//
// Created by Adithya Somashekhar on 9/16/24.
//

#pragma once


enum BufferUsage
{

};

enum TextureUsage
{

};
struct BufferCreateInfo
{
    size_t      size;
    BufferUsage usage;
};

struct TextureCreateInfo
{
    size_t       size;
    TextureUsage texture_usage;
};


class HardwareInterface
{
    virtual void create_buffer() = 0;

    virtual void release_buffer() = 0;

    virtual void create_texture() = 0;

    virtual void release_texture() = 0;

    virtual void copy_buffer() = 0;

    virtual void copy_image() = 0;

    virtual void copy_buffer_to_image() = 0;

    virtual void copy_image_to_buffer() = 0;

    virtual void create_render_pass() = 0;

    virtual void create_semaphore() = 0;

    virtual void create_fence() = 0;

    virtual void release_fence() = 0;

    virtual void release_semaphore() = 0;
};
