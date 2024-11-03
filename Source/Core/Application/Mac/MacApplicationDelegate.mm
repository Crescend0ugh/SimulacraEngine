//
// Created by Adithya Somashekhar on 9/12/24.
//

#include "MacApplicationDelegate.h"

@implementation MacApplicationDelegate
- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)theApplication
{
    return YES;
}
@end