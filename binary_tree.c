// Binary Tree using -'c'
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *create()
{
    int x, k;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Data: (-1) for no node: ");
    scanf("%d", &x);

    if (x == -1)
    {
        return 0;
    }
    newnode->data = x;

    printf("\nEnter right node of %d: ", x);
    newnode->right = create();
    printf("\nEnter left node of %d: ", x);
    newnode->left = create();
    return newnode;
}
void preorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        preorder(ptr->left);
        printf("%d ", ptr->data);
        preorder(ptr->right);
    }
}
void postorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        preorder(ptr->left);
        preorder(ptr->right);
        printf("%d ", ptr->data);
    }
}
int main()
{
    while (1)
    {

        struct node *root = NULL;
        root = create();
        int k;
        printf("\nEnter Choice: ");
        scanf("%d", &k);
        switch (k)
        {
        case 0:
            exit(0);
            break;
        case 1:
            preorder(root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            postorder(root);
            break;
        default:
            printf("Sorry wrong choice!!..\n\n");
            break;
        }
    }
}