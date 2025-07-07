#include "Arena.h"
#include "memory/Allocators/StackAllocator.h"

void* arena_push(Arena* arena, u64 size) {
    return stack_allocate(&arena->allocator, size);
}

void* arena_push(Arena* arena, u64 size, u64 alignment) {
    return stack_allocate(&arena->allocator, size, alignment);
}

void arena_clear(Arena* arena) {
    stack_clear(&arena->allocator);
}
