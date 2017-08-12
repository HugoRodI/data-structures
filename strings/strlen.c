/*calculates the length of a string*/

#include <stdio.h>

int main()
{
    char str[100];
    int i, length = 0;
    char * pstr;
    pstr = str;
    printf("\n Enter the string: ");
    gets(str);
    while(*pstr++ != '\0')
        length += 1;
    printf("\n The length of the string is: %d", length);
    return 0;
}
