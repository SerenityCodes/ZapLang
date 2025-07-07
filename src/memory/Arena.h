#pragma once

#include "Allocators/StackAllocator.h"
#include "common.h"

typedef struct {
    StackAllocator allocator;  
} Arena;

void* arena_push(Arena* arena, u64 size);
void* arena_push(Arena* arena, u64 size, u64 alignment);

void arena_clear(Arena* arena);
