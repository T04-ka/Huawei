#include "strfuncs.h"

#include "structs.h"
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


//-------------------------------------------------------------------------------------
size_t rdflsz(const char* flnm){

    struct stat statdata = {};
    stat(flnm, &statdata);
    return (size_t) statdata.st_size;
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
