#include "io.h"

#include "strfuncs.h"

//-------------------------------------------------------------------------------------
void printArr(string arr[], int nlines){


    //printf("nlines = %d\n", nlines);
    for (int i = 0; i < nlines; i++){

        printf("|%s|\n", arr[i].str);
    }

    getchar();
}


//-------------------------------------------------------------------------------------
#define fldt_ fldt ->

void rdfrmfl(struct filedata* fldt){

    fldt_ sz = rdflsz(fldt_ flnm);
    fldt_ rdbffr = (char*) calloc(fldt_ sz + 1, 1);

    FILE* file = fopen(fldt_ flnm, "r");
    fread(fldt_ rdbffr, sizeof(char), fldt_ sz, file);
    fclose(file);

    prsdata(fldt);

}

#undef fldt_
//-------------------------------------------------------------------------------------
