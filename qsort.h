#ifndef QSORT_H
#define QSORT_H

#include <stdio.h>

//----------------------------------------------------------------------------------------------------------------
/// Sorting the void* array with personal comparator given
///
/// @param[in] arr[]     Array with data
/// @param[in] elemsize  Size of one array element in bytes
/// @param[in] arrsize   Size of array in bytes
/// @param[in] cmp       Personal comparator
///
/// @note Comparator must return 0 if elements are equal,
///                              positive int if first elem > second elem,
///                              negative int if first elem < second elem.
///
/// @note DO NOT USE FOR 3 ELEMENTS
//----------------------------------------------------------------------------------------------------------------
void myqsort(void* arr, size_t elemsize, size_t arrsize, int (*cmp)(const void *a, const void *b));



#endif
