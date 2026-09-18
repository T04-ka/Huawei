#include <stdio.h>
#include <string.h>

#include "qsort.cpp"

void printArr(const char* arr[], size_t sz);

int scmp(void *s1, void *s2);

int main(){

    const char * arr[] = {"c",
                          "a",
                          "b"
    };

    printArr(arr, sizeof(arr)/sizeof(arr[0]));

    qsort(arr, sizeof(arr[0]), sizeof(arr), scmp);

    printArr(arr, sizeof(arr)/sizeof(arr[0]));
}

int scmp(void *s1ptr, void *s2ptr){

    printf("strcmp(%s, %s) = %d\n", *(const char **) s1ptr, *(const char **) s2ptr, strcmp(*(const char **) s1ptr, *(const char **) s2ptr));
    return strcmp(*(const char **) s1ptr, *(const char **) s2ptr);
}

void printArr(const char* arr[], size_t sz){


    for (int i = 0; i < sz; i++) {

        printf("%s\n", arr[i]);
    }
    getchar();
}
