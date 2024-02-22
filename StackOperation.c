//All Stack Operations you Find Here ------------> 'C'
#include<stdio.h>
#include<stdlib.h>
#define max 4
int s[max];
int top=-1;
void push(int);
void Display();
void peek();
void pop();
int main()
{
    printf("\n\t\t--------->>Stack Operation<<--------\n\n");
    int k,num;
    while(1)
    {
        printf("\nMenu of StackOperation---> \n\n");
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display");
        printf("\n\nChoose operation Number: ");
        scanf("%d",&k);
        switch(k)
        {
            case 0:
                exit(0);
                break;
            case 1:
                printf("Enter data: ");
                scanf("%d",&num);
                push(num);
                Display();
                break;
            case 4:
                Display();
                break;
            case 2:
                pop();
                Display();
                break;
            case 3:
                peek();
                Display();
                break;
            default:
                printf("Sorry!!Wrong Choice..");
                break;
        }
        fflush(stdin);
        getchar();
    }
}
void push(int x)
{
    if(top==max-1)
    {
        printf("Stack is Overflowed.");
    }
    else{
        top++;
        s[top]=x;
    }
}
void Display()
{
    for(int i=top;i>=0;i--)
    {
        printf("\n\t\t|%d|",s[i]);
        if(top==i)
        {
            printf("--->TOP(%d)",s[top]);
        }
    }
}
void pop()
{
    if(top==-1)
    {
        printf("\n\tStack Is Underflowed.");
    }
    else{
        top--;
    }
}
void peek()
{
    printf("%d is Top element..",s[top]);
}