//
// Created by Adithya Somashekhar on 10/9/24.
//

#include "ForwardRenderer.h"
#include "ForwardRendererTypes.h"

ForwardRenderer::ForwardRenderer()
{
    depth_texture =          metal->create_texture(viewport_dimensions.x,
                                                    viewport_dimensions.y,
                                                    MTLTextureUsageRenderTarget,
                                                    MTLStorageModePrivate,
                                                    NO,
                                                    MTLPixelFormatRGBA8Unorm);

    normal_texture =          metal->create_texture(viewport_dimensions.x,
                                                    viewport_dimensions.y,
                                                    MTLTextureUsageRenderTarget,
                                                    MTLStorageModePrivate,
                                                    NO,
                                                    MTLPixelFormatRGBA8Unorm);
}

ForwardRenderer::~ForwardRenderer()
{
}

void ForwardRenderer::draw_frame()
{

}

void ForwardRenderer::build_shaders()
{

}

void ForwardRenderer::update_uniform_buffers()
{

}

void ForwardRenderer::draw_into_window()
{

}

void ForwardRenderer::build_depth_stencil()
{

}

void ForwardRenderer::create_pipelines()
{
    RenderPipelineDescription pipeline_description{};
    pipeline_description.enable_depth_write = true;
    pipeline_description.compare_function   = CompareFunction::less;
    gbuffer_pipeline = metal->create_pipeline(pipeline_description);
}


