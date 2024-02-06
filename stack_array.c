#include<stdio.h>
int n,i,top,item;
int maxsize=10;
int a[10];
void display(int a[],int num)
{
	int j;
	for(j=num;j>=0;j--)
	printf("%d ",a[j]);
}
void push(int item)
{
	if(top==maxsize-1)
	printf("\nStack overflow\n");
	else
	{
		top=top+1;
		a[top]=item;
	}
}
void pop()
{
	if(top==-1)
	printf("\nStack underflow\n");
	else
	{
		int ele;
		ele=a[top];
		top=top-1;
		printf("\nPopped element is %d\n",ele);
	}
}
int main()
{
	int f1,f2;
	printf("\nEnter the number of elements in the stack : ");
	scanf("%d",&n);
	printf("\nEnter the stack elements :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		top=i;
	}
	printf("\nThe original stack:\n");
	display(a,top);
	printf("\n");
	printf("\n\tPUSH\t\n");
	printf("\nEnter any number other than 0 to start push operation : ");
	scanf("%d",&f1);
	while(f1!=0)
	{
		printf("\nEnter the element to be inserted : ");
	    scanf("%d",&item);
	    push(item);
	    printf("\nEnter 0 to stop and any other number to continue : ");
	    scanf("%d",&f1);
	}
	printf("\nStack after push operation :\n");
	display(a,top);
	printf("\n");
	printf("\n\tPOP\t\n");
	printf("\nEnter any number other than 0 to start pop operation : ");
	scanf("%d",&f2);
	while(f2!=0)
	{
		pop();
		printf("\nEnter 0 to stop and any other number to continue : ");
	    scanf("%d",&f2);
	}
	printf("\n");
	printf("\nStack after pop operation :\n");
	display(a,top);
	return 0;
}
