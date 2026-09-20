
//#include "sqsort.h"
#include "io.h"
#include "structs.h"
#include "sqsort.h"

#include <string.h>

#include <stdlib.h>



int scmp(void *s1, void *s2);

int main(){

    const char * flnm = "inp.txt";

    filedata fldt = {.flnm = flnm};

    rdfrmfl(&fldt);

    printArr(fldt.prsdbffr, fldt.nlns);

    sqsort(fldt.prsdbffr, sizeof(fldt.prsdbffr[0]) * (size_t) fldt.nlns, sizeof(fldt.prsdbffr[0]), scmp);

    printArr(fldt.prsdbffr, fldt.nlns);

    free(fldt.rdbffr);
    free(fldt.prsdbffr);
}

int scmp(void *s1ptr, void *s2ptr){

    //printf("strcmp(%s, %s) = %d\n", *(const char **) s1ptr, *(const char **) s2ptr, strcmp(*(const char **) s1ptr, *(const char **) s2ptr));
    return strcmp(*(const char **) s1ptr, *(const char **) s2ptr);
}
