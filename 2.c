#include<stdio.h>
void swapbyvalue(int x,int y)
{
    int temp=0;
    temp=x;
    x=y;
    y=temp;
}
void swapbyrefference(int *x,int *y)
{
    int temp=0;
    temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    int a,b;
    printf("A: ");
    scanf("%d",&a);
    printf("B: ");
    scanf("%d",&b);
    swapbyvalue(a,b);
    printf("Swapping by value\n");
    printf("A: %d\n",a);
    printf("B: %d\n",b);
    swapbyrefference(&a,&b);
    printf("Swapping by Reference\n");
    printf("A: %d\n",a);
    printf("B: %d\n",b);
    return 0;
}