#ifndef IO_H
#define IO_H

#include "structs.h"

#include <stdlib.h>

//-------------------------------------------------------------------------------------
///Prints the contents of an array of strings to the console.
///
/// @param[in] arr The array of strings to print.
/// @param[in] nlines The number of lines in the array.
///
//-------------------------------------------------------------------------------------
void printArr(string arr[], int nlines);



//-------------------------------------------------------------------------------------
/// Reads the contents of a file into a filedata struct.
///
/// @param[in] fldt The filedata struct to read into.
///
//-------------------------------------------------------------------------------------
void rdfrmfl(struct filedata* filedata);



#endif
