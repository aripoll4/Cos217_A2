/*--------------------------------------------------------*/
/*
strp.c
Author: Alfred Ripoll 
*/
/*--------------------------------------------------------*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "str.h"

/*--------------------------------------------------------*/


/* Inputs a String pcSrc using a pointer, Returns the long number of the length of the string minus the null character*/
size_t Str_getLength(const char *pcSrc)
{
   const char *pcEnd;
   assert(pcSrc != NULL);
   pcEnd = pcSrc;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - pcSrc);
}

/*Takes an input from a String using a pointer source src, asserts that strings are not null, copies each char and returns it into a destination String dest */
char *Str_copy(char *dest, const char *src) {
   char *pcEnd;
   const char *sEnd = src;
   assert(dest != NULL);
   assert(src != NULL);
   pcEnd = dest;
   while (*sEnd != '\0') {
      *pcEnd = *sEnd;
      sEnd++;
      pcEnd++;
   }
   *pcEnd = '\0';
   return dest;
}

/*Asserts that strings are not null, Appends the input String src to the end of the other input String  dest, returns dest after it has been modified. */
char *Str_concat(char *dest, const char *src) {
   char *destEnd = dest;
   assert (src != NULL);
   assert (dest != NULL);
   while (*destEnd != '\0') {
      destEnd++;
   }
   while(*src != '\0') {
    *destEnd = *src;
    destEnd++;
    src++;
   }
   *destEnd = '\0';
   return dest;

}

/* Compares two Strings character by characer. If first is larger, returns one. If second is larger, returns -1. If equal, returns 0. */
int Str_compare(const char *str1, const char *str2) {
   const char *str1End;
   const char *str2End;

   assert (str1 != NULL);
   assert (str2 != NULL);
   str1End = str1;
   str2End = str2;

   while (*str1End == *str2End) {
      if (*str1End == '\0') {
         return 0;
      } else {
        str1End++;
        str2End++;
      }
      }
      if (*str1End > *str2End) {
         return 1;
      } else {
        return -1;
      }
   
}

/* finds and returns the first occurrence of the subString needle in the Strin haystack. The terminating '\0' characters are not compared.*/
char * Str_search(const char *haystack, const char *needle) {
   const char *haystackEnd = haystack;
   const char *needleEnd = needle;
   assert (haystack != NULL);
   assert (needle != NULL);
   if (*needleEnd == '\0') {
      return (char *)(haystack);
   }
   while (*haystackEnd != '\0') {
      needleEnd = needle;
      while (*needleEnd != '\0' && *haystackEnd == *needleEnd) {
         haystackEnd++;
         needleEnd++;
      }
      if (*needleEnd == '\0') {
         return (char *)(haystackEnd - (needleEnd - needle));
      }
   }
   return NULL;
}
