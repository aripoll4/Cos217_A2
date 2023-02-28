/*--------------------------------------------*/
/*
str.h
Author: Alfred Ripoll
*/
/*--------------------------------------------*/

#ifndef STR_INCLUDED
#define STR_INCLUDED
#include <stddef.h>

/*Calculates the length of input String and returns the length. Asserts that String is not null */
size_t Str_getLength(const char *pcSrc);

/* Copies input String src onto other input String dest, asserts that Strings are not null, returns new dest String */
char *Str_copy(char *dest, const char *src);

/*Appends the input String src to the end of the other input String dest, asserts that string are not null, returns dest after it has been modified. */
char *Str_concat(char *dest, const char *src);

/* Asserts that strings are not null, Compares two Strings character by characer. If first is larger, returns one. If second is larger, returns -1. If equal, returns 0. */
int Str_compare(const char *str1, const char *str2);

/* Asserts that strings are not null, finds the first occurrence of the subString needle in the Strin haystack. The terminating '\0' characters are not compared.*/
char * Str_search(const char *haystack, const char *needle);

#endif
