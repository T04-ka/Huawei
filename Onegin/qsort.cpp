#include <stdio.h>
#include <assert.h>
#include <string.h>

enum Cmp    {
    LESS = -1,
    EQ = 0,
    MORE = 1
};



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
//----------------------------------------------------------------------------------------------------------------
void qsort(void* arr, size_t elemsize, size_t arrsize, int (*cmp)(void *a, void *b));



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
void qsort(void* arr, size_t elemsize, size_t arrsize, int (*cmp)(void *e1ptr, void *e2ptr)){

    size_t leftbrdr = 0;
    size_t rightbrdr = arrsize/elemsize - 1;

    if (leftbrdr >= rightbrdr || arrsize <= 0){

        return;
    }

    size_t leftptr = leftbrdr;
    size_t rightptr = rightbrdr;

    size_t adress = elemsize * ((leftbrdr + rightbrdr)/2);

    void* pivot = (void*) ((char*) arr + adress);

    while (leftptr < rightptr){

        if ((*cmp)((void*) ((char*) arr + elemsize * leftptr), pivot) >= 0) {

            while (rightptr > leftptr && (*cmp)((void*) ((char*) arr + elemsize * rightptr), pivot) > 0)
            {
                --rightptr;
            }

            swap((void*) ((char*) arr + elemsize * leftptr), (void*) ((char*) arr + elemsize * rightptr), elemsize);
        }

        leftptr++;
    }

    qsort(arr, elemsize, elemsize * (leftptr - leftbrdr), cmp);
    qsort((void*) ((char*) arr + elemsize * (rightptr + 1)), elemsize, elemsize * (rightbrdr - rightptr), cmp);
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
