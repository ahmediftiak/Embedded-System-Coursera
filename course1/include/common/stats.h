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
/******************************************************************************
 * @file stats.h
 * @brief Header file for stats.c.
 *
 * Contains declarations for functions that perform statistical analysis
 * on an array of unsigned characters.
 *
 * Author: Iftiak Ahmed
 * Date: 07/15/2024
 ******************************************************************************/

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * This function takes an array and its length as inputs and prints the minimum,
 * maximum, mean, and median values of the array.
 *
 * @param array The array of unsigned characters.
 * @param length The length of the array.
 *
 * @return void
 */
void print_statistics(unsigned char* array, unsigned int length);

/**
 * @brief Prints the array to the screen.
 *
 * This function takes an array and its length as inputs and prints each element
 * of the array to the screen.
 *
 * @param array The array of unsigned characters.
 * @param length The length of the array.
 *
 * @return void
 */
void print_array(unsigned char* array, unsigned int length);

/**
 * @brief Finds the median value of the array.
 *
 * This function takes an array and its length as inputs, sorts the array, and
 * returns the median value.
 *
 * @param array The array of unsigned characters.
 * @param length The length of the array.
 *
 * @return The median value of the array.
 */
unsigned char find_median(unsigned char* array, unsigned int length);

/**
 * @brief Finds the mean value of the array.
 *
 * This function takes an array and its length as inputs, calculates the sum of
 * the array elements, and returns the mean value.
 *
 * @param array The array of unsigned characters.
 * @param length The length of the array.
 *
 * @return The mean value of the array.
 */
unsigned char find_mean(unsigned char* array, unsigned int length);

/**
 * @brief Finds the maximum value in the array.
 *
 * This function takes an array and its length as inputs, iterates through the
 * array, and returns the maximum value.
 *
 * @param array The array of unsigned characters.
 * @param length The length of the array.
 *
 * @return The maximum value of the array.
 */
unsigned char find_maximum(unsigned char* array, unsigned int length);

/**
 * @brief Finds the minimum value in the array.
 *
 * This function takes an array and its length as inputs, iterates through the
 * array, and returns the minimum value.
 *
 * @param array The array of unsigned characters.
 * @param length The length of the array.
 *
 * @return The minimum value of the array.
 */
unsigned char find_minimum(unsigned char* array, unsigned int length);

/**
 * @brief Sorts the array from largest to smallest.
 *
 * This function takes an array and its length as inputs and sorts the array
 * in descending order using the quicksort algorithm.
 *
 * @param array The array of unsigned characters.
 * @param length The length of the array.
 *
 * @return void
 */
void sort_array(unsigned char* array, unsigned int length);

/**
 * @brief Sorts the array using the quicksort algorithm.
 *
 * This function takes an array and the indices of the low and high elements,
 * partitions the array, and recursively sorts the partitions.
 *
 * @param array The array of unsigned characters.
 * @param low The index of the first element in the array.
 * @param high The index of the last element in the array.
 *
 * @return void
 */
void quicksort(unsigned char* array, int low, int high);

/**
 * @brief Partitions the array for quicksort.
 *
 * This function takes an array and the indices of the low and high elements,
 * partitions the array around a pivot, and returns the index of the pivot.
 *
 * @param array The array of unsigned characters.
 * @param low The index of the first element in the array.
 * @param high The index of the last element in the array.
 *
 * @return The index of the pivot.
 */
int partition(unsigned char* array, int low, int high);

#endif // __STATS_H__
