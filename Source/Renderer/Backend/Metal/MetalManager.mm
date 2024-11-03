//
// Created by Adithya Somashekhar on 10/11/24.
//

#include "MetalManager.h"

@implementation MetalManager
- (id)init {
NSError* error;
NSRect frame = NSMakeRect(0, 0, 1024, 512);
                window = [[NSWindow alloc] initWithContentRect:frame
        styleMask:NSWindowStyleMaskClosable | NSWindowStyleMaskTitled
        backing:NSBackingStoreBuffered defer:NO];

id <MTLDevice> device = MTLCreateSystemDefaultDevice();
MTKView* view = [[MTKView alloc] initWithFrame:frame device:device];
[view setDelegate:self];
[view setDepthStencilPixelFormat:MTLPixelFormatDepth32Float];
[view setClearDepth:1.0];
[window center];
[window setContentView:view];
[window makeKeyAndOrderFront:NSApp];

metal = new MetalRHI(device);
return self;
}

- (void)drawInMTKView:(MTKView*)view {
    metal->draw_frame(view);
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)theApplication {
return YES;

}
@end
