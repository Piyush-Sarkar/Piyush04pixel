#include<stdio.h>
#define maxsize 10
int n,f1=1,f2=1,front=-1,rear=-1,item,ch1=0,ch2=0,i;
int a[maxsize];
void display(int a[],int num)
{
	int j;
	for(j=0;j<num;j++)
	printf("%d ",a[j]);
}
void insertion(int item)
{
	if((front==0 && rear==maxsize-1)||front==rear+1)
	{
		printf("\nQueue overflow\n");
		ch1=1;
		return;
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
	}
	else if(rear==maxsize-1 && front>0)
	{
		rear=0;
	}
	else
	{
		rear=rear+1;
	}
	a[rear]=item;
}
void deletion()
{
	if(front==-1)
	{
		printf("\nQueue underflow\n");
		ch2=1;
		return;
	}
	int del=a[front];
	front=0;
	printf("\nDeleted item is %d\n",del);
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(front==maxsize-1)
	{
		front=0;
	}
	else
	{
		front=front+1;
	}
}
int main()
{
	printf("\nEnter the number of elements in the queue : ");
	scanf("%d",&n);
	printf("\nEnter the queue elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("\nThe original queue :\n");
	display(a,maxsize);
	printf("\n");
	printf("\n\tINSERTION\t\n");
	printf("\nEnter any number other than 0 to start insertion : ");
	scanf("%d",&f1);
	while(f1!=0)
	{
		if(ch1!=1)
		{
			printf("\nEnter the element to be inserted : ");
	        scanf("%d",&item);
	        insertion(item);
	        printf("\nEnter 0 to stop and any other number to continue : ");
	        scanf("%d",&f1);	
		}
	}
	printf("\nQueue after insertion :\n");
	display(a,maxsize);
	printf("\n");
	printf("\n\tDELETION\t\n");
	printf("\nEnter any number other than 0 to start deletion : ");
	scanf("%d",&f2);
	while(f2!=0)
	{
		if(ch2!=1)
		{
			deletion();
		    printf("\nEnter 0 to stop and any other number to continue : ");
	        scanf("%d",&f2);
		}
	}
	printf("\n");
	printf("\nQueue after deletion :\n");
	display(a,maxsize);
	return 0;
}

