#include "strfuncs.h"

#include <sys/stat.h>
#include <stdlib.h>


//-------------------------------------------------------------------------------------
int chrncnt(char* buf, char smpl, size_t size){

    int cnt = 0;

    for (size_t i = 0; i < size; i++){

        if (buf[i] == smpl){

            cnt++;
        }
    }

    return cnt;
}

#include <assert.h>

//-------------------------------------------------------------------------------------
long long rdflsz(FILE* fl){

    struct stat statdata = {};
    int err = fstat(fileno(fl), &statdata);

    return (!err) ? statdata.st_size : -1;
}


//-------------------------------------------------------------------------------------
void prsdata(struct filedata* fldt){

    char* rbuf = fldt -> rdbffr;

    fldt -> nlns = chrncnt(rbuf, '\n', fldt -> sz);

    string *prsdbffr = (string*) calloc((size_t) fldt -> nlns, sizeof(struct string));
    string *prsdbffrptr = prsdbffr;

    const char* prevptr = rbuf;

    for (size_t i = 0; i < fldt -> sz; i++){

        if (rbuf[i] == '\n'){

            rbuf[i] = '\0';
            prsdbffrptr -> str = prevptr;
            prsdbffrptr -> len = (size_t) (rbuf + i + 1 - prevptr);
            prevptr = rbuf + i + 1;
            prsdbffrptr++;
            //prevptr = *prsdbffrptr;
        }
    }

    fldt -> prsdbffr = prsdbffr;
}


//-------------------------------------------------------------------------------------
#define fldt_ fldt ->

void filedatastrdestr(struct filedata* fldt){

    fldt_ fl = NULL;
    fldt_ sz = -1;
    fldt_ nlns = -1;
    free(fldt_ rdbffr);
    free(fldt_ prsdbffr);
}

#undef fldt_


//-------------------------------------------------------------------------------------
int ioflnmsprs(int argc, char** argv, struct io_data* ionm){

    if (argc == 3){

        ionm -> inp = argv[1];
        ionm -> out = argv[2];
        return 0;
    }

    if (argc == 2){

        ionm -> inp = argv[1];
        return 0;
    }

    return -1;
}


//-------------------------------------------------------------------------------------
