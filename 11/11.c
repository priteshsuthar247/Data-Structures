#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[5],low,mid,high,search;
    printf("Enter: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (a[i]<a[j])
            {
                int temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            
        }
    }
    printf("Search: ");
    scanf("%d",&search);
    low = 0, high = 4;
    while (low <= high)
    {
        mid = (low + high)/2;
        if (a[mid] == search)   
        {
            printf("Found: %d\n",a[mid]);
        }
        if (a[mid] < search)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    system("PAUSE");
    return 0;
}