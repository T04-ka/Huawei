#include "cmprators.h"

#include "structs.h"

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

    const char *s1 = (*(const string *) s1ptr).str;
    const char *s2 = (*(const string *) s2ptr).str;


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


    printf("cpm(%s, %s) = %d\n", s1, s2, diff);
    return diff;
}


//-------------------------------------------------------------------------------------
int scmpfrmstrendtostrstrt(const void *s1ptr, const void *s2ptr){

    const char *s1 = (*(const string *) s1ptr).str;
    const char *s2 = (*(const string *) s2ptr).str;

    size_t s1ln = (*(const string *) s1ptr).len;
    size_t s2ln = (*(const string *) s2ptr).len;

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
int ptrcmp(const void* n1ptr, const void* n2ptr) {

    const char* n1 = *(const char *const *) n1ptr;
    const char* n2 = *(const char *const *) n2ptr;

    return (int) (n1 - n2);
}


//-------------------------------------------------------------------------------------
