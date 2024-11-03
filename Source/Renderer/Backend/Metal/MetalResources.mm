#include <Metal/MetalResources.h>

id <MTLRenderCommandEncoder>
MetalCommandBuffer::render_encoder_with_descriptor(MTLRenderPassDescriptor* render_pass_descriptor)
{
    switch (current_encoding_state) {

        case none:
            break;
        case render:
            end_render();
            break;
        case blit:
            [blit_command_encoder endEncoding];
            break;
        case compute:
            break;
    }

    current_encoding_state = render;
    render_command_encoder = [command_buffer renderCommandEncoderWithDescriptor:render_pass_descriptor];
    return render_command_encoder;
}

id <MTLRenderCommandEncoder> MetalCommandBuffer::render_encoder()
{
    switch (current_encoding_state) {

        case none:
            break;
        case render:
            break;
        case blit:
            [blit_command_encoder endEncoding];
            break;
        case compute:
            break;
    }

    current_encoding_state = render;
    return render_command_encoder;
}

id <MTLBlitCommandEncoder> MetalCommandBuffer::blit_encoder()
{

    blit_command_encoder = [command_buffer blitCommandEncoder];

    current_encoding_state = blit;
    return blit_command_encoder;
}

MetalTexture::MetalTexture(id <MTLDevice> device, uint32 width, uint32 height, MTLTextureUsage usage,
                           MTLStorageMode storage_mode,
                           bool mipmap, MTLPixelFormat pixel_format) : format(
        pixel_format)
{
    MTLTextureDescriptor* texture_descriptor = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:pixel_format
                                                                                                  width:width
                                                                                                 height:height
                                                                                              mipmapped:mipmap];
    texture_descriptor.usage       = usage;
    texture_descriptor.storageMode = storage_mode;
    texture_descriptor.textureType = MTLTextureType2D;
    texture_descriptor.pixelFormat = pixel_format;
    texture = [device newTextureWithDescriptor:texture_descriptor];
}
