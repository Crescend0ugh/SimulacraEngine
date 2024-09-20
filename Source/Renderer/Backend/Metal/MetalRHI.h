#include <Core.h>
#include <Foundation/Foundation.h>
#include <Metal/Metal.h>
#include "HardwareInterface.h"
#include <Application/Mac/MacWindow.h>
#include <QuartzCore/QuartzCore.h>
#include <simd/simd.h>

class MetalRHI : public HardwareInterface
{

public:

    MetalRHI();

    ~MetalRHI();

    virtual void draw_primitives();
    
    virtual void draw_primitives_indexed();

    virtual void draw_primitives_indirect();

    virtual void draw_primitives_indexed_indirect();

    virtual void create_buffer();

    virtual void release_buffer();

    virtual void create_texture();

    virtual void release_texture();

    virtual void copy_buffer();

    virtual void copy_image();

    virtual void copy_buffer_to_image();

    virtual void copy_image_to_buffer();

    virtual void create_render_pass();

    virtual void create_semaphore();

    virtual void create_fence();

    virtual void release_fence();

    virtual void release_semaphore();

private:

    void test_create_triangle();
    void test_create_default_library();
    void test_create_command_queue();
    void test_create_render_pipeline();
    void encode_render_command();
    void send_render_command();
    void draw();




    id<MTLDevice> device;
    CAMetalLayer* metal_layer;
    id<CAMetalDrawable> metal_drawable;
    id<MTLLibrary> default_metal_library;
    id<MTLCommandQueue> command_queue;
    id<MTLCommandBuffer> command_buffer;
    id<MTLRenderPipelineState> render_pipeline;
    id<MTLBuffer> triangle_buffer;
    MacWindow window;

};