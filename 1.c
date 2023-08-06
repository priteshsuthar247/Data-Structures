#include <stdio.h>
#include <stdlib.h>
int top;
int insert(int arr[])
{
    int index;
    if (top==10)
    {
        printf("\nArray Overflow\n");
        return top;
    }
    re:
    printf("\nEnter index value: ");
    scanf("%d",&index);
    if (top<index)
    {
        printf("Enter a value >= %d\n",top);
        goto re;
    }
    else
    {
        for (int i = top-1; i >= index; i--)
        {
            arr[i+1]=arr[i];
        }
    }
    printf("Enter new value for index %d: ",index);
    scanf("%d",&arr[index]);
    printf("\n");
    return top=top+1;
}
void search(int arr[])
{
    int i,x,n=0;
    printf("\nSerach : ");
    scanf("%d",&x);
    for (int i = 0; i < top; i++)
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
    printf("\n");
}
int delete(int arr[])
{
    int s;
    re:
    printf("\nDelete value at index: ");
    scanf("%d",&s);
    if (top-1<s)
    {
        printf("Enter a value lesser than %d\n",top);
        goto re;
    }
    else
    {
        for (int i = s; i < top; i++)
        {
            arr[i]=arr[i+1];
        }
    }
    printf("\n");
    return top=top-1;
}
void display(int arr[])
{
    printf("\n");
    for (int i = 0; i < top; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[10],choice;
    printf("Enter: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&arr[i]);
        top = arr[i];
    }
    restart:
    printf("\nPress 1 to Insert an element \n");
    printf("Press 2 to Search an element \n");
    printf("Press 3 to Delete an element\n");
    printf("Press 4 to Display\n");
    printf("Press 5 to Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        insert(arr);
        goto restart;
        break;
    case 2 :
        search(arr);
        goto restart;
        break;
    case 3:
        delete(arr);
        goto restart;
        break;
    case 4:
        display(arr);
        goto restart;
        break;
    case 5:
        printf("Exit.\n");
        break;
    default:
        printf("Wrong Choice\n");
        goto restart;
        break;
    }
    system("PAUSE");
    return 0;
}
