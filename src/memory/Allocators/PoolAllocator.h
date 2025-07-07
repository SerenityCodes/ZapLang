#pragma once

#include "common.h"

typedef struct chunk {
    chunk* next;
} Chunk;

typedef struct {
    AllocFunc alloc_func;
    Chunk* alloc_ptr;
    u64 chunks_per_block;
    u64 chunk_size;
} PoolAllocator;

Chunk* chunk_allocate_block(PoolAllocator* allocator);

void* pool_allocate(PoolAllocator* allocator);
void pool_deallocate(PoolAllocator* allocator, void* ptr);
