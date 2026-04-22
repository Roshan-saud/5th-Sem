#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair minMax(int arr[], int low, int high) {
    struct Pair p, left, right;

    if (low == high) {
        p.min = p.max = arr[low];
        return p;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            p.min = arr[low];
            p.max = arr[high];
        } else {
            p.min = arr[high];
            p.max = arr[low];
        }
        return p;
    }

    int mid = (low + high) / 2;

    left = minMax(arr, low, mid);
    right = minMax(arr, mid + 1, high);

    p.min = (left.min < right.min) ? left.min : right.min;
    p.max = (left.max > right.max) ? left.max : right.max;

    return p;
}

int main() {
    int n;

    // Example Input:
    // n = 6
    // array = 3 5 1 8 2 9

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Pair result = minMax(arr, 0, n - 1);

    printf("Minimum = %d\n", result.min);
    printf("Maximum = %d\n", result.max);

    return 0;
}