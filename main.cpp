#include "io.h"
#include "structs.h"
#include "qsort.h"
#include "sqsort.h"
#include "cmprators.h"

#include <cstdlib>
#include <stdlib.h>


int main(){

    //const char * flnm = "ASPushkinEvgeniyOnegin.txt";
    const char* flnm = "inp.txt";

    filedata fldt = {.flnm = flnm};

    rdfrmfl(&fldt);

    printf("default Onegin:\n");
    printArr(fldt.prsdbffr, fldt.nlns);

    qsort(fldt.prsdbffr, (size_t) fldt.nlns, sizeof(fldt.prsdbffr[0]), strcmpfrmstrstrttostrend);
    printf("First cmp Onegin:\n");
    printArr(fldt.prsdbffr, fldt.nlns);

    myqsort(fldt.prsdbffr, sizeof(fldt.prsdbffr[0]), sizeof(fldt.prsdbffr[0]) * (size_t) fldt.nlns, scmpfrmstrendtostrstrt);
    printf("Second cmp Onegin:\n");
    printArr(fldt.prsdbffr, fldt.nlns);

    qsort(fldt.prsdbffr, (size_t) fldt.nlns, sizeof(fldt.prsdbffr[0]), ptrcmp);
    printf("\nAgain default Onegin:\n");
    printArr(fldt.prsdbffr, fldt.nlns);


    free(fldt.rdbffr);
    free(fldt.prsdbffr);
}
