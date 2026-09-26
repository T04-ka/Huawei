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

//TODO: сделть if (файл непрочитан) error
//-------------------------------------------------------------------------------------
#define fldt_ fldt ->

int rdfrmfl(struct filedata* fldt){

    long long sz = rdflsz(fldt_ flnm);

    if (sz == -1){

        return 1;
    }

    fldt_ sz = (size_t) sz;
    fldt_ rdbffr = (char*) calloc(fldt_ sz + 1, 1);

    FILE* file = fopen(fldt_ flnm, "r");
    fread(fldt_ rdbffr, sizeof(char), fldt_ sz, file);
    fclose(file);

    prsdata(fldt);

    return 0;
}

#undef fldt_
//-------------------------------------------------------------------------------------
