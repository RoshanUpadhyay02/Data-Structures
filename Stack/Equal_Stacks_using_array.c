#include <stdio.h>
#include <stdlib.h>

int *stack1, *stack2, *stack3,top1 = -1,top2 = -1,top3 = -1;

int push1(int value,int s)
{
    s += value;
    stack1[++top1] = value;
    return s;
}

int pop1()
{
    return stack1[top1--];
}

void display1()
{
    int n = top1;
    while(n != -1)
        printf("%d ",stack1[n--]);
}

int push2(int value, int s)
{
    s += value;
    stack2[++top2] = value;
    return s;
}

int pop2()
{
    return stack2[top2--];
}

void display2()
{
    int n = top2;
    while(n != -1)
        printf("%d ",stack2[n--]);
}

int push3(int value, int s)
{
    s += value;
    stack3[++top3] = value;
    return s;
}

int pop3()
{
    return stack3[top3--];
}

void display3()
{
    int n = top3;
    while(n != -1)
        printf("%d ",stack3[n--]);
}

int findmax(int s1, int s2, int s3)
{
    if(s1 > s2 && s1 > s3)
        return 1;
    else if(s2 > s1 && s2 > s3)
        return 2;
    else
        return 3;
}

int findsum(int s1,int s2,int s3)
{
    while(!(s1 == s2 && s2  == s3))
    {
        int max = findmax(s1,s2,s3);
        if(max == 1)        
            s1 -= pop1();
        else if(max == 2)
            s2 -= pop2();
        else
            s3 -= pop3();
    }

    return s1;
}

int main()
{
    int n,x,i,sum1 = 0,sum2 = 0,sum3 = 0;
    printf("Enter the no. of elemetns for 1st: ");
    scanf("%d",&n);

    stack1 = (int *)malloc(n*sizeof(int));
    stack2 = (int *)malloc(n*sizeof(int));
    stack3 = (int *)malloc(n*sizeof(int));

    printf("Enter the elements for 1st: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        sum1 = push1(x,sum1);   
    }

    display1();

    printf("\nEnter the no. of elemetns for 2nd: ");
    scanf("%d",&n);

    printf("Enter the elements for 2nd: ");
    while(n--)
    {
        scanf("%d",&x);
        sum2 = push2(x,sum2);   
    }

    display2();

    printf("\nEnter the no. of elemetns for 3rd: ");
    scanf("%d",&n);

    printf("Enter the elements for 3rd: ");
    while(n--)
    {
        scanf("%d",&x);
        sum3 = push3(x,sum3);   
    }

    display3();

    int sum = findsum(sum1,sum2,sum3);  

    printf("\n\nThe Max Sum at wich the stacks are equal is: %d",sum);

    return 0;
}