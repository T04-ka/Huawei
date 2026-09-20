#ifndef CMPRATORS_H
#define CMPRATORS_H


//-------------------------------------------------------------------------------------
/// Compares two strings lexicographically.
///
/// @param s1 Pointer to the first string.
/// @param s2 Pointer to the second string.
/// @return An integer less than, equal to, or greater than zero if the first string is found,
///         respectively, to be less than, to match, or be greater than the second string.
///
/// @note Skipes non-alphanumeric characters.
///
//-------------------------------------------------------------------------------------
int scmpv1(void *s1, void *s2);


#endif
