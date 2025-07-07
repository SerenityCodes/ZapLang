#pragma once

#include "common.h"

typedef struct {
    u64 size;
    u64 capacity;
    void* data;
} DynArray;

#define DYN_ARRAY_PUSH(array_ptr, elem, type, alloc_func, alloc_ptr) \
    if (array_ptr->size + 1 > array_ptr->capacity) {\
        void* new_data = alloc_func(alloc_ptr, sizeof(type) * array_ptr->capacity * 2);\
        memcpy(new_data, array_ptr->data, sizeof(type) * array_ptr->size);\
        array_ptr->data = new_data;\
    }\
    array_ptr->data[array_ptr->size++] = elem;\

#define DYN_ARRAY_CLEAR(array_ptr, type, clear_mem) \
    array_ptr->size = 0;\
    if (clear_mem) {\
        memset(array_ptr->data, 0, array_ptr->capacity * sizeof(type));\
    }\
