#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

/**
 * @brief Converts integer to ASCII string
 *
 * This function converts a signed 32-bit integer into a null-terminated
 * ASCII string for the specified base (2 to 16). The resulting string is
 * stored in the provided pointer using pointer arithmetic.
 *
 * @param data The signed integer to convert
 * @param ptr The pointer to the output buffer
 * @param base The numeric base to convert to (2 to 16)
 *
 * @return Length of the resulting string including null terminator
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts ASCII string to integer
 *
 * This function converts a null-terminated ASCII string to a signed 32-bit
 * integer using the specified base (2 to 16). The conversion uses pointer
 * arithmetic and handles signed numbers.
 *
 * @param ptr The pointer to the ASCII input string
 * @param digits The number of digits in the ASCII string
 * @param base The numeric base to convert from (2 to 16)
 *
 * @return The converted signed 32-bit integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
