#include "cmprators.h"

#include <string.h>
#include <ctype.h>

// 1. строки с начала (зам болшие на малень и игнор все что не букв)
// 2. тоже самое с конца
// 3. Распечатать изначальный буффер
//
// Стоит в яме холм с кулями
// Выйду на холм куль поставлю
//
//-------------------------------------------------------------------------------------
int strcmpfrmstrstrttostrend(const void *s1ptr, const void *s2ptr){

    const char *s1 = *(const char * const*) s1ptr;
    const char *s2 = *(const char * const*) s2ptr;


    int diff = 0;

    for (; *s2 != 0 && *s1 != 0; ){

        if (!isalpha(*s1)) {

            s1++;
            continue;
        }

        if (!isalpha(*s2)) {

            s2++;
            continue;
        }

        diff = tolower(*s1++) - tolower(*s2++);

        if (diff != 0) {

            return diff;
        }
    }

    while (!isalpha(*s2) && *s2 != 0) {

        s2++;
    }

    while (!isalpha(*s1) && *s1 != 0) {

        s1++;
    }

    diff = tolower(*s1) - tolower(*s2);

    return diff;
}


//-------------------------------------------------------------------------------------
int scmpfrmstrendtostrstrt(void *s1ptr, void *s2ptr){

    const char *s1 = *(const char **) s1ptr;
    const char *s2 = *(const char **) s2ptr;

    size_t s1ln = strlen(s1);
    size_t s2ln = strlen(s2);

    int d = 0;

    const char *s1cmpptr = s1 + s1ln - 1;
    const char *s2cmpptr = s2 + s2ln - 1;

    for (; s1cmpptr != s1 && s2cmpptr != s2; ){

        if (!isalpha(*s1cmpptr)) {

            s1cmpptr--;
            continue;
        }

        if (!isalpha(*s2cmpptr)) {

            s2cmpptr--;
            continue;
        }

        d = tolower(*s1cmpptr--) - tolower(*s2cmpptr--);

        if (d != 0) {

            return d;
        }
    }

    while (!isalpha(*s2cmpptr) && s2cmpptr != s2) {

        s2cmpptr--;
    }

    while (!isalpha(*s1cmpptr) && s1cmpptr != s1) {

        s1cmpptr--;
    }

    d = tolower(*s1cmpptr) - tolower(*s2cmpptr);

    return d;
}


//-------------------------------------------------------------------------------------
int ptrcmp(void* n1ptr, void* n2ptr) {

    const char* n1 = *(const char**) n1ptr;
    const char* n2 = *(const char**) n2ptr;

    return (int) (n1 - n2);
}


//-------------------------------------------------------------------------------------
