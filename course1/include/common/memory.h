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
 * @file memory.h
 * @brief Abstraction of memory manipulation operations
 *
 * This header file provides function declarations for low-level memory 
 * manipulation operations, including moving, copying, setting, zeroing, 
 * reversing memory, and dynamic memory allocation.
 * 
 * All functions use pointer arithmetic and avoid array indexing.
 *
 * @author
 * @date
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Moves a block of memory handling overlaps
 *
 * Moves `length` bytes from `src` to `dst`. Handles overlapping source 
 * and destination ranges safely.
 *
 * @param src Pointer to the source memory
 * @param dst Pointer to the destination memory
 * @param length Number of bytes to move
 *
 * @return Pointer to the destination memory
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies a block of memory without handling overlap
 *
 * Copies `length` bytes from `src` to `dst`. Behavior is undefined if 
 * source and destination regions overlap.
 *
 * @param src Pointer to the source memory
 * @param dst Pointer to the destination memory
 * @param length Number of bytes to copy
 *
 * @return Pointer to the destination memory
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets memory to a specific value
 *
 * Sets `length` bytes starting from `src` to the specified `value`.
 *
 * @param src Pointer to the memory block
 * @param length Number of bytes to set
 * @param value The value to write to each byte
 *
 * @return Pointer to the source memory
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets memory to zero
 *
 * Sets `length` bytes starting from `src` to zero.
 *
 * @param src Pointer to the memory block
 * @param length Number of bytes to zero
 *
 * @return Pointer to the source memory
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of bytes in memory
 *
 * Reverses the order of `length` bytes starting at `src`.
 *
 * @param src Pointer to the memory block
 * @param length Number of bytes to reverse
 *
 * @return Pointer to the source memory
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates dynamic memory for word storage
 *
 * Allocates memory for `length` 32-bit integers (words) and returns a pointer.
 *
 * @param length Number of 32-bit words to allocate
 *
 * @return Pointer to allocated memory, or NULL if allocation fails
 */
uint32_t * reserve_words(size_t length);

/**
 * @brief Frees dynamically allocated word memory
 *
 * Frees the memory pointed to by `src`.
 *
 * @param src Pointer to memory to be freed
 *
 * @return void
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
