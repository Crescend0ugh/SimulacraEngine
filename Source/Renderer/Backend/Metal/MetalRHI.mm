//
// Created by Adithya Somashekhar on 9/9/24.
//

#include "MetalRHI.h"


MetalRHI::MetalRHI()
{
    device = MTLCreateSystemDefaultDevice();
    metal_layer = [CAMetalLayer layer];
    metal_layer.device = (__bridge id <MTLDevice>) device;
    metal_layer.pixelFormat = MTLPixelFormatBGRA8Unorm;
    window = MacWindow();
    window.initialize(800, 450);
    NSWindow* cocoa_handle = static_cast<NSWindow*>(window.native_handle());
    cocoa_handle.contentView.layer = metal_layer;
    cocoa_handle.contentView.wantsLayer = YES;
    test_create_triangle();
    test_create_default_library();

}

MetalRHI::~MetalRHI()
{
    [device release];
}

void MetalRHI::create_buffer()
{
    std::cout << "Lol";
}

void MetalRHI::release_buffer()
{

}

void MetalRHI::create_texture()
{

}

void MetalRHI::release_texture()
{

}

void MetalRHI::copy_buffer()
{

}

void MetalRHI::copy_image()
{

}

void MetalRHI::copy_buffer_to_image()
{

}

void MetalRHI::copy_image_to_buffer()
{

}

void MetalRHI::create_render_pass()
{

}

void MetalRHI::create_semaphore()
{

}

void MetalRHI::create_fence()
{

}

void MetalRHI::release_fence()
{

}

void MetalRHI::release_semaphore()
{

}

void MetalRHI::test_create_triangle()
{
    simd::float3 vertices[] =
            {
                    {-0.5f, -0.5f, 0.0f},
                    {0.5f,  -0.5f, 0.0f},
                    {0.0f,  0.5f,  0.0f}
            };
    triangle_buffer = [device newBufferWithBytes:&vertices length:sizeof(vertices) options:MTLResourceStorageModeShared];
}

void MetalRHI::test_create_default_library()
{
    NSError *libraryError = NULL;

    id <MTLLibrary> myLibrary = [device newLibraryWithFile:@"../../../../../Shaders/metal/triangle.metallib" error:&libraryError];
    if (!myLibrary) {
        NSLog(@"Library error: %@", libraryError);
    }


}

void MetalRHI::test_create_command_queue()
{
    command_queue = [device newCommandQueue];
}

void MetalRHI::test_create_render_pipeline()
{
    id<MTLFunction> vertex_shader = [default_metal_library newFunctionWithName:@"vertexShader"];
    id<MTLFunction> fragment_shader = [default_metal_library newFunctionWithName:@"fragmentShader"];
    assert(vertex_shader);
    assert(fragment_shader);
    MTLRenderPipelineDescriptor* render_pipeline_descriptor = [[MTLRenderPipelineDescriptor alloc] init];
    [render_pipeline_descriptor setLabel:@"Triangle Rendering Pipeline"];
    [render_pipeline_descriptor setVertexFunction:vertex_shader];
    [render_pipeline_descriptor setFragmentFunction:fragment_shader];
    assert(render_pipeline_descriptor);
    MTLPixelFormat pixel_format = metal_layer.pixelFormat;
    render_pipeline_descriptor.colorAttachments[0].pixelFormat = pixel_format;
    NSError* error;
    render_pipeline  = [device newRenderPipelineStateWithDescriptor:render_pipeline_descriptor error:&error];
    [render_pipeline_descriptor release];
}

void MetalRHI::encode_render_command()
{

}

void MetalRHI::send_render_command()
{

}

void MetalRHI::draw()
{

}

void MetalRHI::draw_primitives()
{
    e
}

void MetalRHI::draw_primitives_indexed()
{

}

void MetalRHI::draw_primitives_indirect()
{

}

void MetalRHI::draw_primitives_indexed_indirect()
{

}
