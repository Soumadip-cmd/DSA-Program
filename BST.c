#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
void preorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
    printf("\n\n");
}
void inorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        printf("%d\t",ptr->data);
        inorder(ptr->right);
    }
    printf("\n\n");
}
void postorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d\t",ptr->data);
    }
    printf("\n\n");
}

struct node *create()
{
    struct node *newnode;
    int prevdata;
    int x;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Data(-1 for no node): ");
    scanf("%d",&x);
    prevdata=newnode->data;
    newnode->data=x;
    if(newnode->data==-1)
    {
        return 0;
    }
    if(prevdata<newnode->data)
    {
        newnode->right=create();
    }
    else if(prevdata>newnode->data)
    {
        newnode->left=create();
    }
    return newnode;
}
int main()
{
    struct node *root=NULL;
    root=create();
    preorder(root);
    inorder(root);
    postorder(root);
    // preorder(tail);
}