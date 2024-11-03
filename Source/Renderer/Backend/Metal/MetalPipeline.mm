#include <Metal/MetalPipeline.h>

MetalRenderPipeline::MetalRenderPipeline(id<MTLDevice> device, const RenderPipelineDescription &pipeline_description)
{
    MTLRenderPipelineDescriptor* render_pipeline_descriptor;

    if (pipeline_description.enable_depth_write)
    {
        MTLDepthStencilDescriptor* depth_stencil_descriptor = [[MTLDepthStencilDescriptor alloc] init];
        [depth_stencil_descriptor setDepthWriteEnabled:YES];
        [depth_stencil_descriptor setDepthCompareFunction:
                convert_to_metal_compare(pipeline_description.compare_function)];
        depth_stencil_state = [device newDepthStencilStateWithDescriptor:depth_stencil_descriptor];
        [depth_stencil_descriptor release];
    }

    NSError * error  = nullptr;
    NSString* source = [NSString stringWithContentsOfFile:@"/Users/adithyasomashekhar/CLionProjects/SimulacraEngine/Shaders/ForwardRendering/metal/triangle.metal" encoding:NSUTF8StringEncoding error:&error];
    id <MTLLibrary> library = [device newLibraryWithSource:source options:nil error:&error];
    if (!library) {
        [NSException raise:@"Failed to read shaders" format:@"%@", [error localizedDescription]];
    }

    MTLRenderPipelineDescriptor* pipeline_descriptor = [[MTLRenderPipelineDescriptor alloc] init];
    id<MTLFunction> vert_function = [library newFunctionWithName:@"vertexFunction"];
    id<MTLFunction> frag_function = [library newFunctionWithName:@"fragmentFunction"];
    pipeline_descriptor.vertexFunction   = vert_function;
    pipeline_descriptor.fragmentFunction = frag_function;
    pipeline_descriptor.inputPrimitiveTopology = MTLPrimitiveTopologyClassTriangle;
    pipeline_descriptor.colorAttachments[0].pixelFormat = MTLPixelFormat::MTLPixelFormatBGRA8Unorm;
    pipeline_descriptor.depthAttachmentPixelFormat = MTLPixelFormatDepth32Float;
    pipeline_state = [device newRenderPipelineStateWithDescriptor:pipeline_descriptor error:&error];
    if (!pipeline_state) {
        [NSException raise:@"Failed to create pipeline state" format:@"%@", [error localizedDescription]];
    }

    [pipeline_descriptor release];
    [library release];
    [vert_function release];
    [frag_function release];

}