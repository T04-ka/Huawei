
//#include "sqsort.h"
#include "io.h"
#include "structs.h"
#include "sqsort.h"
#include "cmprators.h"


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
