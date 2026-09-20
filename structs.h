#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>

struct filedata {
    const char* flnm;
    size_t sz;
    int nlns;
    char *rdbffr;
    const char* *prsdbffr;
};

#endif
