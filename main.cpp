#include "io.h"
#include "structs.h"
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

    //sortprint("First cmp Onegin", strcmpfrsmstrstrttostrend);

    qsort(fldt.prsdbffr, (size_t) fldt.nlns, sizeof(fldt.prsdbffr[0]), strcmpfrmstrstrttostrend);
    printf("First cmp Onegin:\n");
    printArr(fldt.prsdbffr, fldt.nlns);

    sqsort(fldt.prsdbffr, sizeof(fldt.prsdbffr[0]) * (size_t) fldt.nlns, sizeof(fldt.prsdbffr[0]), scmpfrmstrendtostrstrt);
    printf("Second cmp Onegin:\n");
    printArr(fldt.prsdbffr, fldt.nlns);

    qsort(fldt.prsdbffr, (size_t) fldt.nlns, sizeof(fldt.prsdbffr[0]), ptrcmp);
    printf("\nAgain default Onegin:\n");
    printArr(fldt.prsdbffr, fldt.nlns);


    free(fldt.rdbffr);
    free(fldt.prsdbffr);
}
