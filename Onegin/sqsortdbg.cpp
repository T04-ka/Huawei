#include <stdio.h>
#include <string.h>

enum Tp
    {Int = 1,
    Str = 2};

int numcmp(void *elm1ptr, void *elm2ptr);
int scmp(void *s1ptr, void *s2ptr);
void sqsort(void *arr, size_t arrsize, size_t elemsize, int (*cmp)(void *, void *));
void swap(void *elm1ptr, void *elm2ptr, size_t size);

int main(){
    void printArr(const char* arr[], size_t len);

    int arr1[] = {1,4,1,0,2,5,7};
    const char * arr2[] = {"c",
                          "a",
                          "b",
                          "d",
                          "e",
                      "y"
    };

    size_t len = sizeof(arr2) / sizeof(arr2[0]);

    printf("Before sort:\n");
    printArr(arr2, len);

    sqsort(arr2, sizeof(arr2), sizeof(arr2[0]), &scmp);

    printf("\nAfter sort:\n");
    printArr(arr2, len);
}

void printArr(const char* arr[], size_t len){

    for (size_t i = 0; i < len; i++){

                    printf("%s ", arr[i]);
    }
    putchar('\n');
}
/*
void printArr(void* arr, size_t len, Tp type){

    for (size_t i = 0; i < len; i++){

        switch (type)
        {
            case Int:
                {
                    printf("%d ", *((char*) arr + 4 * i));
                    break;
                }
            case Str:
                {
                    printf("%s ", *((char**) arr + 8 * i));
                    break;
                }
        }
    }
    putchar('\n');
}
*/
int scmp(void *s1ptr, void *s2ptr){

    return strcmp(*(const char **) s1ptr, *(const char **) s2ptr);
}


int numcmp(void *elm1ptr, void *elm2ptr){

    int elm1 = *((int*) elm1ptr);
    int elm2 = *((int*) elm2ptr);

    return (elm1 < elm2) ? -1 : (elm1 == elm2) ? 0 : 1;
}

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
