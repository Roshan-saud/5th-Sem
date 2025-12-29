// 29 Dec, 09/13


/*
Title: Iterative sorting Algorithm

Objective:
 - To implement Bubble sort and analyze it's complexity
 - To implement Selection sort and analyze it's complexity
 - To implement Insertion sort and analyze it's complexity
*/

#include <stdio.h>
int n, arr[100], opr, i, j, temp;

void insertElement()
{
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void displayElement()
{
    printf("array: ");
    printf("[ ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
     printf("]");
    printf("\n");
}
void bubbleSort()
{
    for (i = 0; i < n-1 ; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if(arr[j]>arr[j+1]){
                temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted successfully \n");
}
void insertionSort()
{
    for(i=1; i<n; i++){
        int key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]= arr[j];
            j = j-1;
        }
        arr[j+1]= key;
    }
    printf("Sorted successfully \n");
}
void selectionSort()
{
    for(i=0; i<n-1; i++){
        int min = i;
        for(j=i+1; j<n; j++){
            if(arr[j]<arr[min])
            min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    printf("Sorted successfully \n");
}

int main()
{
    int opr;
    do{
    printf("\nEnter 1 to insert element\n");
    printf("Enter 2 for display\n");
    printf("Enter 3 for Bubble Sort\n");
    printf("Enter 4 for insertion Sort\n");
    printf("Enter 5 for Selection sort\n");
    printf("Enter 6 for exit\n");
    printf("Enter the operation(1-6): ");
    scanf("%d", &opr);
    switch (opr)
    {
    case 1:
        insertElement();
        break;
    case 2:
        displayElement();
        break;
    case 3:
        bubbleSort();
        break;
    case 4:
        insertionSort();
        break;
    case 5:
        selectionSort();
        break;
    case 6:
        printf("Exit successfully\n");
        break;
    default:
        printf("Please Enter a valid operation\n");
        break;
    }
    }while(opr!=6);
}

