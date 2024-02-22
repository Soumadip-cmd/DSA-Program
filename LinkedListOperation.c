//All linkedlist operation BY -'C'
#include<stdio.h>
#include<Stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *start=NULL;
void create()
{
    int ch;
    do{
        struct node *temp,*newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter Data: ");
        scanf("%d",&newnode->data);
        newnode->link=0;
        if(start==0)
        {
            start=temp=newnode;
        }
        else{
            temp->link=newnode;
            temp=newnode;
        }
        printf("\nDo Again?..Enter 1:- ");
        scanf("%d",&ch);
    }while(ch==1);

}
void display()
{
    struct node *temp=start;
    printf("START->");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->link;
    }
    printf("NULL");
}
void insert_beg(int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->link=0;
    if(temp!=NULL)
    {
        temp->link=start;
        start=temp;
    }
}
void insert_end(int x)
{
    struct node *temp,*ptr=start,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->link=0;
    if(temp!=NULL)
    {
        while(ptr->link!=NULL)
        {
            p=ptr;
            ptr=ptr->link;
        }
        ptr->link=temp;
        
    }
}
void insert_pos(int x,int pos)
{
    struct node *temp,*ptr=start,*p=start,*p1;
    int i=1,count=0;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->link=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    if(pos>count||pos<=0)
    {
        printf("\nCheck Position...\n\n");
    }
    else{
        while(i<pos)
        {
            i++;
            p1=p;
            p=p->link;
        }
        p1->link=temp;
        temp->link=p;
    }


}
void delete_beg()
{
    struct node *ptr=start;
    if(start!=NULL)
    {
        start=start->link;
        free(ptr);
    }
}
void delete_end()
{
    struct node *temp=start;
    while(temp->link->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=NULL;
    // free(temp->link->link);
}
void delete_pos(int pos)
{
    struct node *ptr=start,*temp=start,*p,*p1;
    int i=1,count=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    if(pos>count||pos<=0)
    {
        printf("\nCheck Position...\n\n");
    }
    else{
        while(i<pos)
        {
            p=temp;
            i++;
            temp=temp->link;
        }
        p1=p->link;
        p->link=temp->link;
        free(p1);

    }

}
void reverse()
{
    struct node *temp,*prevnode,*nextnode;
    prevnode=0;
    nextnode=temp=start;
    while(nextnode!=NULL)
    {

        nextnode=nextnode->link;
        temp->link=prevnode;
        prevnode=temp;
        temp=nextnode;
    }
    start=prevnode;
}
void merge()
{
    int ch;
    struct node *t=start;
    while(t->link!=NULL)
    {
        t=t->link;
    }
    do{
        struct node *temp,*newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter Data: ");
        scanf("%d",&newnode->data);
        newnode->link=0;
        
        if(t->link==NULL)
        {
            t->link=newnode;
            temp=newnode;
        }
        else{
            temp->link=newnode;
            temp=newnode;
        }
        printf("\nDo Again?..Enter 1:- ");
        scanf("%d",&ch);
    }while(ch==1);

}
void sorting()
{
    struct node *ptr=start,*cpt;
    int temp;
    while(ptr->link!=NULL)
    {
        cpt=ptr->link;
        while(cpt!=NULL)
        {
            if(ptr->data>cpt->data)
            {
                temp=ptr->data;
                ptr->data=cpt->data;
                cpt->data=temp;
            }
            cpt=cpt->link;
        }
        ptr=ptr->link;
    }
}
int main()
{
    int k,n,pos,pos2;
    printf("\n\t\t----------->>Linked-list Operation<<-----------\n\n");
    while(1)
    {
        printf("Menu of LinkedList Operation:-\n\n");
        
        printf("\n\n0.Exit\n1.Create\n2.Display\n3.Insert at Beginnig\n4.Insert at End\n5.Insert at Specific Position\n6.Delete From Beginnig\n7.Delete End\n8.Delete From specific position\n9.Reverse\n10.Merge LinkedList\n11.Sorting[Bubble]\n12.Searching element\n13.Count\n\n");
        printf("Choose Operation number: ");
        scanf("%d",&k);
        switch(k)
        {
            case 0:
                exit(0);
                break;
            case 1:
                create();
                break;
            case 3:
                printf("\nEnter Insert-Beginning Data: ");
                scanf("%d",&n);
                insert_beg(n);
                display();
                break;
            case 2:
                display();
                break;
            case 4:
                printf("\nEnter Insert-End Data: ");
                scanf("%d",&n);
                insert_end(n);
                display();
                break;
            case 5:
                printf("\nEnter Insert Data: ");
                scanf("%d",&n);
                printf("\nEnter Position: ");
                scanf("%d",&pos);
                
                insert_pos(n,pos);
                display();
                break;
                
            case 6:
                delete_beg();
                display();
                break;
            case 7:
                delete_end();
                display();
                break;
            case 8:
                printf("\nEnter Position: ");
                scanf("%d",&pos2);
                
                delete_pos(pos2);
                display();
                break;
            case 9:
                printf("\nBefore reverse: \n");
                display();
                printf("\nAfter reverse: \n");
                reverse();
                display();
                break;
            case 10:
                printf("\nMerge Operation-----\n\n");
                merge();
                display();
                break;
            case 11:
                printf("\nBefore Sorting: \n");
                display();
                printf("\nAfter Sorting: \n");
                sorting();
                display();
                break;
            case 13:
                display();
                break;
            case 14:
                display();
                break;
            case 15:
                display();
                break;
            case 16:
                display();
                break;
            default:
                printf("\tSorry!!..Wrong choice..\n\n");
                break;
        }
        fflush(stdin);
        getchar();
    }
}