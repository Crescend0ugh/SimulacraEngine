//
// Created by Adithya Somashekhar on 10/11/24.
//

#pragma once

#include <Core.h>
#include <Metal/MetalInclude.h>
#import "ForwardRenderer.h"
#include "MetalRHI.h"

@interface MetalManager : NSObject <NSApplicationDelegate, MTKViewDelegate>
{
    NSWindow* window;
    MetalRHI* metal;
};
@end