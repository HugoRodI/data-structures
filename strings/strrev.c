/*reverse a string*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char str[100];
    int temp, i = 0;
    float length;

    printf("\n Enter a string to reverse: ");
    fgets(str, sizeof(str), stdin);

    length = strlen(str);
    for ( ; i < ceil(length/2.0); i++)
    {
        temp = str[i];
        str[i] = str[(int)length - i - 1];
        str[(int)length - i - 1] = temp;
    }

    printf("%s", str);
    return 0;
}
