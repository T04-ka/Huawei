#include "qsort.h"



//----------------------------------------------------------------------------------------------------------------
/// Swaps 2 elements pointed by void*
///
/// @param[in] i    Pointer to first element
/// @param[in] j    Pointer to second element
/// @param[in] size Size of elements to swap
///
//----------------------------------------------------------------------------------------------------------------
void swap(void* e1ptr, void* e2ptr, size_t size);



//----------------------------------------------------------------------------------------------------------------
void myqsort(void* arr, size_t elemsize, size_t arrsize, int (*cmp)(const void *e1ptr, const void *e2ptr)){

    size_t rightbrdr = arrsize/elemsize - 1;

    if (rightbrdr <= 0 || arrsize <= 0) {

        return;
    }
    size_t leftptr = 0;
    size_t rightptr = rightbrdr;

    void* pivot = (void*) ((char*) arr + elemsize * (rightbrdr / 2));

    while (leftptr < rightptr) {

        if ((*cmp)((void*) ((char*) arr + elemsize * leftptr), pivot) >= 0) {

            while (rightptr > leftptr && (*cmp)((void*) ((char*) arr + elemsize * rightptr), pivot) > 0)
            {
                --rightptr;
            }

            void* ptr1toswp = (void*) ((char*) arr + elemsize * leftptr);
            void* ptr2toswp = (void*) ((char*) arr + elemsize * rightptr);

            if (ptr1toswp == pivot) {

                pivot = ptr2toswp;
            }
            else if (ptr2toswp == pivot) {

                pivot = ptr1toswp;
            }

            swap(ptr1toswp, ptr2toswp, elemsize);
        }
        leftptr++;
    }

    size_t indpivot = (size_t) ((char*) pivot - (char*) arr) / elemsize;

    myqsort(arr, elemsize, elemsize * indpivot, cmp);

    myqsort((void*) ((char*) arr + (indpivot + 1) * elemsize), elemsize, elemsize * (rightbrdr - indpivot), cmp);
}


//----------------------------------------------------------------------------------------------------------------
void swap(void* e1ptr, void* e2ptr, size_t size){

    for (size_t i = 0; i < size; i++){

        char tmpbyte = *((char *) e1ptr + i);

        *((char *) e1ptr + i) = *((char *) e2ptr + i);

        *((char *) e2ptr + i) = tmpbyte;
    }
}


//----------------------------------------------------------------------------------------------------------------
