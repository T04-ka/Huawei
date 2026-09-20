#include "strfuncs.h"


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
