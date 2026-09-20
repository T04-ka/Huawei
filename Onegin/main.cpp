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

    char** rdfrmfl(const char* flnm, char* data);

    const char * flnm = "inp.txt";

    char* readdata = NULL;
    char** parseddata = rdfrmfl(flnm, readdata);

    free(readdata);
    free(parseddata);
}

int scmp(void *s1ptr, void *s2ptr){

    //printf("strcmp(%s, %s) = %d\n", *(const char **) s1ptr, *(const char **) s2ptr, strcmp(*(const char **) s1ptr, *(const char **) s2ptr));
    return strcmp(*(const char **) s1ptr, *(const char **) s2ptr);
}

#include <sys/stat.h>


char** rdfrmfl(const char* flnm, char* databffr){

    FILE* file = fopen(flnm, "r");

    struct stat fldata = {};
    stat(flnm, &fldata);

    size_t size = (size_t) fldata.st_blksize;
    databffr = (char*) calloc(size + 1, 1);

    fread(databffr, sizeof(char), size, file);

    char** parsedata(char* data, size_t size, size_t* linescnt);

    size_t linescnt = 0;

    char** prsdbffr = parsedata((char*) databffr, size, &linescnt);


    printf("n = %zu\n", linescnt);
    for (size_t i = 0; i < linescnt; i++){

        printf("|%s|\n", prsdbffr[i]);
    }

    return prsdbffr;
}


char** parsedata(char data[], size_t size, size_t* cnt){

    *cnt = 0;

    for (size_t i = 0; i < size; i++){

        if (data[i] == '\n'){

            (*cnt)++;
        }
    }


    char** prsdbffr = (char**) calloc(*cnt, sizeof(char*));
    char** prsdbffrptr = prsdbffr;

    char* prevptr = data;

    for (size_t i = 0; i < size; i++){

        if (data[i] == '\n'){

            data[i] = '\0';
            *(prsdbffrptr++) = prevptr;
            prevptr = data + i + 1;
        }
    }

    return prsdbffr;
}

void printArr(const char* arr[], size_t sz){


    for (size_t i = 0; i < sz; i++) {

        printf("%s ", arr[i]);
    }
    putchar('\n');
    getchar();
}
