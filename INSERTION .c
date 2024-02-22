//insert element at any position
#include<stdio.h>
int main()
{
	int n;
	printf("\nEnter limit of Array: ");
	scanf("%d",&n);
	int a[n],i,pos,num;
	printf("\nEnter Elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nAt which position You want to add a number: ");
	scanf("%d",&pos);
	printf("\nNumber is: ");
	scanf("%d",&num);
	for(i=n-1;i>=pos-1;i--)
	{
		a[i+1]=a[i];
		// printf("%d\n",a[i+1]);
	}
	a[pos-1]=num;
	n++;
	printf("Array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	// 
}
