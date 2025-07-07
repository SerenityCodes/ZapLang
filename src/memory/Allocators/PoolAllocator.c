#include "PoolAllocator.h"

#include <cstdlib>


Chunk* chunk_allocate_block(PoolAllocator* allocator) {
    size_t block_size = allocator->chunks_per_block * allocator->chunk_size;
    Chunk* block_begin = static_cast<Chunk*>(allocator->alloc_func(block_size, 1));

    Chunk* begin = block_begin;
    for (size_t i = 0; i < allocator->chunks_per_block; i++) {
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
    Chunk* to_be_freed = static_cast<Chunk*>(ptr);
    to_be_freed->next = allocator->alloc_ptr;
    allocator->alloc_ptr = to_be_freed;
}

