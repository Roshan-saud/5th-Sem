#include <stdio.h>

struct Item {
    int weight, profit;
    float ratio;
};

void sort(struct Item items[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (items[j].ratio < items[j+1].ratio) {
                struct Item temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;

    // Example Input:
    // n = 3
    // weights = 10 20 30
    // profits = 60 100 120
    // capacity = 50

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &items[i].weight);

    printf("Enter profits:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &items[i].profit);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n; i++)
        items[i].ratio = (float)items[i].profit / items[i].weight;

    sort(items, n);

    float totalProfit = 0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        } else {
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}