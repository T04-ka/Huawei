#include "sqsort.h"


void swap(void *elm1ptr, void *elm2ptr, size_t size);

void sqsort(void *arr, size_t arrsize, size_t elemsize, int (*cmp)(void *, void *)){

    size_t len = arrsize/elemsize;

    for (size_t i = 0; i < len; i++){
        for (size_t j = i; j < len; j++){

            void *ivl = (void *) ((char*) arr + elemsize * i);
            void *jvl = (void *) ((char*) arr + elemsize * j);

            if (cmp(ivl, jvl) > 0){

                swap(ivl, jvl, elemsize);
            }
        }
    }
}

void swap(void *elm1ptr, void *elm2ptr, size_t size){

    for (size_t i = 0; i < size; i++){

            char tmpbyte = *((char *) elm1ptr + i);

            *((char *) elm1ptr + i) = *((char *) elm2ptr + i);

            *((char *) elm2ptr + i) = tmpbyte;
        }
}
