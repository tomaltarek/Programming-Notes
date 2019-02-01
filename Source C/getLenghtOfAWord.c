/*
Portions of the work are derived from
'Ihe Standard C Library ', Copyright(c) 1992 by PJ Plauger
published by Prentice-Hall, and are used with permission.


*/


#include <string.h>
#include<stdio.h>

//the below is strlen() type of code, slightly modified
// see how pointers are used to write high performance code.
size_t getLength (const char *s)
{ /* find length of s[] */
const char *sc;
int i=0;
for (sc=s;*sc!='\0';++sc)
    {
        i++;
    }
  return(i);
}



int main(void)
{
    char array[30];
    puts("give a word (not more than 30 characters) :  ");
    scanf("%s",&array);

    int len=getLength(array);
    printf("The length of %s is : %d ",array,len);
}
