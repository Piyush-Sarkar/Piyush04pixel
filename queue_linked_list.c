#include<stdio.h>
#include<stdlib.h>
int n,f1=1,f2=1,maxsize,front=-1,rear=-1,item,ch1=0,ch2=0;
struct node{
	int data;
	struct node *next;
};
struct node *head;
void createList(int n)
{
	struct node *newnode, *temp;
	int data,i;
	head=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data 1 : \n");
	scanf("%d",&data);
	head->data=data;
	head->next=NULL;
	front=0;rear=0;
	temp=head;
	for(i=2;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data %d : \n",i);
		scanf("%d",&data);
		newnode->data=data;
		newnode->next=NULL;
		temp->next=newnode;
		temp=temp->next;
		rear=rear+1;
	}
}
void traverseList()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nQueue is empty\n");
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void insertion(int item)
{
	if(rear==maxsize-1)
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
	else
	{
		struct node *newnode;
	    newnode=(struct node*)malloc(sizeof(struct node));
	    newnode->data=item;
	    newnode->next=NULL;
	    struct node *temp;
	    temp=head;
	    while(temp->next!=NULL)
	    {
		    temp=temp->next;
	    }
	    temp->next=newnode;
	    rear=rear+1;
    } 
}
void deletion()
{
	if(front==-1 || front>rear)
	{
		printf("\nQueue underflow\n");
		ch2=1;
		return;
	}
	else
	{
	    struct node *temp;
	    temp=head;
	    if(temp==NULL)
	    {
	    	front=front+1;
	    	return;
		}
	    printf("\nDeleted element is %d\n",temp->data);
	    if(head->next==NULL)
	    {
	    	head=NULL;
	    	front=front+1;
	    	return;
		}
	    head=head->next;
	    front=front+1;
	    free(temp);
	}
}
int main()
{
	printf("\nEnter the maximum number of elements in the queue : ");
	scanf("%d",&maxsize);
	printf("\nEnter the number of elements in the queue : ");
	scanf("%d",&n);
	createList(n);
	printf("\nThe original queue :\n");
	traverseList(n);
	printf("\n");
	printf("\n\tINSERTION\t\n");
	printf("\nEnter any number other than 0 to start insertion : ");
	scanf("%d",&f1);
	while(f1!=0)
	{
		if(ch1==1)
		break;
		printf("\nEnter the element to be inserted : ");
	    scanf("%d",&item);
	    insertion(item);
	    printf("\nEnter 0 to stop and any other number to continue : ");
	    scanf("%d",&f1);
	}
	printf("\nQueue after insertion :\n");
	traverseList(n);
	printf("\n");
	printf("\n\tDELETION\t\n");
	printf("\nEnter any number other than 0 to start deletion : ");
	scanf("%d",&f2);
	while(f2!=0)
	{
		if(ch2==1)
		break;
		deletion();
		printf("\nEnter 0 to stop and any other number to continue : ");
	    scanf("%d",&f2);
	}
	printf("\n");
	printf("\nQueue after deletion :\n");
	traverseList(n);
	return 0;
}
