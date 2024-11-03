
#pragma once

#include <Core.h>
#include "HardwareInterface.h"
#include <Metal/MetalCppInclude.h>
#include <Metal/MetalInclude.h>
#include <Application/Mac/MacWindow.h>
#include <Metal/MetalShaderTypes.h>
#include <Metal/MetalMath.h>
#include <Metal/MetalResources.h>
//#include <Metal/MetalWindow.h>
#include <Math/Matrix.h>
#include <Metal/MetalPipeline.h>


struct InstanceData
{
    simd::float4x4 instance_transform;
    simd::float3   instance_color;
};

struct CameraData
{
    simd::float4x4 view;
    simd::float4x4 world;
};

//TODO change this to an vector/array and move it into the class as static member to support creation of multiple viwe

class MetalRHI
{


public:

    explicit MetalRHI(_Nonnull id <MTLDevice> device);

    ~MetalRHI();

    MetalCommandBuffer create_command_buffer();

    MetalBuffer create_buffer(uint64 size, MTLResourceOptions options);

    void free_buffer(MetalBuffer &buffer);

    void draw_frame(MTKView* view);

    MetalTexture create_texture(uint32 width, uint32 height, MTLTextureUsage usage, MTLStorageMode storage_mode,
                                bool mipmap, MTLPixelFormat pixel_format);

    void free_texture(MetalTexture &texture)
    {
        [texture.texture release];
        texture = {};
    };

    void copy_buffer(const MetalBuffer &src, MetalBuffer &destination, MetalCommandBuffer &command_buffer,
                     size_t size);

    void copy_buffer_to_image(const MetalBuffer &src, MetalTexture &destination, MetalCommandBuffer &command_buffer);

    void copy_image_to_buffer(const MetalTexture &src, MetalBuffer &destination, MetalCommandBuffer &command_buffer);

    MetalRenderPipeline create_pipeline(const RenderPipelineDescription &pipeline_description);

    void release_pipeline(MetalRenderPipeline &pipeline);

//    void create_render_pass();
    void bind_pipeline(const MetalRenderPipeline &pipeline, MetalCommandBuffer &command_buffer);
//    void create_semaphore();
//    void free_semphore();
//    void create_fence();
//    void free_fence();
//    void wait_fence();

private:

    void build_depth_stencil();

    void build_shaders();

    void build_buffers();

    void update_uniform_buffers();

    void build_render_targets();


private:


    const static uint32 max_frames_in_flight = 3;
    uint32              frame                = 0;
    float               angle;

    id <MTLDevice>            device;
    id <MTLCommandQueue>      command_queue{};
    MetalBuffer               vertex_buffer;
    MetalBuffer               index_buffer;
    MetalBuffer               instance_buffers[max_frames_in_flight];
    MetalBuffer               camera_data_buffers[max_frames_in_flight];
    MetalRenderPipeline       pipeline;
    id <MTLDepthStencilState> depth_stencil_state;
    id <MTLLibrary>           shader_library{};
    dispatch_semaphore_t      semaphore;


    MetalTexture albedo_specular_texture;
    MetalTexture normal_texture;
    MetalTexture depth_texture;
    Vector2i viewport_dimensions;

};


constexpr static uint32 instance_count = 32;

const float size = 0.9;

const static simd::float3 verts[]   = {
        {-size, -size, +size},
        {+size, -size, +size},
        {+size, +size, +size},
        {-size, +size, +size},
        {-size, -size, -size},
        {-size, +size, -size},
        {+size, +size, -size},
        {+size, -size, -size}
};
const static uint16       indices[] = {
        0, 1, 2, /*front*/
        2, 3, 0,

        1, 7, 6, /* right */
        6, 2, 1,

        7, 4, 5, /* back */
        5, 6, 7,

        4, 0, 3, /* left */
        3, 5, 4,

        3, 2, 6, /* top */
        6, 5, 3,

        4, 7, 1, /* bottom */
        1, 0, 4
};

