#include <stdio.h>
#include <string.h>

#include "qsort.cpp"

void printArr(void* arr[], size_t sz);

int scmp(void *s1, void *s2);

int main(){

    const char * strArr[] = {"abc",
                             "aasdd",
                             "adsda"
    };

    void* arr[] = { (void*)  strArr,
                    (void*) (strArr + 1),
                    (void*) (strArr + 2),
    };

    const size_t sz = 3;

    printArr(arr, sz);

    qsort(arr, 0, sz - 1, scmp);

    printArr(arr, sz);

}

int scmp(void *s1, void *s2){

    return strcmp((const char *) s1, (const char *) s2);
}

void printArr(void* arr[], size_t sz){


    for (int i = 0; i < sz; i++) {

        printf("%s\n", *((const char**) arr[i]));
    }
    getchar();
}
