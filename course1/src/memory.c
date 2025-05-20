/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Implementation of memory manipulation functions
 *
 * This file contains implementations of memory functions such as move,
 * copy, set, zero, reverse, allocate, and free. All operations are done
 * using pointer arithmetic without array indexing.
 *
 * @author
 * @date
 *
 */
#include <stdlib.h>  // For malloc and free
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>


uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
    uint8_t * ret = dst;  // Save original dst pointer
    if (src == dst || length == 0) return ret;

    if (dst > src && dst < src + length) {
        src += length - 1;
        dst += length - 1;
        while (length--) {
            *dst-- = *src--;
        }
    } else {
        while (length--) {
            *dst++ = *src++;
        }
    }
    return ret;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
    uint8_t * ret = dst;
    while (length--) {
        *dst++ = *src++;
    }
    return ret;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
    uint8_t *ptr = src;
    while (length--) {
        *ptr++ = value;
    }
    return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {
    uint8_t *ptr = src;
    while (length--) {
        *ptr++ = 0;
    }
    return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length) {
    if (src == NULL || length == 0) return src;

    // printf("Before reverse:\n");
    // for (size_t i = 0; i < length; i++) {
    //     printf("%d ", src[i]);
    // }
    // printf("\n");

    uint8_t *start = src;
    uint8_t *end = src + length - 1;

    while (start < end) {
        uint8_t temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    // printf("After reverse:\n");
    // for (size_t i = 0; i < length; i++) {
    //     printf("%d ", src[i]);
    // }
    // printf("\n");

    return src;
}

uint32_t * reserve_words(size_t length) {
    uint32_t * ptr = (uint32_t *) malloc(length * sizeof(uint32_t));
    return ptr;  // returns NULL if malloc fails
}

void free_words(uint32_t * src) {
    free(src);
}
