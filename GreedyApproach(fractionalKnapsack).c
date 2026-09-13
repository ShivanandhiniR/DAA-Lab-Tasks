#include <stdio.h>

int main() {
    int n, i, j;
    float weight[100], profit[100], ratio[100];
    float capacity, totalProfit = 0;
    float temp;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of the items:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &weight[i]);

    printf("Enter the profits of the items:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &profit[i]);

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (capacity >= weight[i]) {
            capacity -= weight[i];
            totalProfit += profit[i];
        } else {
            totalProfit += ratio[i] * capacity;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
