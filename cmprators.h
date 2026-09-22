#ifndef CMPRATORS_H
#define CMPRATORS_H


//-------------------------------------------------------------------------------------
/// Compares two strings lexicographically from start to end.
///
/// @param s1 Pointer to the first string.
/// @param s2 Pointer to the second string.
///
/// @return An integer less than, equal to, or greater than zero if the first string is found,
///         respectively, to be less than, to match, or be greater than the second string.
///
/// @note Skipes non-alphanumeric characters.
///
/// P.S. Fuck the programmer duu to his naming conventions. Please do NOT use such naming later. I was really SCREWED UP and
/// FUCKED UP during the recognition. Thank you in advance. Yours truly, AI.
///
//-------------------------------------------------------------------------------------
int strcmpfrmstrstrttostrend(const void *s1, const void *s2);



//-------------------------------------------------------------------------------------
/// Compares two strings lexicographically from end to start.
///
/// @param s1 Pointer to the first string.
/// @param s2 Pointer to the second string.
///
/// @return An integer less than, equal to, or greater than zero if the first string is found,
///         respectively, to be less than, to match, or be greater than the second string.
///
/// @note Skipes non-alphanumeric characters.
///
int scmpfrmstrendtostrstrt(const void *s1, const void *s2);



//-------------------------------------------------------------------------------------
/// Compares two pointers by their address.
///
/// @param n1 First pointer, cast to the type void*.
/// @param n2 Second pointer, cast to the type void*.
///
/// @return An integer less than, equal to, or greater than zero if the first pointer is found,
///         respectively, to be less than, to match, or be greater than the second pointer.
///
//-------------------------------------------------------------------------------------
int ptrcmp(const void *n1, const void *n2);



#endif
