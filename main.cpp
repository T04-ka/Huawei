#include "io.h"
#include "strfuncs.h"
#include "structs.h"
#include "qsort.h"
#include "cmprators.h"

#include <cstdlib>
#include <stdlib.h>

// TODO сделать argc argv c именами файлов DONE
// carambaswitcher!!
// TODO: сделать свой вывод буффера через puts со скипом \0
// TODO: сделать отдельную функцию для free всего с уничтоженем всех данных DONE

#define CHCKERR(A)  if (err) {                                      \
                                                                    \
                        printf(A);                                  \
                        return 1;                                   \
                    }

int main(int argc, char** argv){

    struct io_data io_data = {};

    int err = ioflnmsprs(argc, argv, &io_data);
    CHCKERR("Wrong parametrs number.\n");

    //const char * flnm = "ASPushkinEvgeniyOnegin.txt";
    //const char* flnm = "inp.txt";

    filedata fldt = {.flnm = io_data.inp};


    err = rdfrmfl(&fldt);
    CHCKERR("Cannot find input file.\n");

    printf("Default Onegin:\n");
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

    filedatastrdestr(&fldt);
}
