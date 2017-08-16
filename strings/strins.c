/*insert string in another string at a given position*/

#include <stdio.h>
#include <string.h>

int main()
{
    char source[100], strins[10], temp[100];
    int pos, src_length, strins_length;

    printf("\n Enter the source string: ");
    fgets(source, sizeof(source), stdin);

    printf("\n Enter the string to be inserted: ");
    fgets(strins, sizeof(strins), stdin);

    printf("\n Enter the position at which the string is going to be inserted: ");
    scanf("%d", &pos);

    src_length = strlen(source) - 1;
    strins_length = strlen(strins) - 1;

    for (int i = pos - 1; i < src_length; i++)
        temp[i - pos + 1] = source[i];

    for (int i = pos - 1; i < strins_length + pos - 1; i++)
        if (strins[i - pos + 1] != '\0')
            source[i] = strins[i - pos + 1];
    for (int i = 0; i < strlen(temp); i++)
        source[i + pos - 1 + strins_length] = temp[i];

    printf("\n The new string is: %s", source);
    return 0;
}
