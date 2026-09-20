#include "cmprators.h"

#include <string.h>
#include <ctype.h>

// 1. строки с начала (зам болшие на малень и игнор все что не букв)
// 2. тоже самое с конца
// 3. Распечатать изначальный буффер

//-------------------------------------------------------------------------------------
int scmpv1(void *s1ptr, void *s2ptr){

    const char *s1 = *(const char **) s1ptr;
    const char *s2 = *(const char **) s2ptr;


    int d = 0;

    for (; *s2 != 0 && *s1 != 0; ){

        if (!isalpha(*s1)) {

            s1++;
            continue;
        }

        if (!isalpha(*s2)) {

            s2++;
            continue;
        }

        d = tolower(*s1++) - tolower(*s2++);

        if (d != 0) {

            return d;
        }
    }

    while (!isalpha(*s2) && *s2 != 0) {

        s2++;
    }

    while (!isalpha(*s1) && *s1 != 0) {

        s1++;
    }

    d = tolower(*s1) - tolower(*s2);

    return d;
}


//-------------------------------------------------------------------------------------
