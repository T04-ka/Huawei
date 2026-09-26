#include "io.h"

#include "strfuncs.h"
#include <cstddef>
#include <cstdio>
#include <assert.h>

//-------------------------------------------------------------------------------------
int opnfls(FILE** inp, FILE** out, struct io_data io_data){

    *inp = fopen(io_data.inp, "r");
    *out = fopen(io_data.out, "w");

    if (*out == NULL) {

        *out = stdout;
    }
    if (*inp == NULL){

        return 1;
    }

    return 0;
}


//-------------------------------------------------------------------------------------
int clsfls(FILE* inp, FILE* out){

    if (inp == NULL){

        return 1;
    }

    int errout = 0;
    if (out != stdout){

        errout = fclose(out);
    }

    int errinp = fclose(inp);
    //printf("inp = %d, out = %d\n", errinp, errout);
    if (errinp || errout){

        return 1;
    }

    return 0;
}


//-------------------------------------------------------------------------------------
void printArr(string arr[], int nlines, FILE* fl){


    //printf("nlines = %d\n", nlines);
    for (int i = 0; i < nlines; i++){

        fprintf(fl, "|%s|\n", arr[i].str);
    }

    getchar();
}

//TODO: сделть if (файл непрочитан) error
//-------------------------------------------------------------------------------------
#define fldt_ fldt ->

int rdfrmfl(struct filedata* fldt){

    long long sz = rdflsz(fldt_ fl);

    if (sz == -1){

        return 1;
    }

    fldt_ sz = (size_t) sz;
    fldt_ rdbffr = (char*) calloc(fldt_ sz + 1, 1);

    fread(fldt_ rdbffr, sizeof(char), fldt_ sz, fldt_ fl);

    /*
    int fldiscr = open(fldt_ flnm, 1, "r");
    read(fldt_ rdbffr, sizeof(char), fldt_ sz, fldiscr);
    fclose(file);
    */

    prsdata(fldt);

    return 0;
}

#undef fldt_
//-------------------------------------------------------------------------------------
