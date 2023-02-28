/*--------------------------------------------------------*/
/*
stra.c
Author: Alfred Ripoll 

Implements the string handling functions of Str_getLength, Str_copy, Str_concat, Str_compare, and Str_search using arrays

*/
/*--------------------------------------------------------*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "str.h"

/*--------------------------------------------------------*/

/* Inputs a character array, Returns the long number of the length of the string minus the null character*/
size_t Str_getLength(const char pcSrc[]) {
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

/*Takes an input from a character array source src, copies each char and returns it into another character array destination d */
char *Str_copy(char dest[], const char src[]) {
   size_t uLength = 0;
   assert(dest != NULL);
   assert(src != NULL);
   while (src[uLength] != '\0') {
      dest[uLength] = src[uLength];
      uLength++;
   }
   dest[uLength] = '\0';
   return dest;
}

/* Appends the input char array named src to the end of the other input char array named dest, returns dest after it has been modified. */
char *Str_concat(char dest[], const char src[]) {
  size_t dlen = 0;
  size_t slen = 0;
  assert(dest != NULL);
  assert(src != NULL);
  while (dest[dlen] != '\0') {
   dlen++;
  }
  while (src[slen] != '\0') {
   dest[dlen] = src[slen];
   dlen++;
   slen++;
  }
  dest[dlen] = '\0';
  return dest;
}

/* Compares two char arrays character by characer. If first is larger, returns one. If second is larger, returns -1. If equal, returns 0. */
int Str_compare(const char str1[], const char str2[]) {
   size_t i = 0;
   assert (str1 != NULL);
   assert (str2 != NULL);
   while(str1[i] != '\0' && str2[i] != '\0') {
      if (str1[i] > str2[i]) {
         return 1;
      }
      else if (str1[i] < str2[i]) {
         return -1;
      }
      else {
      i++;
      }
   }
   return 0;
}

/* finds the first occurrence of the char array needle in the char array haystack. The terminating '\0' characters are not compared.*/
char* Str_search(const char haystack[], const char needle[]) {
size_t i = 0;
size_t j = 0;
assert (haystack != NULL);
assert (needle != NULL);
if (needle[0] == '\0') {
   return (char*)(haystack);
}
while (haystack[i] != '\0') {
   j = 0;
   while (needle[j] != '\0') {
      if (haystack[i + j] == needle[j]) {
         j++;
         if (needle[j + 1] == '\0') {
            return (char*) &haystack[i];
         }
      }
      else {
         break;
      }
   }
   i++;
}
return NULL;
}
