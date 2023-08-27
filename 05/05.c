#include <stdio.h>
#include <stdlib.h>
int cqueue[10], cfront,crear;
int squeue[10], sfront,srear;
void senqueue()
{
    if (srear==4)
    {
        printf("\nQueue Overflow.\n");
    }
    else if (sfront&&srear==-1)
    {
        int temp;
        sfront++;
        srear++;
        printf("Enter digit: ");
        scanf("%d",&temp);
        squeue[sfront]=squeue[srear]=temp;
    }
    else
    {
        srear++;
        printf("Enter digit: ");
        scanf("%d",&squeue[srear]);
    }
}
void sdequeue()
{
    if (sfront==-1)
    {
        printf("\nQueue Underflow.\n");
    }
    else if (sfront==srear)
    {
        printf("\n%d is dequeued.\n",squeue[sfront]);
        sfront=srear=-1;
    }
    else
    {
        printf("\n%d is dequeued.\n",squeue[sfront]);
        sfront++;
    }
}
void sdisplay()
{
    if (srear&&sfront==-1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        for (int i = sfront; i <=srear; i++)
        {
            printf("%d ",squeue[i]);
        }
    }
    printf("\n");
}
void smenu()
{
    int choice;
    restart:
    printf("************************Simple Queue************************\n");
    printf("\nPress 1 to Enqueue.\n");
    printf("Press 2 to Dequeue.\n");
    printf("Press 3 to Display.\n");
    printf("Press 4 to Exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        senqueue();
        goto restart;
    case 2:
        sdequeue();
        goto restart;
    case 3:
        sdisplay();
        goto restart;
    case 4:
        printf("Exit.\n");
        break;
    default:
        printf("Wrong Choice.\n");
        goto restart;
    }
}
void sinitialize()
{
    sfront=srear=-1;
    smenu();
}
void cenqueue()
{
    if ((crear+1)%5==cfront)
    {
        printf("\nQueue Overflow.\n");
    }
    else if (cfront&&crear==-1)
    {
        int temp;
        cfront=(cfront+1)%5;
        crear=(crear+1)%5;
        printf("Enter digit: ");
        scanf("%d",&temp);
        cqueue[cfront]=cqueue[crear]=temp;
    }
    else
    {
        crear=(crear+1)%5;
        printf("Enter digit: ");
        scanf("%d",&cqueue[crear]);
    }
}
void cdequeue()
{
    if (cfront==-1)
    {
        printf("\nQueue Underflow.\n");
    }
    else if (cfront==crear)
    {
        printf("\n%d is dequeued.\n",cqueue[cfront]);
        cfront=crear=-1;
    }
    else
    {
        printf("\n%d is dequeued.\n",cqueue[cfront]);
        cfront=(cfront+1)%5;
    }
}
void cdisplay()
{
    if (crear&&cfront==-1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        int i = cfront;
        do 
        {
            printf("%d ", cqueue[i]);
            i = (i + 1) % 5;
        }
        while (i != (crear + 1) % 5);
    }
    printf("\n");
}
void cmenu()
{
    int choice;
    restart:
    printf("************************Circular Queue************************\n");
    printf("\nPress 1 to Enqueue.\n");
    printf("Press 2 to Dequeue.\n");
    printf("Press 3 to Display.\n");
    printf("Press 4 to Exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        cenqueue();
        goto restart;
        break;
    case 2:
        cdequeue();
        goto restart;
        break;
    case 3:
        cdisplay();
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
}
void cinitialize()
{
    cfront=crear=-1;
    cmenu();
}
void mainmenu()
{
    int choice;
    restart:
    printf("************************Main Menu************************\n");
    printf("\nPress 1 for Simple Queue.\n");
    printf("Press 2 for Circular Queue.\n");
    printf("Press 3 to Exit.\n");
    printf("Enter your Choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        sinitialize();
        goto restart;
    case 2:
        cinitialize();
        goto restart;
    case 3:
        printf("Exit.\n");
        break;   
    default:
        printf("Wrong Choice.\n");
        goto restart;
    }
}
int main()
{
    mainmenu();
    system("PAUSE");
    return 0;
}
