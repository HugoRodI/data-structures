/*inserting means to insert an element in an array. */
/*It can be done at the beginning, middle or end of the array*/

/*insert a number at a given location in an array*/

#include <stdio.h>

#define ARRAYSIZE 10

int main()
{
    int array[ARRAYSIZE], i, j, n, num_to_insert, insert_in;
    printf("\n Enter the size of the array");
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        printf("\n array[%d] = ", i);
        scanf("%d", &array[i]);
    }
    printf("\n Enter the number to be inserted");
    scanf("%d", &num_to_insert);
    printf("\n Enter the position where the number is going to be inserted");
    scanf("%d", &insert_in);
    for (i = n; i > insert_in; --i)
        array[i] = array[i - 1];
    array[insert_in] = num_to_insert;
    for(i = 0; i <= n; ++i)
        printf("\n array[%d] = %d", i, array[i]);
    return 0;
}
