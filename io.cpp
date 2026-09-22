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
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//TODO: сделать readfilesize (28-32)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//-------------------------------------------------------------------------------------
void rdfrmfl(struct filedata* fldt){

    //read
    fldt -> sz = rdflsz(fldt -> flnm);
    fldt -> rdbffr = (char*) calloc(fldt -> sz + 1, 1);

    FILE* file = fopen(fldt -> flnm, "r");
    fread(fldt -> rdbffr, sizeof(char), fldt -> sz, file);
    fclose(file);

    //TODO: сделать тдельную функцию для парсера
    //parse
    //void parsedata(struct filedata* filedata);
    char* rbuf = fldt -> rdbffr;

    fldt -> nlns = chrncnt(rbuf, '\n', fldt -> sz);

    const char* *prsdbffr = (const char**) calloc((size_t) fldt -> nlns, sizeof(char*));
    const char* *prsdbffrptr = prsdbffr;

    const char* prevptr = rbuf;

    for (size_t i = 0; i < fldt -> sz; i++){

        if (rbuf[i] == '\n'){

            rbuf[i] = '\0';
            *(prsdbffrptr++) = prevptr;
            prevptr = rbuf + i + 1;
            //prevptr = *prsdbffrptr;
        }
    }

    fldt -> prsdbffr = prsdbffr;
}


//-------------------------------------------------------------------------------------
