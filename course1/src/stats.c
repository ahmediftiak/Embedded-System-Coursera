/******************************************************************************
 * @file stats.c
 * @brief This file contains functions for statistical analysis of an array.
 *
 * This file includes functions to calculate and print statistics such as
 * minimum, maximum, mean, and median values of an array. Additionally, it
 * includes a function to sort the array in descending order.
 *
 * Author: Iftiak Ahmed
 * Date: 07/15/2024
 ******************************************************************************/

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

// void main() {

//   unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
//                               114, 88,   45,  76, 123,  87,  25,  23,
//                               200, 122, 150, 90,   92,  87, 177, 244,
//                               201,   6,  12,  60,   8,   2,   5,  67,
//                                 7,  87, 250, 230,  99,   3, 100,  90};

//   /* Other Variable Declarations Go Here */
//   /* Statistics and Printing Functions Go Here */
//   printf("Data set (Unsorted) :");
//   print_array(test, SIZE);
//   printf("\n");
//   print_statistics(test, SIZE);
//   printf("\n");
//   printf("Data set (Sorted): ");
//   print_array(test, SIZE);

// }

/* Add other Implementation File Code Here */
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
void print_statistics(unsigned char* array, unsigned int length) {
    printf("Statistics:\n");
    printf("Minimum: %d\n", find_minimum(array, length));
    printf("Maximum: %d\n", find_maximum(array, length));
    printf("Mean: %d\n", find_mean(array, length));
    printf("Median: %d\n", find_median(array, length));
}

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
void print_array(unsigned char* array, unsigned int length) {
  printf("Array: ");
  for (unsigned int i = 0; i < length; i++) {
    printf("%d ", array[i]);
    }
    printf("\n");
}

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
unsigned char find_median(unsigned char* array, unsigned int length) {
  sort_array(array, length);
  if (length % 2 == 0) {
    return (array[length / 2] + array[length / 2 - 1])/2;
  } else {
    return array[length / 2];
  }
}

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
unsigned char find_mean(unsigned char* array, unsigned int length) {
  unsigned int sum = 0;
  for (unsigned int i = 0; i < length; i++) {
    sum += array[i];
  }
  return sum / length;
}

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
unsigned char find_maximum(unsigned char* array, unsigned int length) {
  unsigned char max = array[0];
  for (unsigned int i = 1; i < length; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

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
unsigned char find_minimum(unsigned char* array, unsigned int length) {
  unsigned char min = array[0];
  for (unsigned int i = 1; i < length; i++) {
    if (array[i] < min) {
      min = array[i];
    }  
  }
  return min;
}
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
void sort_array(unsigned char* array, unsigned int length) {
    quicksort(array, 0, length - 1);
}

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
void quicksort(unsigned char* array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

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
int partition(unsigned char* array, int low, int high) {
    unsigned char pivot = array[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (array[j] > pivot) {
            i++;
            unsigned char temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    unsigned char temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}