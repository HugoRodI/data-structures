/*subtracts one string from other string*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100];
    char * pstr;
    char substr[100];
    int substr_length, pos_first_char;

    printf("\n Enter the source string: ");
    fgets(str, sizeof(str), stdin);

    printf("\n Enter the position of the first character of the substring: ");
    scanf("%d", &pos_first_char);

    printf("\n Enter the length of the substring: ");
    scanf("%d", &substr_length);

    pstr = str + (pos_first_char);
    while(substr_length-- > 0)
        pstr++;
    *pstr = '\0';
    int n = 0;
    while(substr[n++] = *pstr++)
        ;
    printf("%c", substr);
    return 0;
}
