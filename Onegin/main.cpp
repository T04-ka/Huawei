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

    size_t size = fldata.st_blksize;
    void *databffr = calloc(size + 1, 1);

    fread(databffr, sizeof(char), size, file);

    int parsedata(char* data, size_t size);
    int ncnt = parsedata((char*) databffr, size);
    printf("Nlines + 1 = %d\n", ncnt);
    return (char*) databffr;

}

#define tovoid (void*)
#define tochar  (char*)

int parsedata(char data[], size_t size){

    int cnt = 0;
    for (size_t i = 0; i < size; i++){

        if (data[i] == '\n'){

            cnt++;
        }
    }

    /*
    void* prsdbffr = tovoid calloc(cnt, sizeof(void*));

    void* prevptr = tovoid data;

    for (size_t i = 0; i < size; i++){

        if (data[i] == '\n'){

            data[i] = '\0';
            cnt++;
        }
    }
    */

    return cnt;
}

void printArr(const char* arr[], size_t sz){


    for (int i = 0; i < sz; i++) {

        printf("%s ", arr[i]);
    }
    putchar('\n');
    getchar();
}
