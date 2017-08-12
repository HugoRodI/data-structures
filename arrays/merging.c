/*merging two arrays into a third array*/

#include <stdio.h>

#define ARRAYSIZE 10

int main()
{
    int array1[ARRAYSIZE], array2[ARRAYSIZE], array3[2*ARRAYSIZE], i, n1, n2, n3;
    printf("\n Enter the size of the array1: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; ++i)
    {
        printf("\n array1[%d] = ", i);
        scanf("%d", &array1[i]);
    }
    printf("\n Enter the size of the array2: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; ++i)
    {
        printf("\n array2[%d] = ", i);
        scanf("%d", &array2[i]);
    }
    n3 = n1 + n2;
    for (i = 0; i < n1; i++)
        array3[i] = array1[i];
    printf("%d", i);
    for ( ; i < n1 + n2; i++)
        array3[i] = array2[i - n1];
    for (i = 0; i < n3; i++)
        printf("\n array3[%d] = %d", i, array3[i]);
    return 0;
}
