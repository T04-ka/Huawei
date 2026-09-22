#include "io.h"

#include "strfuncs.h"
#include "structs.h"



//-------------------------------------------------------------------------------------
void printArr(const char* arr[], int nlines){


    //printf("nlines = %d\n", nlines);
    for (int i = 0; i < nlines; i++){

        printf("|%s|\n", arr[i]);
    }

    getchar();
}


//-------------------------------------------------------------------------------------
void rdfrmfl(struct filedata* fldt){

    //read
    fldt -> sz = rdflsz(fldt -> flnm);
    fldt -> rdbffr = (char*) calloc(fldt -> sz + 1, 1);

    FILE* file = fopen(fldt -> flnm, "r");
    fread(fldt -> rdbffr, sizeof(char), fldt -> sz, file);
    fclose(file);

    prsdata(fldt);

}


//-------------------------------------------------------------------------------------
