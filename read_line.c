
#include<stdio.h>
#include"read_line.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//read_line function
int read_line(char str[], int n) {
int ch, i=0;
while (isspace(ch = getchar()))
;
str[i++] = ch;
while ((ch = getchar()) != '\n') {
if (i < n)
str[i++] = ch;    
}
str[i] = '\0';
return i;
}

