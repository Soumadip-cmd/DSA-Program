//All Array Operations you Find Here ------------> 'C'
#include<stdio.h>
#include<stdlib.h>
#define MAX 15
int create(int []);
void display(int [],int);
int insert_beg(int [],int,int);
int delete_beg(int [],int);
int insert_end(int [],int ,int );
int delete_end(int [],int );
int insert_pos(int [],int ,int ,int);
int delete_pos(int [],int ,int);
void max_min(int [],int);
void sorting(int [],int);
void search(int [],int,int);
int count(int [],int);
int merge(int [],int);
void reverse(int [],int);
int binary_search(int [],int ,int);
int main()
{
    int k,a[MAX],n,data,pos,srch,store,position;
    printf("\n\t\t---->>Array Operation<<-----\n");
    while(1)
    {
        printf("\n\nMenu Of Array operations:-\n");
        printf("\n\n0.Exit\n1.Create\n2.Display\n3.Insert at Beginnig\n4.Insert at End\n5.Insert at Specific Position\n6.Delete From Beginnig\n7.Delete End\n8.Delete From specific position\n9.Max-Min of Array\n10.Merge Array\n11.Sorting[Bubble]\n12.Searching element\n13.Count\n14.Reverse\n15.Binary-Search\n\n");
        printf("Choose Operation number: ");
        scanf("%d",&k);
        switch(k)
        {
            case 0:
                exit(0);
                break;
            case 1:
                n=create(a);
                break;
            case 3:
                printf("Enter Data: ");
                scanf("%d",&data);
                n=insert_beg(a,n,data);
                display(a,n);
                break;
            case 2:
                display(a,n);
                break;
            case 4:
                printf("Enter Data: ");
                scanf("%d",&data);
                n=insert_end(a,n,data);
                display(a,n);
                break;
            case 5:
                printf("Enter Data: ");
                scanf("%d",&data);
                printf("\nEnter Position: ");
                scanf("%d",&pos);
                if(pos<=0||pos>n)
                {
                    printf("Ckeck!! Invalid Position..");
                }
                else{
                    n=insert_pos(a,n,data,pos);
                }
                display(a,n);
                break;
            case 6:
                n=delete_beg(a,n);
                display(a,n);
                break;
            case 7:
                n=delete_end(a,n);
                display(a,n);
                break;
            case 8:
                printf("\nEnter Position: ");
                scanf("%d",&pos);
                if(pos<=0||pos>n)
                {
                    printf("Ckeck!! Invalid Position..");
                }
                else{
                    n=delete_pos(a,n,pos);
                }
                display(a,n);
                break;
            case 9:
                max_min(a,n);
                break;
            case 11:
                sorting(a,n);
                display(a,n);
                break;
            case 10:
                n=merge(a,n);
                display(a,n);
                break;
            case 12:
                printf("\nEnter Searched Number: ");
                scanf("%d",&srch);
                display(a,n);
                search(a,n,srch);
                break;
            case 15:
                printf("\nEnter Searched Number: ");
                scanf("%d",&srch);
                display(a,n);
                position=binary_search(a,n,srch);
                printf("%d element is Found at position %d",srch,position+1);
                break;
            case 13:
                
                display(a,n);
                printf("\n\tCounted Array Element= %d",count(a,n));
                break;
            case 14:
                printf("Before Reverse: ");
                display(a,n);
                printf("After Reverse: ");
                reverse(a,n);
                display(a,n);
                break;
            default:
                printf("Sorry!!Wrong Choice..");
                break;
        }
        fflush(stdin);
        getchar();
    }
}

int create(int a[])
{
    int n;
    printf("\nEnter Array Limit: ");
    scanf("%d",&n);
    printf("\nEnter elements One bY One:\n");
    for(int i=0;i<n;i++)
    {
        printf("A[%d]=",i);
        scanf("%d",&a[i]);
    }
    return n;
}
void display(int a[],int n)
{
    printf("\n\tArrays Elements are:-->\n");
    for(int i=0;i<n;i++)
    {
        printf("A[%d]=|%d|\n",i,a[i]);
    }
}
int count(int a[],int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        count++;
    }
    return count;
}
int insert_beg(int a[],int n,int x)
{
    for(int i=n-1;i>=0;i--)
    {
        a[i+1]=a[i];
    }
    a[0]=x;
    return n+1;
}
int insert_end(int a[],int n,int x)
{
    
    a[n]=x;
    return n+1;
}
int insert_pos(int a[],int n,int x,int pos)
{
    for(int i=n-1;i>=pos-1;i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1]=x;
    return n+1;
}
int delete_beg(int a[],int n)
{
    for(int i=0;i<=n;i++)
    {
        a[i]=a[i+1];
    }
    return n-1;
}
int delete_end(int a[],int n)
{
    
    return n-1;
}
int delete_pos(int a[],int n,int pos)
{
    for(int i=pos-1;i<=n;i++)
    {
        a[i]=a[i+1];
    }
    return n-1;
}
void max_min(int a[],int n)
{
    int max,min,posmax=0;
    int posm=0;
    max=a[0];
    min=a[0];
    for(int i=0;i<n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
            posmax=i+1;

        }
        if(min>a[i])
        {
            min=a[i];
            posm=i+1;

        }
    }
    printf("%d is Max element at position %d.",max,posmax);
    printf("%d is Min element at position %d.",min,posm);
}
void sorting(int a[],int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    
}
void search(int a[],int n,int k)
{
    int flag,pos;
    for(int i=0;i<n;i++)
    {
        if(k==a[i])
        {
            flag=1;
            pos=i;
        }
    }
    if(flag==1)
    {
        printf("%d is Found at position %d",k,pos+1);
    }
    else{
        printf("Ckeck Number.");
    }
}
void reverse(int a[],int n)
{
    int temp;
    for(int i=0;i<n/2;i++)
    {
        temp=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=temp;
    }
}
int merge(int a[],int n)
{
    int lt,m;
    m=count(a,n);
    
    printf("\nEnter Array Limit: ");
    scanf("%d",&lt);
    printf("\nEnter elements One bY One:\n");
    for(int i=m;i<m+lt;i++)
    {
        printf("A[%d]=",i);
        scanf("%d",&a[i]);
    }
    return m+lt;
}
int binary_search(int a[],int n,int num)
{
    int l=0,r=n-1;
    int mid;
    while(l<=r)
    {
        mid=((l+r)/2);
        if(a[mid]==num)
        {
            return mid;

        }
        else if(num<a[mid])
        {
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
        return -1;
}