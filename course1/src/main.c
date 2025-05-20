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
 * @file main.c
 * @brief Main entry point for the Course 1 application
 *
 * This file contains the main function which conditionally calls the
 * course1() function when the COURSE1 compile-time switch is enabled.
 * This allows different course deliverables to be conditionally built
 * and executed based on compilation flags.
 *
 * To enable this, compile using the -DCOURSE1 flag.
 *
 * Example:
 * gcc -DCOURSE1 -o main main.c course1.c
 *
 * @author 
 * @date 
 *
 */

#include "course1.h"  // Ensure this header declares: void course1(void);

/**
 * @brief Main function
 *
 * Entry point of the program. Calls course1() if the COURSE1 macro is defined.
 *
 * @return int Returns 0 after execution
 */
int main() {
#ifdef COURSE1
    course1();
#endif
    return 0;
}
