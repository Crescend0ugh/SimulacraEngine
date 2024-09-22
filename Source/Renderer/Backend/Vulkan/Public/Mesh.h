//
// Created by avsom on 9/1/2024.
//

#pragma once

#include "Core.h"
#include "VulkanResources.h"

struct Vertex
{
    Vector3f position_;
    Vector3f color_;
    Vector2f texture_coordinates_;
    Vector3f normal;

    static VkVertexInputBindingDescription get_binding_description()
    {
        VkVertexInputBindingDescription binding_description{};
        binding_description.binding = 0;
        binding_description.stride = sizeof(Vertex);
        binding_description.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
        return binding_description;
    }

    static std::vector<VkVertexInputAttributeDescription> get_attribute_descriptions()
    {
        std::vector<VkVertexInputAttributeDescription> attribute_descriptions{};
        attribute_descriptions.reserve(4);
        attribute_descriptions.resize(4);
        attribute_descriptions[0].binding = 0;
        attribute_descriptions[0].location = 0;
        attribute_descriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
        attribute_descriptions[0].offset = offsetof(Vertex, position_);

        attribute_descriptions[3].binding = 0;
        attribute_descriptions[3].location = 1;
        attribute_descriptions[3].format = VK_FORMAT_R32G32B32_SFLOAT;
        attribute_descriptions[3].offset = offsetof(Vertex, normal);

        attribute_descriptions[1].binding = 0;
        attribute_descriptions[1].location = 2;
        attribute_descriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
        attribute_descriptions[1].offset = offsetof(Vertex, color_);

        attribute_descriptions[2].binding = 0;
        attribute_descriptions[2].location = 3;
        attribute_descriptions[2].format = VK_FORMAT_R32G32_SFLOAT;
        attribute_descriptions[2].offset = offsetof(Vertex, texture_coordinates_);

        return attribute_descriptions;
    }

};

