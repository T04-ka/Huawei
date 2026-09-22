#ifndef STRFUNCS_H
#define STRFUNCS_H

#include <stdio.h>

//-------------------------------------------------------------------------------------
/// Counts the number of occurrences of a character in a buffer.
///
/// @param[in] buf The buffer to search.
/// @param[in] size The size of the buffer.
/// @param[in] smlp The character to search for.
///
/// @return The number of occurrences of the character.
///
//-------------------------------------------------------------------------------------
int chrncnt(char* line, char smpl, size_t size);



//-------------------------------------------------------------------------------------
/// Returns the size of the file in bytes
///
/// @param flnm Path to the fil
///
/// @return Size of the file in bytes
///
//-------------------------------------------------------------------------------------
size_t rdflsz(const char* flnm);



//-------------------------------------------------------------------------------------
/// Parses the data in the buffer into a buffer of pointers to lines.
///
/// @param fldt The file data structure.
///
/// @note The previous data of the buffer to parse will be removed.
///
//-------------------------------------------------------------------------------------
void prsdata(struct filedata* fldt);



#endif
