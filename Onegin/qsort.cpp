#include <stdio.h>
#include <assert.h>

#define SZ 5

#define pdbg(A)  printArr(arr, SZ, leftbrdr, rightbrdr, leftptr, rightptr, *((int*) midval), A);

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


//----------------------------------------------------------------------------------------------------------------
//void qsort(void* arr[], size_t leftbrdr, size_t rightbrdr);
void qsort(void* arr[], size_t leftbrdr, size_t rightbrdr, Cmp (*cmp)(void *a, void *b));


//----------------------------------------------------------------------------------------------------------------
void swap(void* *i, void* *j);


//----------------------------------------------------------------------------------------------------------------
void printArr(void* *arr, size_t size = 0, size_t lB = 0, size_t rB = 0, size_t l = 0, size_t r = 0, int mid = 0, const char *com = "");


//----------------------------------------------------------------------------------------------------------------
int main(){

    int numArr[] = {6,5,4,3,6};

    void* arr[] = {
        (void*) numArr,
        (void*) (numArr + 1),
        (void*) (numArr + 2),
        (void*) (numArr + 3),
        (void*) (numArr + 4),
        (void*) (numArr + 5),
    };

    printArr(arr, SZ);

    qsort((void **)arr, 0, SZ - 1, &numcmp);

    printArr(arr, SZ);
}


//----------------------------------------------------------------------------------------------------------------
void printArr(void* *arr, size_t size, size_t lB, size_t rB, size_t l, size_t r, int mid, const char *com){

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

        printf("%d ", *((int*)(arr)[i]));

        printf(DEF);
    }

    printf("| %lu | %lu", r, rB);
    putchar('\n');

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
void qsort(void* arr[], size_t leftbrdr, size_t rightbrdr, Cmp (*cmp)(void *a, void *b)){

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

