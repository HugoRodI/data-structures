/*Convert a string to upper case*/

#include <stdio.h>

int main()
{
    char str[100], upstr[100];
    int i = 0;
    printf("\n Enter the string to convert to upper case:");
    gets(str);
    while(str[i])
    {
        if(str[i] >= 'a' && str[i] <= 'z')
            upstr[i] = str[i] - 32;
        else
            upstr[i] = str[i];
    i++;
    }
    upstr[i] = '\0';
    puts(upstr);
    return 0;
}
