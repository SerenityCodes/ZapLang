#pragma once

#include <cstdio>
#include "common.h"
#include "containers/Array.h"
#include "memory/Allocators/StackAllocator.h"
#include "memory/Arena.h"

typedef struct {
    Arena temp_arena;
    StackAllocator calc_allocator;
     
} Engine;

void run_engine(Engine* engine);

Array* read_byte_file(AllocFunc alloc_func, const char* file_name) {
    FILE* file = fopen(file_name, "rb");
    ZAP_ASSERT(file != NULL, "Failed to open file {}", file_name);
    Array* new_arr = (Array*) alloc_func(NULL, sizeof(Array), sizeof(Array));  
    ZAP_ASSERT(fseek(file, 0L, SEEK_END) == 0, "Error seeking the end of the file {}", file_name);
    u64 file_size = ftell(file);         
    ZAP_ASSERT(file_size != -1, "Error getting the file size from the end of file {}", file_name);
    new_arr->data = alloc_func(NULL, file_size, 1);
    ZAP_ASSERT(fseek(file, 0L, SEEK_SET) == 0, "Failed to return to the beginning of file {}", file_name);
    u64 new_length = fread((u8*) new_arr->data, sizeof(u8), file_size, file);
    ZAP_ASSERT(ferror(file) == 0, "Error reading file {}", file_name)
    new_arr->size = new_length;
    fclose(file);
    return new_arr;
}

