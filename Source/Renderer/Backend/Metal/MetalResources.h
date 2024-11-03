//
// Created by Adithya Somashekhar on 9/30/24.
//

#pragma once

#include <Core.h>
#include <Metal/MetalInclude.h>
#include <Metal/MetalCppInclude.h>

class MetalTexture
{
public:
    MetalTexture() = default;
    MetalTexture(id <MTLDevice> device, uint32 width, uint32 height, MTLTextureUsage usage, MTLStorageMode storage_mode,
                 bool mipmap, MTLPixelFormat pixel_format);
    id<MTLTexture> texture;
    MTLPixelFormat format;
};
class MetalBuffer
{

public:

    MetalBuffer(id <MTLBuffer> buffer, NS::Range range) : buffer([buffer retain]), range(range)
    {}

    MetalBuffer() : range(NS::Range(0, 0)), buffer(nullptr)
    {}

    ~MetalBuffer()
    {
//        if(buffer)
//        {
//            [buffer release];
//            buffer = nullptr;
//        }
    }

    forceinline uint32 offset() const
    {
        return range.location;
    }

    forceinline uint32 length() const
    {
        return range.length;
    }

    forceinline void* contents() const
    {
        return static_cast<byte*>([buffer contents]) + offset();
    }

    forceinline id <MTLBuffer> get_native_buffer() const
    { return buffer; }

private:
    id <MTLBuffer> buffer;
    NS::Range      range;
};


enum EncodingState : uint8
{
    none,
    render,
    blit,
    compute
};

class MetalCommandBuffer
{
public:

    MetalCommandBuffer(id <MTLCommandBuffer> command_buffer) : command_buffer(command_buffer), render_command_encoder(nil), blit_command_encoder(nil)
    {}

    forceinline void commit() { [command_buffer commit]; }

    id <MTLRenderCommandEncoder>
    render_encoder_with_descriptor(MTLRenderPassDescriptor* render_pass_descriptor);

    id <MTLRenderCommandEncoder> render_encoder();

    forceinline void end_render()
    { if (render_command_encoder != nil) { [render_command_encoder endEncoding]; }}


    forceinline void end_blit()
    { if (blit_command_encoder != nil) { [blit_command_encoder endEncoding]; }}

    id <MTLBlitCommandEncoder> blit_encoder();

    id <MTLCommandBuffer>        command_buffer;
    id <MTLRenderCommandEncoder> render_command_encoder;
    id <MTLBlitCommandEncoder>   blit_command_encoder;
    EncodingState                current_encoding_state;
};

