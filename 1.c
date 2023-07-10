#include<stdio.h>
#include<stdbool.h>
void insert(int arr[])
{
    int index;
    printf("\nEnter index value: ");
    scanf("%d",&index);
    for (int i = 4; i >= index-1; i--)
    {
        arr[i+1]=arr[i];
    }
    printf("Enter new value for index %d: ",index);
    scanf("%d",&arr[index]);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void search(int arr[],bool iused)
{
    int i,x,n=0;
    printf("\nSerach : ");
    scanf("%d",&x);
    if (iused==false)
    {
        for (int i = 0; i < 5; i++)
        {
            if (arr[i]==x)
            {
                printf("Found %d at %d\n",x,i);
                n++;
            }
        }
        if (n==0)
        {
            printf("Unsuccesfull Search");
        }
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            if (arr[i]==x)
            {
                printf("Found %d at %d\n",x,i);
                n++;
            }
        }
        if (n==0)
        {
            printf("Unsuccesfull Search");
        }
    }
    printf("\n");
}
void delete(int arr[],bool iused)
{
    int s;
    printf("\nDelete value at index: ");
    scanf("%d",&s);
    if (iused==false)
    {
        for (int i = s; i < 5; i++)
        {
            arr[i]=arr[i+1];
            arr[i+1]=arr[i]; 
        }
        printf("New : ");
        for (int i = 0; i < 4; i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = s; i < 6; i++)
        {
            arr[i]=arr[i+1];
            arr[i+1]=arr[i]; 
        }
        printf("New : ");
        for (int i = 0; i < 5; i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}
int main()
{
    int arr[10],choice;
    bool iused=false;
    printf("Enter: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&arr[i]);
    }
    restart:
    printf("\nPress 1 to insert an element \n");
    printf("Press 2 to search an element \n");
    printf("Press 3 to delete an element\n");
    printf("Press 4 to Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        insert(arr);
        iused=true;
        goto restart;
        break;
    case 2 :
        search(arr,iused);
        goto restart;
        break;
    case 3:
        delete(arr,iused);
        goto restart;
        break;
    case 4:
        printf("Exit");
        break;
    default:
        printf("Wrong Choice");
        goto restart;
        break;
    }
    return 0;
}
