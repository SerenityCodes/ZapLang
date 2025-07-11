#pragma once

#include "memory/Allocator.h"

typedef struct {
    char* bytes;
    u64 length;
} CharString;

void init_string(Allocator* allocator, CharString* str) {
    str->length = 0;
    str->bytes = NULL;
}

CharString* copy_c_string(Allocator* allocator, char* str) {
    int str_len = strlen(str);
    CharString* new_str = (CharString*) allocate_memory(allocator, sizeof(CharString));
    new_str->length = str_len;
    new_str->bytes = (char*) allocate_memory(allocator, str_len);
    for (int i = 0; i < str_len; i++) {
        new_str->bytes[i] = str[i];
    }
    return new_str;
}

char* c_str(Allocator* alloc, CharString* str) {
    char* buff = (char*) allocate_memory(alloc, str->length + 1);
    strncpy(buff, str->bytes, str->length); 
    buff[str->length] = '\0';
    return buff;
}


