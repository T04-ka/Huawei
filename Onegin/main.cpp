#include "sqsort.h"

#include <string.h>



void printArr(const char* arr[], size_t sz);

int scmp(void *s1, void *s2);

int main(){

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

int scmp(void *s1ptr, void *s2ptr){

    //printf("strcmp(%s, %s) = %d\n", *(const char **) s1ptr, *(const char **) s2ptr, strcmp(*(const char **) s1ptr, *(const char **) s2ptr));
    return strcmp(*(const char **) s1ptr, *(const char **) s2ptr);
}


char** rdfrmfl(const char* flnm){

    FILE* file = fopen(flnm, "r");
    struct stat fldata = {};
    const char* bffr[] = fread(file, );

}
void printArr(const char* arr[], size_t sz){


    for (int i = 0; i < sz; i++) {

        printf("%s ", arr[i]);
    }
    putchar('\n');
    getchar();
}
