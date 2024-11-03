//
// Created by Adithya Somashekhar on 10/14/24.
//

#include <Core.h>
#include <Metal/MetalInclude.h>
#include <RendererTypes.h>

constexpr MTLCompareFunction convert_to_metal_compare(CompareFunction compare_function)
{
    switch (compare_function) {
        case CompareFunction::less:
            return MTLCompareFunctionLess;
            break;
        case CompareFunction::never:
            return MTLCompareFunctionNever;
            break;
        case CompareFunction::equal:
            return MTLCompareFunctionEqual;
            break;
        case CompareFunction::less_or_equal:
            return MTLCompareFunctionLessEqual;
            break;
        case CompareFunction::greater:
            return MTLCompareFunctionGreater;
            break;
        case CompareFunction::not_equal:
            return MTLCompareFunctionNotEqual;
            break;
        case CompareFunction::greater_or_equal:
            return MTLCompareFunctionGreaterEqual;
            break;
        case CompareFunction::always:
            return MTLCompareFunctionAlways;
            break;
    }
}




struct MetalRenderPipeline
{
    MetalRenderPipeline() = default;
    MetalRenderPipeline(id<MTLDevice> device, const RenderPipelineDescription& pipeline_description);
    id<MTLRenderPipelineState> pipeline_state;
    id<MTLDepthStencilState>   depth_stencil_state;
};
