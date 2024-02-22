#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start, *tail;
void create();
void insert_beg(int);
void delete_beg();
void insert_end(int);
void delete_end();
void insert_pos(int);
void delete_pos();
void display();
void reverse();
void search();
void length();
int main()
{

    int k;
    do
    {
        create();
        int key;
        printf("\nEnter Choices: ");
        printf("\n0->exit\n1->display\n2->reverse\n3->insert_begining\n4->insert_ending\n5->insert_position\n6->search\n7->length\n8->delete_begin\n9->delete_end\n10->delete_pos\n");
        scanf("%d", &key);
        switch (key)
        {
        case 0:
            exit(0);
            break;
        case 1:
            display();
            break;
        case 2:
            reverse();
            break;
        case 3:
            insert_beg(909);
            display();
            break;
        case 4:
            insert_end(909);
            display();
            break;
        case 5:
            insert_pos(909);
            display();
            break;
        case 6:
            display();
            search();
            break;
        case 7:
            length();
            break;
        case 8:
            delete_beg();
            display();
            break;
        case 9:
            delete_end();
            display();
            break;
        case 10:
            display();
            delete_pos();
            display();
            break;
        default:
            printf("\nSorry Check Your choice..");
            break;
        }
        printf("\nAgain?..");
        scanf("%d", &k);
    } while (k == 1);
}
void create()
{
    char ch;
    do
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter Number: ");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        newnode->next = 0;
        if (start == NULL)
        {
            start = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        printf("\nDo Again?...->Y\n");
        fflush(stdin);
        ch = getchar();
    } while (ch == 'y' || ch == 'Y');
}
void display()
{
    struct node *temp = start;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
void insert_beg(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    start->prev = newnode;
    newnode->next = start;
    newnode->prev = NULL;
    start = newnode;
}
void reverse()
{
    struct node *temp = tail;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->prev;
    }
}
void insert_end(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    tail->next = temp;
    temp->next = NULL;
    temp->prev = tail;
    tail = temp;
}
void insert_pos(int x)
{
    struct node *temp,*ptr,*prevnode;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    int pos,i=1;
    printf("\nEnter position: ");
    scanf("%d",&pos);
    ptr=start;
    while(i<pos)
    {
        prevnode=ptr;
        ptr=ptr->next;
        i++;
    }
    temp->next=ptr;
    temp->prev=prevnode;
    prevnode->next=temp;
    ptr->prev=temp;
}
void search()
{
    int num,count=1,find;
    struct node *temp=start;
    printf("\nEnter Number: ");
    scanf("%d",&num);
    while(temp->next!=NULL)
    {
        if(temp->data==num)
        {
            printf("%d is Found at position %d\n",num,count);
            find=1;
        }
        count++;
        temp=temp->next;
    }
    if(find==0)
    {
        printf("\nSorry You don't Enter.\n");
    }
}
void length()
{
    int count=0;
    struct node *temp = start;
    while (temp != NULL)
    {
        
        temp = temp->next;
        count++;
    }
    printf("\nLength = %d",count);
}
void delete_beg()
{
    struct node *temp;
    temp=start;
    start=start->next;
    free(temp);
    start->prev=NULL;
}
void delete_end()
{
    struct node *temp=start,*new;
    while(temp->next!=NULL)
    {
        new=temp;
        temp=temp->next;
        
    }
    new->next=NULL;
    tail=new;
    free(temp);
}
void delete_pos()
{
    struct node *del=start,*temp,*p;
    int pos,i=1;
    printf("\nEnter Position: ");
    scanf("%d",&pos);
    while(i<pos)
    {
        temp=del;
        del=del->next;
        i++;
    }
    temp->next=del->next;
    // p=del->next;
    del->next->prev=temp;
    free(del);
}