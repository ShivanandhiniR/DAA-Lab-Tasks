#include <stdio.h>

#define SIZE 100

int main()
{
    int a[SIZE], hash[SIZE];
    int n, T, i, x, required;

    for (i = 0; i < SIZE; i++)
        hash[i] = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target value: ");
    scanf("%d", &T);

    for (i = 0; i < n; i++)
    {
        x = a[i];
        required = T - x;

        if (required >= 0 && required < SIZE && hash[required] == 1)
        {
            printf("Pair found: %d + %d = %d\n", required, x, T);
            return 0;
        }

        if (x >= 0 && x < SIZE)
            hash[x] = 1;
    }

    printf("No pair found\n");

    return 0;
}
