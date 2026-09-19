#ifndef SQSORT_H
#define SQSORT_H

#include <stdio.h>

void sqsort(void *arr, size_t arrsize, size_t elemsize, int (*cmp)(void *, void *));

#endif
