/*return the position at which a string contains other string*/

#include <stdio.h>
#include <string.h>

int main()
{
    char src[100], str[20];
    int i, j, k, src_length, str_length, pos = -1;

    printf("\n Enter the source string: ");
    fgets(src, sizeof(src), stdin);

    printf("\n Enter the string to match in the source string: ");
    fgets(str, sizeof(str), stdin);

    src_length = strlen(src) - 1;
    str_length = strlen(str) - 1;


    for (i = 0; i < src_length; i++)
    {
        j = i;
        k = 0;
        while (src[j] == str[k] && src[j] != '\0' && src[j] != '\n')
        {
            j++;
            k++;
        }
        if (k == str_length)
        {
            pos = i + 1;
            break;
        }
    }

    printf("\n The source string contains the string to match at position: %d", pos);
    return 0;
}
