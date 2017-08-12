/*appends source string to destination string*/

#include <stdio.h>

int main()
{
    char srcstr[100], deststr[100];
    char *psrcstr, *pdeststr;

    printf("\n Enter source string: ");
    gets(srcstr);
    printf("\n Enter destination string: ");
    gets(deststr);

    pdeststr = deststr;
    psrcstr = srcstr;

    while(*pdeststr)
        pdeststr++;
    while(*pdeststr++ = *psrcstr++)
        ;

    printf("%s", deststr);
    return 0;
}
