#include "sqsort.h"

#include <string.h>

#include <stdlib.h>

void printArr(const char* arr[], size_t sz);

int scmp(void *s1, void *s2);

int main(){
    /*
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

    */

    char* rdfrmfl(const char* flnm);

    const char * flnm = "inp.txt";

    char* data = rdfrmfl(flnm);

    printf("|%s|", data);

    free(data);
}

int scmp(void *s1ptr, void *s2ptr){

    //printf("strcmp(%s, %s) = %d\n", *(const char **) s1ptr, *(const char **) s2ptr, strcmp(*(const char **) s1ptr, *(const char **) s2ptr));
    return strcmp(*(const char **) s1ptr, *(const char **) s2ptr);
}

#include <sys/stat.h>


char* rdfrmfl(const char* flnm){
    FILE* file = fopen(flnm, "r");
    struct stat fldata = {};
    stat(flnm, &fldata);
    void *databffr = calloc(fldata.st_blksize + 1, 1);
    fread(databffr, sizeof(char), fldata.st_blksize, file);
    return (char*) databffr;

}
void printArr(const char* arr[], size_t sz){


    for (int i = 0; i < sz; i++) {

        printf("%s ", arr[i]);
    }
    putchar('\n');
    getchar();
}
