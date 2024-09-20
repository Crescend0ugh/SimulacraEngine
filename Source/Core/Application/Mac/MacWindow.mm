//
// Created by Adithya Somashekhar on 9/11/24.
//

#include "MacWindow.h"
#import "CocoaWindow.h"


MacWindow::~MacWindow()
{
    [handle close];
}

void MacWindow::initialize(uint32 width, uint32 height)
{
    this->width = width;
    this->height = height;
    NSRect frame = NSMakeRect(300,200, width, height);
    handle = [[CocoaWindow alloc] initWithContentRect:frame styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskResizable | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable  backing:NSBackingStoreBuffered defer:NO];
    handle.contentView.autoresizesSubviews = true;
    [handle setBackgroundColor:[NSColor windowBackgroundColor]];
    [handle makeKeyAndOrderFront:NSApp];
}

void MacWindow::resize()
{
}

void MacWindow::move()
{

}

void MacWindow::minimize()
{

}

void MacWindow::maximize()
{

}

void MacWindow::show_window(bool should_show)
{

}

void* MacWindow::native_handle()
{
    return handle;
}

bool MacWindow::is_open()
{
    return true;
}





