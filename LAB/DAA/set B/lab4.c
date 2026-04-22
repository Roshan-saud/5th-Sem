#include <stdio.h>

struct Job {
    int id, deadline, profit;
};

void sort(struct Job jobs[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (jobs[j].profit < jobs[j+1].profit) {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;

    // Example Input:
    // n = 4
    // deadlines = 2 1 2 1
    // profits   = 100 19 27 25
    // (IDs will be automatically assigned as J1, J2, J3, J4)

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    printf("Enter deadlines:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &jobs[i].deadline);
        jobs[i].id = i + 1;   // Auto assign ID
    }

    printf("Enter profits:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &jobs[i].profit);
    }

    sort(jobs, n);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    int slot[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Selected Jobs: ");
    for (int i = 0; i < maxDeadline; i++)
        if (slot[i] != -1)
            printf("J%d ", slot[i]);

    printf("\nTotal Profit = %d\n", totalProfit);

    return 0;
}






// #include <stdio.h>

// struct Job {
//     int id, deadline, profit;
// };

// void sort(struct Job jobs[], int n) {
//     for (int i = 0; i < n-1; i++) {
//         for (int j = 0; j < n-i-1; j++) {
//             if (jobs[j].profit < jobs[j+1].profit) {
//                 struct Job temp = jobs[j];
//                 jobs[j] = jobs[j+1];
//                 jobs[j+1] = temp;
//             }
//         }
//     }
// }

// int main() {
//     int n;

//     // Example Input:
//     // n = 4
//     // Job details:
//     // ID Deadline Profit
//     // 1   2        100
//     // 2   1        19
//     // 3   2        27
//     // 4   1        25

//     printf("Enter number of jobs: ");
//     scanf("%d", &n);

//     struct Job jobs[n];

//     printf("Enter job details (id deadline profit):\n");
//     for (int i = 0; i < n; i++)
//         scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);

//     sort(jobs, n);

//     int maxDeadline = 0;
//     for (int i = 0; i < n; i++)
//         if (jobs[i].deadline > maxDeadline)
//             maxDeadline = jobs[i].deadline;

//     int slot[maxDeadline];
//     for (int i = 0; i < maxDeadline; i++)
//         slot[i] = -1;

//     int totalProfit = 0;

//     for (int i = 0; i < n; i++) {
//         for (int j = jobs[i].deadline - 1; j >= 0; j--) {
//             if (slot[j] == -1) {
//                 slot[j] = jobs[i].id;
//                 totalProfit += jobs[i].profit;
//                 break;
//             }
//         }
//     }

//     printf("Selected Jobs: ");
//     for (int i = 0; i < maxDeadline; i++)
//         if (slot[i] != -1)
//             printf("J%d ", slot[i]);

//     printf("\nTotal Profit = %d\n", totalProfit);

//     return 0;
// }