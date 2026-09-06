#include <stdio.h>

void bucketSort(int a[], int n)
{
    int bucket[10][100];
    int count[10] = {0};
    int i, j, k, b;

    for (i = 0; i < n; i++)
    {
        b = a[i] / 10;
        bucket[b][count[b]] = a[i];
        count[b]++;
    }

    for (b = 0; b < 10; b++)
    {
        for (i = 0; i < count[b] - 1; i++)
        {
            for (j = i + 1; j < count[b]; j++)
            {
                if (bucket[b][i] > bucket[b][j])
                {
                    int temp = bucket[b][i];
                    bucket[b][i] = bucket[b][j];
                    bucket[b][j] = temp;
                }
            }
        }
    }

    k = 0;

    for (b = 0; b < 10; b++)
    {
        for (i = 0; i < count[b]; i++)
        {
            a[k] = bucket[b][i];
            k++;
        }
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bucketSort(a, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
