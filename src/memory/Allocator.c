#include "Allocator.h"

Chunk* chunk_allocate_block(PoolAllocator* allocator) {
    u64 block_size = allocator->chunks_per_block * allocator->chunk_size;
    Chunk* block_begin = (Chunk*) allocate_memory(allocator->allocator, block_size);

    Chunk* begin = block_begin;
    for (u64 i = 0; i < allocator->chunks_per_block; i++) {
        begin->next = (Chunk*)((u8*)begin + allocator->chunk_size);
        begin = begin->next;
    }
    begin->next = nullptr;
    return block_begin;
}

void* pool_allocate(PoolAllocator* allocator) {
    if (allocator->alloc_ptr == NULL) {
        allocator->alloc_ptr = chunk_allocate_block(allocator);
    }
    Chunk* free_chunk = allocator->alloc_ptr;
    allocator->alloc_ptr = allocator->alloc_ptr->next;
    return free_chunk;
}

void pool_deallocate(PoolAllocator* allocator, void* ptr) {
    if (ptr == NULL) {
        return;
    }
    Chunk* to_be_freed = (Chunk*) ptr;
    to_be_freed->next = allocator->alloc_ptr;
    allocator->alloc_ptr = to_be_freed;
}


void* stack_allocate(StackAllocator* allocator, u64 amount) {
    ZAP_ASSERT(amount != 0, "Amount given to the stack allocator is zero. Exiting...")
    u8* current_pos = allocator->data + allocator->current_size;
    if (allocator->current_size + amount > allocator->capacity) {
        return NULL;
    }
    allocator->current_size += amount;
    return current_pos;
}

void* stack_allocate(StackAllocator* allocator, u64 amount, u64 alignment) {
    if (amount == 0 || amount > allocator->capacity) {
        return NULL;
    }
    uintptr_t current_pos = (uintptr_t) allocator->data + allocator->current_size;
    uintptr_t aligned_pos = (current_pos + (alignment - 1)) & ~(alignment - 1);
    u64 padding = aligned_pos - current_pos;
    u64 new_size = allocator->current_size + padding;
    if (new_size > allocator->capacity) {
        // Introduce a linked list type setup with stack allocators
        return NULL;
    }
    allocator->current_size = new_size;
    return (void*) aligned_pos;
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


void* arena_push(Arena* arena, u64 size) {
    return stack_allocate(&arena->allocator, size);
}

void* arena_push(Arena* arena, u64 size, u64 alignment) {
    return stack_allocate(&arena->allocator, size, alignment);
}

void arena_clear(Arena* arena) {
    stack_clear(&arena->allocator);
}
