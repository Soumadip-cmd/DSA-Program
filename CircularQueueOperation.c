//All CircularQueue Operations you Find Here ------------> 'C'
#include<stdio.h>
#include<stdlib.h>
#define max 4
int q[max];
int front=-1;
int rear=-1;
void enqueue(int);
void Display();
void dequeue();
void peek();
int main()
{
    printf("\n\t\t--------->>CircularQueue Operation<<--------\n\n");
    int k,num;
    while(1)
    {
        printf("\nMenu of CircularQueueOperation---> \n\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display");
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
                enqueue(num);
                Display();
                break;
            case 4:
                Display();
                break;
            case 2:
                dequeue();
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
void enqueue(int x)
{
    if(front==-1&&rear==-1)
    {
        front=rear=0;
        q[rear]=x;
    }
    else if((rear+1)%max==front)
    {
        printf("CircularQueue is Overflowed.");
    }
    else{
        rear=(rear+1)%max;
        q[rear]=x;
    }
}
void Display()
{
    int i=front;
    if(front==-1&&rear==-1)
    {
        printf("\nCircularQueue is empty.");
    }
    else
    {
        while(i!=rear)
        {
            printf("|%d|",q[i]);
            
            i=(i+1)%max;
        }
    }
}
void dequeue()
{
    if(front==-1&&rear==-1)
    {
        printf("\nUnderflow Condition..");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else{
        
        front=(front+1)%max;
    }
}
void peek()
{
    printf("%d is Peek element..",q[front]);
}