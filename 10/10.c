#include <stdio.h>
#include <stdlib.h>
void display(int arr[])
{
    printf("\nSorted: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bsort(int barr[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (barr[i]<barr[j])  
            {
                int temp;
                temp = barr[i];
                barr[i] = barr[j];
                barr[j] = temp;
            }
        }
    }
}

void merge(int marr[], int mid, int low, int high)
{
    int i, j, k, temp[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (marr[i] < marr[j])
        {
            temp[k] = marr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = marr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = marr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k] = marr[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        marr[i] = temp[i];
    }
}

void msort(int marr[], int low, int high)
{
    int mid; 
    if(low<high)
    {
        mid = (low + high) /2;
        msort(marr, low, mid);
        msort(marr, mid+1, high);
        merge(marr, mid, low, high);
    }
}

int partition(int qarr[], int low, int high)
{
    int pivot = qarr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (qarr[i] <= pivot)
        {
            i++;
        }

        while (qarr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = qarr[i];
            qarr[i] = qarr[j];
            qarr[j] = temp;
        }
    } while (i < j);

    temp = qarr[low];
    qarr[low] = qarr[j];
    qarr[j] = temp;
    return j;
}

void qusort(int qarr[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(qarr, low, high); 
        qusort(qarr, low, partitionIndex - 1);
        qusort(qarr, partitionIndex + 1, high);
    }
}
int main()
{
    int arr[5],choice;
    printf("Enter: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&arr[i]);
    }
    restart:
    printf("\nPress 1 for Bubble Sort.\n");
    printf("Press 2 for Merge Sort.\n");
    printf("Press 3 for Quick Sort.\n");
    printf("Press 4 to Exit.\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        bsort(arr);
        display(arr);
        goto restart;
        break;
    case 2:
        msort(arr,0,4);
        display(arr);
        goto restart;
        break;
    case 3:
        qusort(arr,0,4);
        display(arr);
        goto restart;
        break;    
    case 4:
        printf("Exit.\n");
        break;
    default:
        printf("Wrong Choice.\n");
        goto restart;
    }
    system("PAUSE");
    return 0;
}