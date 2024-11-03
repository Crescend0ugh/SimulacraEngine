//
// Created by Adithya Somashekhar on 10/9/24.
//

#pragma once

#include <Core.h>
#include "Application/Mac/CocoaWindow.h"
#include <Metal/MetalInclude.h>



@protocol ViewDelegate<NSObject>
        - (void)drawableResize:(CGSize)size;
        - (void)renderToMetalLayer:(nonnull CAMetalLayer*)metalLayer;
@end

@interface MetalView : NSView<CALayerDelegate>
{
    CAMetalLayer* layer;
    id<ViewDelegate> delegate;
}
@end


class MetalWindow
{
    MetalWindow(_Nonnull id<MTLDevice> device)
    {
        layer.device = device;
        layer.framebufferOnly = YES;
        layer.opaque = YES;
        layer.pixelFormat = MTLPixelFormatBGRA8Unorm_sRGB;
        layer.allowsNextDrawableTimeout = YES;
        frame_buffers.reserve(3);
        frame_buffers.resize(3);
    }

    ~MetalWindow()
    {
        layer = nil;
    }

    void acquire_next_image()
    {
        frame = frame + 1 % frame_buffers.size();
        drawable = layer.nextDrawable;
    }

    void present(_Nonnull id<MTLCommandBuffer> command_buffer)
    {

        [command_buffer presentDrawable:drawable];
        [drawable release];
    }

    CAMetalLayer* layer;
    uint32 frame;
    std::vector<uint32> frame_buffers;
    id<CAMetalDrawable> drawable;
};