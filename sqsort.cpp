#include "sqsort.h"

//-------------------------------------------------------------------------------------
/// Swaps two elements of the array.
///
/// @param elm1ptr Void* pointer to the first element.
/// @param elm2ptr Void* pointer to the second element.
/// @param size Size of the elements.
///
//-------------------------------------------------------------------------------------
void swap(void *elm1ptr, void *elm2ptr, size_t size);


//-------------------------------------------------------------------------------------
void sqsort(void *arr, size_t arrsize, size_t elemsize, int (*cmp)(const void *, const void *)){

    size_t len = arrsize/elemsize;

    for (size_t i = 0; i < len; i++){

        void* ivl = (void *) ((char *) arr + elemsize * i);
        void* min = ivl;


        for (size_t j = i; j < len; j++){

            void *jvl = (void *) ((char *) arr + elemsize * j);

            if (cmp((const void *) min, (const void *) jvl) > 0){

                min = jvl;
            }
        }
        if (min != ivl)
            swap(ivl, min, elemsize);
    }
}


//-------------------------------------------------------------------------------------
void swap(void *elm1ptr, void *elm2ptr, size_t size){

    for (size_t i = 0; i < size; i++){

            char tmpbyte = *((char *) elm1ptr + i);

            *((char *) elm1ptr + i) = *((char *) elm2ptr + i);

            *((char *) elm2ptr + i) = tmpbyte;
        }
}


//-------------------------------------------------------------------------------------
