//
// Created by Adithya Somashekhar on 9/9/24.
//

#include "MetalRHI.h"
#include <filesystem>

MetalRHI::MetalRHI(id <MTLDevice> device) : device([device retain])
{
    command_queue = [device newCommandQueue];
    build_shaders();
    build_depth_stencil();
    build_buffers();
    semaphore = dispatch_semaphore_create(MetalRHI::max_frames_in_flight);
    build_render_targets();
}

MetalRHI::~MetalRHI()
{
    [shader_library release];
    [index_buffer.get_native_buffer() release];
    [command_queue release];
    [device release];
}

MetalBuffer MetalRHI::create_buffer(uint64 size, MTLResourceOptions options)
{
    id <MTLBuffer> buffer = [device newBufferWithLength:size options:options];
    return {[buffer retain], NS::Range(0, buffer.length)};
}

void MetalRHI::build_buffers()
{
    const size_t vertex_buffer_size = sizeof(verts);
    const size_t index_buffer_size  = sizeof(indices);

    MetalBuffer vertex_staging_buffer = create_buffer(vertex_buffer_size, MTLResourceStorageModeShared);
    MetalBuffer index_staging_buffer = create_buffer(index_buffer_size, MTLResourceStorageModeShared);

    memcpy(vertex_staging_buffer.contents(), verts, vertex_buffer_size);
    memcpy(index_staging_buffer.contents(), indices, index_buffer_size);

    MetalCommandBuffer copy_command_buffer = create_command_buffer();


    vertex_buffer = create_buffer(vertex_buffer_size, MTLResourceStorageModePrivate);
    index_buffer  = create_buffer(index_buffer_size, MTLResourceStorageModePrivate);
    copy_buffer(vertex_staging_buffer, vertex_buffer, copy_command_buffer, vertex_staging_buffer.length());
    copy_buffer(index_staging_buffer, index_buffer, copy_command_buffer, index_staging_buffer.length());


    const size_t     instance_data_size = max_frames_in_flight * instance_count * sizeof(InstanceData);
    for (MetalBuffer &instance_buffer: instance_buffers) {
        instance_buffer = create_buffer(instance_data_size, MTLResourceStorageModeManaged);
    }

    const size_t     camera_data_size = max_frames_in_flight * sizeof(CameraData);
    for (MetalBuffer &camera_buffer: camera_data_buffers) {
        camera_buffer = create_buffer(camera_data_size, MTLResourceStorageModeShared);
    }

    copy_command_buffer.commit();

}

void MetalRHI::draw_frame(MTKView* view)
{
    NSAutoreleasePool* autorelease_pool = [[NSAutoreleasePool alloc] init];

    frame = (frame + 1) % MetalRHI::max_frames_in_flight;

    MetalCommandBuffer command_buffer = create_command_buffer();
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    MetalRHI* pointer = this;
    [command_buffer.command_buffer addCompletedHandler:^void(id <MTLCommandBuffer> pCmd) {
        dispatch_semaphore_signal(pointer->semaphore);
    }];

    update_uniform_buffers();

    MTLRenderPassDescriptor* render_pass_descriptor = [view currentRenderPassDescriptor];
    command_buffer.render_encoder_with_descriptor(render_pass_descriptor);
    bind_pipeline(pipeline, command_buffer);

    [command_buffer.render_command_encoder setVertexBuffer:vertex_buffer.get_native_buffer() offset:0 atIndex:0];
    [command_buffer.render_command_encoder setVertexBuffer:instance_buffers[frame].get_native_buffer() offset:0 atIndex:1];
    [command_buffer.render_command_encoder setVertexBuffer:camera_data_buffers[frame].get_native_buffer() offset:0 atIndex:2];
    [command_buffer.render_command_encoder setCullMode:MTLCullModeBack];
    [command_buffer.render_command_encoder setFrontFacingWinding:MTLWindingCounterClockwise];


    [command_buffer.render_command_encoder drawIndexedPrimitives:MTLPrimitiveTypeTriangle indexCount:6
                         indexType:MTLIndexTypeUInt16
                       indexBuffer:index_buffer.get_native_buffer()
                 indexBufferOffset:0
                     instanceCount:instance_count
                        baseVertex:0
                      baseInstance:0];
    [command_buffer.render_encoder() endEncoding];
    [command_buffer.command_buffer presentDrawable:[view currentDrawable]];
    command_buffer.commit();
    [autorelease_pool release];
}

void MetalRHI::build_shaders()
{

    RenderPipelineDescription description{};
    description.front_face = FrontFace::CounterClockwise;
    description.compare_function = CompareFunction::less;
    description.enable_depth_write = true;
    pipeline = create_pipeline(description);

}


void MetalRHI::copy_buffer(const MetalBuffer &src, MetalBuffer &destination, MetalCommandBuffer &command_buffer,
                           size_t size)
{
    id<MTLBlitCommandEncoder> blit_command_encoder = command_buffer.blit_encoder();
    [blit_command_encoder copyFromBuffer:src.get_native_buffer()
                             sourceOffset:0
                                 toBuffer:destination.get_native_buffer()
                        destinationOffset:0
                                     size:size];
    [blit_command_encoder endEncoding];

}

void MetalRHI::build_depth_stencil()
{

}

void MetalRHI::update_uniform_buffers()
{
    //Get current frame instance buffer
    MetalBuffer &current_frame_instance_buffer = instance_buffers[frame];
    angle += 0.01f;

    const float scl = 0.1f;
    InstanceData* pInstanceData = reinterpret_cast<InstanceData*>( current_frame_instance_buffer.contents());

    simd::float3 objectPosition = {0.f, 0.f, -5.f};

    // Update instance positions:

    simd::float4x4 rt            = math::makeTranslate(objectPosition);
    simd::float4x4 rr            = math::makeYRotate(-angle);
    simd::float4x4 rtInv         = math::makeTranslate({-objectPosition.x, -objectPosition.y, -objectPosition.z});
    simd::float4x4 fullObjectRot = rt * rr * rtInv;

    for (size_t i = 0; i < instance_count; ++i) {
        float iDivNumInstances = i / (float) instance_count;
        float xoff             = (iDivNumInstances * 2.0f - 1.0f) + (1.f / instance_count);
        float yoff             = sin((iDivNumInstances + angle) * 2.0f * M_PI);

        // Use the tiny math library to apply a 3D transformation to the instance.
        simd::float4x4 scale     = math::makeScale((simd::float3) {scl, scl, scl});
        simd::float4x4 zrot      = math::makeZRotate(angle);
        simd::float4x4 yrot      = math::makeYRotate(angle);
        simd::float4x4 translate = math::makeTranslate(math::add(objectPosition, {xoff, yoff, 0.f}));

        pInstanceData[i].instance_transform = fullObjectRot * translate * yrot * zrot * scale;

        float r = iDivNumInstances;
        float g = 1.0f - r;
        float b = sinf(M_PI * 2.0f * iDivNumInstances);
        pInstanceData[i].instance_color = (simd::float3) {r, g, b};
    }
    [current_frame_instance_buffer.get_native_buffer() didModifyRange:NSMakeRange(0,
                                                                                  current_frame_instance_buffer.length())];
    MetalBuffer &current_frame_camera_data_buffer = camera_data_buffers[frame];
    CameraData  * camera_data                     = reinterpret_cast< CameraData*>( current_frame_camera_data_buffer.contents());
    camera_data->view  = math::makePerspective(45.f * M_PI / 180.f, 2.f, 0.03f, 500.0f);
    camera_data->world = math::makeIdentity();

}

MetalRenderPipeline MetalRHI::create_pipeline(const RenderPipelineDescription &pipeline_description)
{
    return {device, pipeline_description};
}

void MetalRHI::release_pipeline(MetalRenderPipeline &pipeline)
{
    if (pipeline.pipeline_state != nil) {
        [pipeline.pipeline_state release];
    }

    if (pipeline.depth_stencil_state != nil) {
        [pipeline.depth_stencil_state release];
    }
}

void MetalRHI::bind_pipeline(const MetalRenderPipeline &pipeline, MetalCommandBuffer &command_buffer)
{
    if (pipeline.depth_stencil_state != nil) {
        [command_buffer.render_encoder()
                setDepthStencilState:
                        pipeline.depth_stencil_state];
    }

    if(pipeline.pipeline_state != nil)
    {
        [command_buffer.render_encoder() setRenderPipelineState:pipeline.pipeline_state];
    }

}

MetalCommandBuffer MetalRHI::create_command_buffer()
{
    return {[command_queue commandBuffer]};
}

MetalTexture MetalRHI::create_texture(uint32 width, uint32 height, MTLTextureUsage usage, MTLStorageMode storage_mode,
                                      bool mipmap, MTLPixelFormat pixel_format)
{
    return {device, width, height, usage, storage_mode, mipmap, pixel_format};
}

void MetalRHI::build_render_targets()
{
    viewport_dimensions = {500, 500};
    albedo_specular_texture = create_texture(viewport_dimensions.x,
                                                    viewport_dimensions.y,
                                                    MTLTextureUsageRenderTarget,
                                                    MTLStorageModePrivate,
                                                    NO,
                                                    MTLPixelFormatRGBA8Unorm_sRGB);

    depth_texture =          create_texture(viewport_dimensions.x,
                                                   viewport_dimensions.y,
                                                   MTLTextureUsageRenderTarget,
                                                   MTLStorageModePrivate,
                                                   NO,
                                                   MTLPixelFormatRGBA8Unorm);

    normal_texture =         create_texture(viewport_dimensions.x,
                                                    viewport_dimensions.y,
                                                    MTLTextureUsageRenderTarget,
                                                    MTLStorageModePrivate,
                                                    NO,
                                                    MTLPixelFormatRGBA8Unorm);
}






