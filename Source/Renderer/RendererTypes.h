//
// Created by Adithya Somashekhar on 10/14/24.
//

#pragma once

#include <Core.h>


enum class CompareFunction
{
    never,
    less,
    equal,
    less_or_equal,
    greater,
    not_equal,
    greater_or_equal,
    always,
};

enum class FrontFace
{
    Clockwise,
    CounterClockwise
};

struct RenderPipelineDescription
{
    bool            enable_depth_write;
    CompareFunction compare_function;
    FrontFace       front_face;
};

