//
// Created by Adithya Somashekhar on 10/9/24.
//

#pragma once
#include <Metal/MetalRHI.h>
#include <Core.h>



class ForwardRenderer
{

public:

    ForwardRenderer();
    ~ForwardRenderer();

    void draw_frame();

private:


    void build_depth_stencil();
    void build_shaders();
    void update_uniform_buffers();
    void draw_into_window();
    void create_pipelines();

private:

    /**TODO there needs to be some way to send arbitrary meshes and textures through these "pipelines" rather than
     declaring the resources in the renderer itself **/
    const static uint32 instance_count = 32;
    const static uint32 max_frames_in_flight = 3;



    //TODO change these to be generic api resources

    MetalTexture albedo_specular_texture;
    MetalTexture normal_texture;
    MetalTexture depth_texture;
    Vector2i viewport_dimensions;

    MetalBuffer uniform_buffer;
    MetalBuffer index_buffer;
    MetalBuffer vertex_buffer;
    MetalBuffer instance_buffer[max_frames_in_flight];
    MetalBuffer camera_data_buffers[max_frames_in_flight];



    MetalRenderPipeline gbuffer_pipeline;

    //TODO change this to be an arbitrary api ie. Metal, DX12, Vulkan
    MetalRHI* metal;

};

using Normal             = Vector3f;
using Position           = Vector3f;
using TextureCoordinates = Vector2f;



