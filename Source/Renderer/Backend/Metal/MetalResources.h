//
// Created by Adithya Somashekhar on 9/30/24.
//

#pragma once

#include <Metal/MetalInclude.h>
#include <Metal/MetalCppInclude.h>

class MetalBuffer
{

public:

    MetalBuffer(id<MTLBuffer> buffer, NS::Range range) : buffer([buffer retain]), range(range) {}

    MetalBuffer() : range(NS::Range(0,0)), buffer(nullptr) {}

    ~MetalBuffer()
    {
        if(buffer)
        {
            [buffer release];
        }
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

private:
    id<MTLBuffer> buffer;
    NS::Range range;
};