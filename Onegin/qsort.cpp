/*
#ifndef QSORT_CPP
#define QSORT_CPP
#include <stdio.h>
#include <assert.h>
#endif
*/

//----------------------------------------------------------------------------------------------------------------
/// Sorting the void* array with personal comparator given
///
/// @param[in] arr[]     Array with data
/// @param[in] leftbrdr  Left border of array part to sort
/// @param[in] rightbrdr Right border of array part to sort
/// @param[in] cmp       Personal comparator
///
/// @note Comparator must return 0 if elements are equal,
///                              positive int if first elem > second elem,
///                              negative int if first elem < second elem.
//----------------------------------------------------------------------------------------------------------------
void qsort(void* arr[], size_t leftbrdr, size_t rightbrdr, int (*cmp)(void *a, void *b));


//----------------------------------------------------------------------------------------------------------------
/// Swaps 2 elements pointed by void*
///
/// @param[in] i    Pointer to first element
/// @param[in] j    Pointer to second element
///
//----------------------------------------------------------------------------------------------------------------
void swap(void* *i, void* *j);



//----------------------------------------------------------------------------------------------------------------
void qsort(void* arr[], size_t leftbrdr, size_t rightbrdr, int (*cmp)(void *a, void *b)){

          //  assert(arr != NULL);

            if (leftbrdr >= rightbrdr){

                return;
            }
            /*
            assert(leftbrdr < rightbrdr);
            assert(leftbrdr >= 0);
            */
            void* midval = arr[(leftbrdr + rightbrdr)/2];

            size_t leftptr = leftbrdr;
            size_t rightptr = rightbrdr;

            //pdbg("Start qsort\n");

            while (leftptr < rightptr){

                //pdbg("Begin of cicl\n");
                /*
                assert(rightptr >= leftbrdr);
                assert(leftptr <= rightbrdr);
                assert(rightptr <= rightbrdr);
                assert(leftptr >= leftbrdr);
                */
                if ((*cmp)(arr[leftptr], midval) >= 0) {

                    while (rightptr > leftptr && (*cmp)(arr[rightptr], midval) > 0)
                    {
                        --rightptr;
                        /*
                        assert(rightptr >= leftbrdr);
                        assert(leftptr <= rightbrdr);
                        assert(rightptr <= rightbrdr);
                        assert(leftptr >= leftbrdr);
                        */
                        //pdbg("Rfind cicl\n");
                    }

                    //pdbg("BEFORESWAP\n");

                    //printf("RPTR = %lu\n", rightptr);
                    swap(arr + leftptr, arr + rightptr);

                    //pdbg("AFTERSWAP\n");

                }

                leftptr++;
            }

            //pdbg("After cicl\n");

            qsort(arr, leftbrdr, leftptr - 1, cmp);
            qsort(arr, rightptr + 1, rightbrdr, cmp);
}



//----------------------------------------------------------------------------------------------------------------
void swap(void* *i, void* *j){
//void swap(void **i, void **j){

    void* temp = *i;
    *i = *j;
    *j = temp;
}


//----------------------------------------------------------------------------------------------------------------

