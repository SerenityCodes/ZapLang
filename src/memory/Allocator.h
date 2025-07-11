#pragma once

#include "common.h"

enum AllocatorType {
    ARENA,
    STACK,
    POOL
};

typedef struct Chunk {
    Chunk* next;
} Chunk;

typedef struct {
    AllocatorType type;
    void* allocator;
} Allocator;

typedef struct {
    Allocator* allocator;
    Chunk* alloc_ptr;
    u64 chunks_per_block;
    u64 chunk_size;
} PoolAllocator;

Chunk* chunk_allocate_block(PoolAllocator* allocator);

void* pool_allocate(PoolAllocator* allocator);
void pool_deallocate(PoolAllocator* allocator, void* ptr);

typedef struct {
    u8* data;
    u64 current_size;
    u64 capacity;
} StackAllocator;

void* stack_allocate(StackAllocator* allocator, size_t amount);
void* stack_allocate(StackAllocator* allocator, size_t amount, size_t alignment);
void stack_free_bytes(StackAllocator* allocator, size_t bytes_to_free);
void stack_free_to_marker(StackAllocator* allocator, uint64_t* ptr);
void stack_clear(StackAllocator* allocator);

typedef struct {
    StackAllocator allocator;  
} Arena;


void* arena_push(Arena* arena, u64 size);
void* arena_push(Arena* arena, u64 size, u64 alignment);

void arena_clear(Arena* arena);

inline void* allocate_memory(Allocator* allocator, u64 bytes, u64 alignment) {
    void* mem = NULL;
    switch (allocator->type) {
        case ARENA:
            mem = arena_push((Arena*) allocator->allocator, bytes, alignment);
            break;
        case STACK:
            mem = stack_allocate((StackAllocator*) allocator->allocator, bytes, alignment);
            break;
        case POOL:
            PoolAllocator* pool_alloc = (PoolAllocator*) allocator->allocator;
            if (pool_alloc->chunk_size == bytes) {
                mem = pool_allocate(pool_alloc);
            }
            break;
    }
    return mem;
}

inline void* allocate_memory(Allocator* allocator, u64 bytes) {
    return allocate_memory(allocator, bytes, 1);
}
