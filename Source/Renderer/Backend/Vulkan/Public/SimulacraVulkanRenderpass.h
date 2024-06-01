//
// Created by avsom on 5/31/2024.
//

#pragma once

#include "SimulacraVulkan.h"

class render_pass
{

public:




    VkRenderPass handle() const { return render_pass_; }




private:

    VkRenderPass render_pass_;


};