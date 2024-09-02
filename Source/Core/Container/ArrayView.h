//
// Created by avsom on 8/30/2024.
//

#pragma once

#include "Core.h"

template<typename T>
class span {
    T* ptr_;
    std::size_t len_;

public:

    span() noexcept : ptr_(nullptr), len_(0)
    {}

    span(T* ptr, std::size_t len) noexcept
            : ptr_{ptr}, len_{len}
    {}

    span(const std::initializer_list<T> initializer_list) noexcept
            : ptr_{initializer_list.begin()}, len_{initializer_list.size()}
    {}

    T& operator[](int i) noexcept {
        return *ptr_[i];
    }

    T const& operator[](int i) const noexcept {
        return *ptr_[i];
    }

    std::size_t size() const noexcept {
        return len_;
    }

    T* begin() noexcept {
        return ptr_;
    }

    T* end() noexcept {
        return ptr_ + len_;
    }
};