#include "sqsort.h"

#include <cstdio>
#include <iterator>
#include <string.h>

#include <stdlib.h>

struct filedata {
    const char* flnm;
    size_t sz;
    int nlns;
    char *rdbffr;
    const char* *prsdbffr;
};

void printArr(const char* arr[], int nlines);
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

    void rdfrmfl(struct filedata* filedata);

    const char * flnm = "inp.txt";

    filedata fldt = {.flnm = flnm};

    rdfrmfl(&fldt);

    printArr(fldt.prsdbffr, fldt.nlns);


    free(fldt.rdbffr);
    free(fldt.prsdbffr);
}

int scmp(void *s1ptr, void *s2ptr){

    //printf("strcmp(%s, %s) = %d\n", *(const char **) s1ptr, *(const char **) s2ptr, strcmp(*(const char **) s1ptr, *(const char **) s2ptr));
    return strcmp(*(const char **) s1ptr, *(const char **) s2ptr);
}

#include <sys/stat.h>


void rdfrmfl(struct filedata* fldt){

    struct stat statdata = {};
    stat(fldt -> flnm, &statdata);

    fldt -> sz = (size_t) statdata.st_blksize;
    fldt -> rdbffr = (char*) calloc(fldt -> sz + 1, 1);

    FILE* file = fopen(fldt -> flnm, "r");
    fread(fldt -> rdbffr, sizeof(char), fldt -> sz, file);
    fclose(file);

    void parsedata(struct filedata* filedata);

    parsedata(fldt);
}


void parsedata(struct filedata* fldt){

    char* rbuf = fldt -> rdbffr;

    int chrncnt(char* line, char smpl, size_t size);

    fldt -> nlns = chrncnt(rbuf, '\n', fldt -> sz);

    const char* *prsdbffr = (const char**) calloc((size_t) fldt -> nlns, sizeof(char*));
    const char* *prsdbffrptr = prsdbffr;

    char* prevptr = rbuf;

    for (size_t i = 0; i < fldt -> sz; i++){

        if (rbuf[i] == '\n'){

            rbuf[i] = '\0';
            *(prsdbffrptr++) = prevptr;
            prevptr = rbuf + i + 1;
        }
    }

    fldt -> prsdbffr = prsdbffr;
}

int chrncnt(char* buf, char smpl, size_t size){

    int cnt = 0;

    for (size_t i = 0; i < size; i++){

        if (buf[i] == smpl){

            cnt++;
        }
    }

    return cnt;
}

void printArr(const char* arr[], int nlines){


    printf("nlines = %d\n", nlines);
    for (int i = 0; i < nlines; i++){

        printf("|%s|\n", arr[i]);
    }

    getchar();
}
