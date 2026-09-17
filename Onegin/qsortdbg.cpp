#include <stdio.h>
#include <assert.h>
#include <string.h>

#define SZ 3

#define pdbg(A)  printArr((int *) arr, rightbrdr - leftbrdr + 1, leftbrdr, rightbrdr, leftptr, rightptr, *((int*) pivot), A);

#define RED "\e[31m"
#define BLUE "\e[34m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define DEF "\e[0m"

enum Cmp    {
    LESS = -1,
    EQ = 0,
    MORE = 1
};


//----------------------------------------------------------------------------------------------------------------
Cmp numcmp(void* a, void *b);

int scmp(void *s1, void *s2);


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
void qsort(void* arr, size_t elemsize, size_t arrsize, int (*cmp)(void *a, void *b));


//----------------------------------------------------------------------------------------------------------------
/// Swaps 2 elements pointed by void*
///
/// @param[in] i    Pointer to first element
/// @param[in] j    Pointer to second element
///
//----------------------------------------------------------------------------------------------------------------
void swap(void* e1ptr, void* e2ptr, size_t size);


//----------------------------------------------------------------------------------------------------------------
void printArr(int *arr, size_t size = 0, size_t lB = 0, size_t rB = 0, size_t l = 0, size_t r = 0, int mid = 0, const char *com = "");


//----------------------------------------------------------------------------------------------------------------
int main(){

    int arr[] = {1,4,5,0,9,1};

    const size_t sz = 6;

    printArr(arr, sz);
    printf("ZZZ");
    qsort((void *) arr, sizeof(arr), sizeof(arr[0]), (int (*)(void*, void*)) &numcmp);

    printArr(arr, sz);
}


int scmp(void *s1, void *s2){

    return strcmp((const char *) s1, (const char *) s2);
}


//----------------------------------------------------------------------------------------------------------------
void printArr(int *arr, size_t size, size_t lB, size_t rB, size_t l, size_t r, int mid, const char *com){

    printf("%sMID = %d\n", com, mid);

    printf("%lu | %lu | ", lB, l);
  
    for (size_t i = 0; i < size; i++){

        if (i == l && i != r) {

            printf(BLUE);
        }

        else if (i == r && i != l) {

            printf(RED);
        }
        else if (i == r && i == l) {

            printf(GREEN);
        }
        else {

            printf(YELLOW);
        }

        printf("%d  ", arr[i]);

        printf(DEF);
    }
    printf("| %lu | %lu", r, rB);
    putchar('\n');
 
    printf("ZZZ");   
    getchar();
    
}


//----------------------------------------------------------------------------------------------------------------
Cmp numcmp(void* a, void *b){

    int va = *((int *) a);
    int vb = *((int *) b);

    if (va > vb)  return MORE;
    if (va < vb)  return LESS;
    return EQ;
}


//----------------------------------------------------------------------------------------------------------------
void qsort(void* arr, size_t elemsize, size_t arrsize, int (*cmp)(void *a, void *b)){

            assert(arr != NULL);

            size_t leftbrdr = 0;
            size_t rightbrdr = arrsize/elemsize - 1;

            if (leftbrdr >= rightbrdr){

                return;
            }
            
            assert(leftbrdr < rightbrdr);
            assert(leftbrdr >= 0);
            
            void* pivot = (void*) ((char*) arr + elemsize * (leftbrdr + rightbrdr)/2);

            size_t leftptr = leftbrdr;
            size_t rightptr = rightbrdr;

            pdbg("Start qsort\n");

            while (leftptr < rightptr){

                pdbg("Begin of cicl\n");
                
                assert(rightptr >= leftbrdr);
                assert(leftptr <= rightbrdr);
                assert(rightptr <= rightbrdr);
                assert(leftptr >= leftbrdr);
                

                //printf("Strcmp = %d\n",(*cmp)(arr[leftptr], midval));

                if ((*cmp)((void*) ((char*) arr + elemsize * leftptr), pivot) >= 0) {

                    while (rightptr > leftptr && (*cmp)((void*) ((char*) arr + elemsize * rightptr), pivot) > 0)
                    {
                        --rightptr;
                        
                        assert(rightptr >= leftbrdr);
                        assert(leftptr <= rightbrdr);
                        assert(rightptr <= rightbrdr);
                        assert(leftptr >= leftbrdr);
                        
                        pdbg("Rfind cicl\n");
                    }

                    pdbg("BEFORESWAP\n");

                    //printf("RPTR = %lu\n", rightptr);
                    swap((void*) ((char*) arr + elemsize * leftptr), (void*) ((char*) arr + elemsize * rightptr), elemsize);

                    pdbg("AFTERSWAP\n");

                }

                leftptr++;
            }

            pdbg("After cicl\n");

            qsort(arr, elemsize, elemsize * (leftptr - leftbrdr), cmp);
            qsort((void*) ((char*) arr + elemsize * (rightptr + 1)), elemsize, elemsize * (rightbrdr - rightptr), cmp);
}



//----------------------------------------------------------------------------------------------------------------
void swap(void* e1ptr, void* e2ptr, size_t size){
//void swap(void **i, void **j){
    
    for (size_t i = 0; i < size; i++){

        char tmpbyte = *((char *) e1ptr + i);

        *((char *) e1ptr + i) = *((char *) e2ptr + i);

        *((char *) e2ptr + i) = tmpbyte;
    }
}

