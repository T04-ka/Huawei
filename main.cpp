#include "io.h"
#include "strfuncs.h"
#include "structs.h"
#include "qsort.h"
#include "cmprators.h"

#include <cstdlib>
#include <stdlib.h>

// TODO сделать argc argv c именами файлов DONE
// carambaswitcher!!
// TODO: сделать вывод в файл DONE
// TODO: сделать отдельную функцию для free всего с уничтоженем всех данных DONE

#define CHCKERR(A)  if (err) {                                      \
                                                                    \
                        fprintf(outfl, A);                          \
                        return 1;                                   \
                    }

#define PRINTARR    printArr(fldt.prsdbffr, fldt.nlns, outfl)
#include <assert.h>

int main(int argc, char** argv){

    struct io_data io_data = {};
    FILE* outfl = stdout;

    int err = ioflnmsprs(argc, argv, &io_data);
    CHCKERR("Wrong parametrs number.\n");

    //const char * flnm = "ASPushkinEvgeniyOnegin.txt";
    //const char* flnm = "inp.txt";

    filedata fldt = {};

    err = opnfls(&fldt.fl, &outfl, io_data);
    CHCKERR("Cannot open file.\n");

    err = rdfrmfl(&fldt);
    CHCKERR("Cannot find input file.\n");

    fprintf(outfl, "Default Onegin:\n");
    PRINTARR;

    qsort(fldt.prsdbffr, (size_t) fldt.nlns, sizeof(fldt.prsdbffr[0]), strcmpfrmstrstrttostrend);
    fprintf(outfl, "\nFirst cmp Onegin:\n");
    PRINTARR;

    myqsort(fldt.prsdbffr, sizeof(fldt.prsdbffr[0]), sizeof(fldt.prsdbffr[0]) * (size_t) fldt.nlns, scmpfrmstrendtostrstrt);
    fprintf(outfl, "\nSecond cmp Onegin:\n");
    PRINTARR;

    qsort(fldt.prsdbffr, (size_t) fldt.nlns, sizeof(fldt.prsdbffr[0]), ptrcmp);
    fprintf(outfl, "\nAgain default Onegin:\n");
    PRINTARR;

    err = clsfls(fldt.fl, outfl);
    if (err) {

        fprintf(outfl, "Cannot close file.\n");
    }

    filedatastrdestr(&fldt);

    return err;
}

#undef PRINTARR
#undef CHCKERR
