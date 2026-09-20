#ifndef STRFUNCS_H
#define STRFUNCS_H

#include <stdio.h>


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



#endif
