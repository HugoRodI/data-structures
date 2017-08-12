/*delete an element of an array at a given position*/

#include <stdio.h>

#define ARRAYSIZE 10

int main()
{
    int array[ARRAYSIZE], i, n, delete_from;
    printf("\n Enter the array size: ");
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }
    printf("\n Enter the place where you can delete from: ");
    scanf("%d", &delete_from);
    for (i = delete_from; i < n - 1;  ++i)
        array[i] = array[i + 1];
    for (i = 0; i < n - 1; ++i)
        printf("\narray[%d] = %d", i, array[i]);
    return 0;
}
