/*traversing an array means accessing each and every*/
/*element of the array for a specific purpose*/

/*find duplicate number*/

#include <stdio.h>

#define ARRAYSIZE 10

int main()
{
    int array[ARRAYSIZE], i, n, j;
    printf("\n Enter the size of the array: ");
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        printf("\n array[%d] = ", i);
        scanf("%d", &array[i]);
    }
    for (i = 0; i < n - 1; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (array[i] == array[j])
            {
                printf("\n Duplicated numbers at locations %d and %d", i, j);
                return 0;
            }
        }
    }
    printf("\n Duplicated not found");
    return 0;
}
