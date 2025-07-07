#pragma once

#include "common.h"

typedef struct {
    u8* data;
    u64 current_size;
    u64 capacity;
} StackAllocator;

[[nodiscard]] void* stack_allocate(StackAllocator* allocator, size_t amount);
void* stack_allocate(StackAllocator* allocator, size_t amount, size_t alignment);
void stack_free_bytes(StackAllocator* allocator, size_t bytes_to_free);
void stack_free_to_marker(StackAllocator* allocator, uint64_t* ptr);
void stack_clear(StackAllocator* allocator);
