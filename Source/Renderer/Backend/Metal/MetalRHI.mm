//
// Created by Adithya Somashekhar on 9/9/24.
//

#include "MetalRHI.h"


id MetalRHI::create_buffer(uint64 size, MTLResourceOptions options)
{
    id <MTLBuffer> buffer;
    return [device newBufferWithLength:size options:options];
}

void MetalRHI::build_buffers()
{
    const size_t positionsDataSize = vertex_count * sizeof( simd::float3 );
    const size_t colorDataSize = vertex_count * sizeof( simd::float3 );

    position_buffer = [device newBufferWithLength:positionsDataSize options:MTLStorageModeManaged];
    color_buffer = [device newBufferWithLength:positionsDataSize options:MTLStorageModeManaged];

    memcpy( position_buffer.contents, positions, positionsDataSize );
    memcpy( color_buffer.contents, colors, colorDataSize );

    [position_buffer didModifyRange:NSMakeRange( 0, position_buffer.length)];
    [color_buffer didModifyRange:NSMakeRange( 0, color_buffer.length)];

}

void MetalRHI::draw_frame(MTKView* view)
{
    NSAutoreleasePool* autorelease_pool = [[NSAutoreleasePool alloc] init];

    id<MTLCommandBuffer> command_buffer = [command_queue commandBuffer];
    MTLRenderPassDescriptor* render_pass_descriptor = [view currentRenderPassDescriptor];
    id<MTLRenderCommandEncoder> encoder = [command_buffer renderCommandEncoderWithDescriptor:render_pass_descriptor];


    [encoder setRenderPipelineState:pipeline_state];
    [encoder setVertexBuffer:position_buffer offset:0 atIndex:0];
    [encoder setVertexBuffer:color_buffer offset:0 atIndex:1];
    [encoder drawPrimitives:MTLPrimitiveTypeTriangle vertexStart:0 vertexCount:3];
    [encoder endEncoding];
    [command_buffer presentDrawable:[view currentDrawable]];
    [command_buffer commit];
    [autorelease_pool release];
}

void MetalRHI::build_shaders()
{
    NSError* error = nullptr;
    id <MTLLibrary> library = [device newLibraryWithFile:@"../../../../../Shaders/metal/triangle.metallib" error:&error];
    if (!library) {
        [NSException raise:@"Failed to read shaders" format:@"%@", [error localizedDescription]];
    }

    MTLRenderPipelineDescriptor* pipeline_descriptor = [[MTLRenderPipelineDescriptor alloc] init];
    pipeline_descriptor.vertexFunction = [library newFunctionWithName:@"vertexFunction"];
    pipeline_descriptor.fragmentFunction = [library newFunctionWithName:@"fragmentFunction"];;
    pipeline_descriptor.colorAttachments[0].pixelFormat = MTLPixelFormat::MTLPixelFormatBGRA8Unorm;
    pipeline_state = [device newRenderPipelineStateWithDescriptor:pipeline_descriptor error:&error];
    if (!pipeline_state) {
        [NSException raise:@"Failed to create pipeline state" format:@"%@", [error localizedDescription]];
    }

    [pipeline_descriptor release];
    shader_library = library;
}

MetalRHI::MetalRHI(id <MTLDevice> device) : device([device retain])
{
    command_queue = [device newCommandQueue];
    build_shaders();
    build_buffers();
}

MetalRHI::~MetalRHI()
{
    [shader_library release];
    [argument_buffer release];
    [pipeline_state release];
    [command_queue release];
    [device release];
}

@implementation MetalManager
- (id)init {
    NSError* error;
    NSRect frame = NSMakeRect(0, 0, 640, 480);
    window = [[NSWindow alloc] initWithContentRect:frame
              styleMask:NSWindowStyleMaskClosable | NSWindowStyleMaskTitled
                                           backing:NSBackingStoreBuffered defer:NO];

    id<MTLDevice> device = MTLCreateSystemDefaultDevice();
    MTKView* view = [[MTKView alloc] initWithFrame:frame device:device];
    [view setDelegate:self];
    [window center];
    [window setContentView:view];
    [window makeKeyAndOrderFront:NSApp];

    metal = new MetalRHI(device);
    return self;
}

- (void)drawInMTKView:(MTKView*)view
{
    metal->draw_frame(view);
}

-(BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)theApplication
{
    return YES;
}


@end



