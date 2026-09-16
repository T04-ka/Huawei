#include <stdio.h>
#include <assert.h>

#define SZ 6

#define pdbg(A)  printArr(arr, SZ, leftbrdr, rightbrdr, leftptr, rightptr, midval, A);

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

void qsort(int* arr, size_t leftbrdr, size_t rightbrdr);

void swap(int *arr, size_t i, size_t j);

void printArr(int *arr, size_t size, size_t lB = 0, size_t rB = 0, size_t l = 0, size_t r = 0, int mid = 0, const char *com = "");

int main(){

    int arr[] = {8,8,9,10,8,1};

    printArr(arr, SZ);

    qsort(arr, 0, SZ - 1);

    printArr(arr, SZ);
}


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

        printf("%d ", arr[i]);

        printf(DEF);
    }

    printf("| %lu | %lu", r, rB);
    putchar('\n');

    //getchar();
}

//Cmp (*cmp)(void *a, void *b)
void qsort(int* arr, size_t leftbrdr, size_t rightbrdr){

            assert(arr != NULL);

            if (leftbrdr >= rightbrdr){

                return;
            }

            assert(leftbrdr < rightbrdr);
            assert(leftbrdr >= 0);

            bool was_swap = 0;

            int midval = arr[(leftbrdr + rightbrdr)/2];

            size_t leftptr = leftbrdr;
            size_t rightptr = rightbrdr;

            pdbg("Start qsort\n");




            while (leftptr < rightptr){

              //  printArr(arr, SZ, leftbrdr, rightbrdr, leftptr, rightptr, "Begin of cicl\n");

                pdbg("Begin of cicl\n");

                assert(rightptr >= leftbrdr);
                assert(leftptr <= rightbrdr);
                assert(rightptr <= rightbrdr);
                assert(leftptr >= leftbrdr);

                if (arr[leftptr] >=  midval) {

                    while (rightptr > leftptr && arr[rightptr] > midval)
                    {
                        --rightptr;
                        /*
                        assert(rightptr >= leftbrdr);
                        assert(leftptr <= rightbrdr);
                        assert(rightptr <= rightbrdr);
                        assert(leftptr >= leftbrdr);
                        */
                        //printf("CICL rptr = %lu\n", rightptr);
                    }

                    pdbg("BEFORESWAP\n");

                    //printf("RPTR = %lu\n", rightptr);
                    was_swap = 1;
                    swap(arr, leftptr, rightptr);

                    pdbg("AFTERSWAP\n");

                }

                leftptr++;
            }

            if (!was_swap)
                return;

            pdbg("After cicl\n");

            qsort(arr, leftbrdr, leftptr - 1);
            qsort(arr, rightptr + 1, rightbrdr);
}

void swap(int *arr, size_t i, size_t j){

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

