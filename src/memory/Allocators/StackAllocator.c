#include "StackAllocator.h"
#include <cstddef>
#include <cstdint>
#include <cstdlib>

#include "logger/Logger.h"


void* stack_allocate(StackAllocator* allocator, u64 amount) {
    if (amount == 0) {
        return NULL;
    }
    u8* current_pos = allocator->data + allocator->current_size;
    if (allocator->current_size + amount > allocator->capacity) {
        return NULL;
    }
    allocator->current_size += amount;
    return current_pos;
}

[[nodiscard]] void* stack_allocate(StackAllocator* allocator, u64 amount, u64 alignment) {
    if (amount == 0 || amount > allocator->capacity) {
        return NULL;
    }
    uintptr_t current_pos = (uintptr_t) allocator->data + allocator->current_size;
    uintptr_t aligned_pos = (current_pos + (alignment - 1)) & ~(alignment - 1);
    size_t padding = aligned_pos - current_pos;
    size_t new_size = allocator->current_size + padding;
    if (new_size > allocator->capacity) {
        // Introduce a linked list type setup with stack allocators
        return NULL;
    }
    allocator->current_size = new_size;
    return reinterpret_cast<void*>(aligned_pos);
}

void stack_free_bytes(StackAllocator* allocator, size_t bytes_to_free) {
    if (bytes_to_free > allocator->current_size) {
        ZAP_LOG_ERROR("Cannot free {} bytes from stack allocator. Bigger than the actual size. Wiping stack allocator.", bytes_to_free)
        allocator->current_size = 0;
    } else {
        allocator->current_size -= bytes_to_free;
    }
}

void stack_free_to_marker(StackAllocator* allocator, uint64_t* ptr) {
    size_t byte_difference = (uintptr_t) ptr - (uintptr_t) allocator->data;
    allocator->current_size = byte_difference;
}

void stack_clear(StackAllocator* allocator) {
    allocator->current_size = 0;
}
