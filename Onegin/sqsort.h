#ifndef SQSORT_H
#define SQSORT_H

#include <stdio.h>

//-------------------------------------------------------------------------------------
/// Sorts an array using the square algorithm.
///
/// @param arr The array to sort.
/// @param arrsize The size of the array.
/// @param elemsize The size of each element.
/// @param cmp The comparison function.
///
/// @note The pointer to the array must be void*.
/// @note Comparator must return 0 if elements are equal,
///                              positive int if first elem > second elem,
///                              negative int if first elem < second elem.
//-------------------------------------------------------------------------------------
void sqsort(void *arr, size_t arrsize, size_t elemsize, int (*cmp)(void *, void *));

#endif
