/*Delete substring from main string*/

#include <stdio.h>
#include <string.h>

int main()
{

    char str[100], new_string[100];
    int i, j, pos, length;

    printf("\n Enter the source string: ");
    fgets(str, sizeof(str), stdin);

    printf("\n Enter the position to start deleting: ");
    scanf("%d", &pos);

    pos--;

    printf("\n Enter the length to delete: ");
    scanf("%d", &length);

    for (i = 0, j = 0; i < strlen(str) - 1; i++)
    {
        if (i < pos || i > pos + length - 1)
        {
                new_string[j] = str[i];
                j++;
        }
    }
    new_string[j] = '\0';
    printf("\n The new string is %s", new_string);


    return 0;
}
