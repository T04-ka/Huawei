#include <stdio.h>
#include <string.h>

int numcmp(void *elm1ptr, void *elm2ptr);
int scmp(void *s1ptr, void *s2ptr);
void sqsort(void *arr, size_t arrsize, size_t elemsize, int (*cmp)(void *, void *));
void swap(void *elm1ptr, void *elm2ptr, size_t size);

int main(){
    void printArr(const char* arr[], size_t len);

    const char * arr[] = {"f",
                              "c",
                              "a",
                              "b",
                              "e"
        };


    size_t len = sizeof(arr) / sizeof(arr[0]);

    printf("Before sort:\n");
    printArr(arr, len);

    sqsort(arr, sizeof(arr), sizeof(arr[0]), &numcmp);

    printf("\nAfter sort:\n");
    printArr(arr, len);
}

void printArr(const char* arr[], size_t len){

    for (size_t i = 0; i < len; i++){

        printf("%s ", arr[i]);
    }
    putchar('\n');
}

int scmp(void *s1ptr, void *s2ptr){

    printf("strcmp(%s, %s) = %d\n", *(const char **) s1ptr, *(const char **) s2ptr, strcmp(*(const char **) s1ptr, *(const char **) s2ptr));
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
