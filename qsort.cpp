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
void myqsort(void* arr, size_t elemsize, size_t arrsize, int (*cmp)(void *a, void *b));



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
void myqsort(void* arr, size_t elemsize, size_t arrsize, int (*cmp)(void *e1ptr, void *e2ptr)){

    size_t leftbrdr = 0;
    size_t rightbrdr = arrsize/elemsize - 1;

    if (leftbrdr >= rightbrdr || arrsize <= 0) {

        return;
    }
    size_t leftptr = leftbrdr;
    size_t rightptr = rightbrdr;

    size_t adress = elemsize * ((leftbrdr + rightbrdr)/2);

    void* pivot = (void*) ((char*) arr + adress);

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

    qsort(arr, elemsize, elemsize * (indpivot - leftbrdr), cmp);

    qsort((void*) ((char*) arr + (indpivot + 1) * elemsize), elemsize, elemsize * (rightbrdr - indpivot), cmp);
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
