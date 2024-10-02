#include <Core.h>
#include "HardwareInterface.h"
#include <Metal/MetalCppInclude.h>
#include <Metal/MetalInclude.h>
#include <Application/Mac/MacWindow.h>
#include <Metal/MetalShaderTypes.h>
#include <simd/simd.h>
#include <Metal/MetalResources.h>


class MetalRHI
{


public:

    explicit MetalRHI(id<MTLDevice> device);
    ~MetalRHI();
    id _Nullable create_buffer(uint64 size, MTLResourceOptions options);
    void draw_frame(MTKView* view);
    void build_buffers();
    void build_shaders();

private:
    id<MTLDevice> device;
    id<MTLCommandQueue> command_queue{};
    id<MTLRenderPipelineState> pipeline_state{};
    id<MTLBuffer> position_buffer{};
    id<MTLBuffer> color_buffer{};
    id<MTLBuffer> argument_buffer{};
    id<MTLLibrary> shader_library{};
};

@interface MetalManager : NSObject<NSApplicationDelegate, MTKViewDelegate>
{
    NSWindow* window;
    MetalRHI* metal;
};
@end


const static uint32       vertex_count = 3;
const static simd::float3 positions[]  = {{-0.5f, -0.5f, 0.0f},
                                          {0.5f,  -0.5f, 0.0f},
                                          {0.0f,  0.5f,  0.0f}};
const static simd::float3 colors[]     = {{1, 0, 0},
                                          {0, 1, 0},
                                          {0, 0, 1}};

