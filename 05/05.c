#include <stdio.h>
#include <stdlib.h>
int queue[10], front,rear,flag;
void insert()
{
    if (rear==4)
    {
        printf("\nQueue Overflow.\n");
    }
    else if (front&&rear==-1)
    {
        int temp;
        front++;
        rear++;
        printf("Enter digit: ");
        scanf("%d",&temp);
        printf("Remaining entries left in Queue %d",4-rear);
        queue[front]=queue[rear]=temp;
        printf("\nf%d,r%d,qf%d,qr%d",front,rear,queue[front],queue[rear]);
    }
    else
    {
        rear++;
        printf("Enter digit: ");
        scanf("%d",&queue[rear]);
        printf("Remaining entries left in Queue: %d",4-rear);
        printf("\nf%d,r%d,qf%d,qr%d",front,rear,queue[front],queue[rear]);
    }
}
void delete()
{
    if (front==-1)
    {
        printf("\nQueue Underflow.\n");
    }
    else if (front==rear)
    {
        printf("\n%d is deleted.\n",queue[front]);
        queue[front]=0;
        printf("Elements in the Queue: %d",rear-front);
        printf("\nf%d,r%d,qf%d,qr%d",front,rear,queue[front],queue[rear]);
        front=rear=-1;
    }
    else
    {
        printf("\n%d is deleted.\n",queue[front]);
        queue[front]=0;
        printf("Elements in the Queue: %d",rear-front);
        front++;
        printf("\nf%d,r%d,qf%d,qr%d",front,rear,queue[front],queue[rear]);
    }
}
void display()
{
    if (rear&&front==-1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        for (int i = front; i <=rear; i++)
        {
            printf("%d ",queue[i]);
        }
    }
}
int main()
{
    int choice;
    front=rear=-1;
    restart:
    printf("\nPress 1 to Insert.\n");
    printf("Press 2 to Delete.\n");
    printf("Press 3 to Display.\n");
    printf("Press 4 to Exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        insert();
        goto restart;
        break;
    case 2:
        delete();
        goto restart;
        break;
    case 3:
        display();
        goto restart;
        break;
    case 4:
        printf("Exit.\n");
        break;
    default:
        printf("Wrong Choice.\n");
        goto restart;
        break;
    }
    system("PAUSE");
    return 0;
}