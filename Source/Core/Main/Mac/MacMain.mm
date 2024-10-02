//
// Created by Adithya Somashekhar on 9/7/24.
//



#include "Application/Mac/MacWindow.h"
#include "Metal/MetalRHI.h"
#include "VulkanRHI.h"
#include <MacPlatformInclude.h>

int main(int argc, const char * argv[]) {
    [NSApplication sharedApplication];
    MetalManager* manager = [[MetalManager alloc] init];
    [NSApp setDelegate:manager];
    [NSApp run];
    return 0;
}