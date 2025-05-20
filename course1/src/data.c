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
 * @file data.c
 * @brief Functions to convert integers to ASCII and back
 *
 * This file provides two core conversion utilities: my_itoa() and my_atoi().
 * These functions allow for conversion between signed integers and their
 * ASCII string representations for arbitrary bases between 2 and 16.
 *
 * All operations are done using pointer arithmetic.
 *
 * @author 
 * @date 
 */

#include <stdint.h>
#include <stddef.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    uint8_t * start = ptr;
    uint8_t temp[33];
    int i = 0;
    int is_negative = 0;

    if (data == 0) {
        *ptr++ = '0';
        *ptr = '\0';
        return 2; // '0' and null terminator
    }

    if (data < 0 && base == 10) {
        is_negative = 1;
        data = -data;
    }

    while (data != 0) {
        int rem = data % base;
        *(temp + i++) = (rem > 9) ? (rem - 10 + 'A') : (rem + '0');
        data /= base;
    }

    if (is_negative) {
        *(temp + i++) = '-';
    }

    // Reverse the digits
    for (int j = i - 1; j >= 0; j--) {
        *ptr++ = *(temp + j);
    }

    *ptr = '\0';

    return (uint8_t)((ptr - start) + 1); // including null terminator
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    int32_t result = 0;
    int is_negative = 0;

    if (*ptr == '-') {
        is_negative = 1;
        ptr++;
        digits--;
    }

    while (digits--) {
        char c = *ptr++;
        int value;

        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        } else {
            return 0; // Invalid character
        }

        result = result * base + value;
    }

    return is_negative ? -result : result;
}
