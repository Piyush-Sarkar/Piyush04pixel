#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
int createnode(int data)
{
	struct node *newnode=(struct node*)malloc(sizeof (struct node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
}
struct node *insert(struct node *node,int data)
{
	if(node==NULL)
	return createnode(data);
	if(data<node->data)
	node->left=insert(node->left,data);
	else if(data>node->data)
	node->right=insert(node->right,data);
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->data);
	}
}
int main()
{
	int r,f=1,ch,x;
	struct node *root=NULL;
	printf("Enter the value of root:\n");
	scanf("%d",&r);
	root=insert(root,r);
	printf("\nEnter 1 to insert more nodes:");
	scanf("%d",&f);
	while(f==1)
	{
		printf("enter a value to be inserted:\n");
		scanf("%d",&x);
		insert(root,x);
		printf("\nenter 1 to continue and 0 to discontinue\n");
		scanf("%d",&f);
	}
	printf("\n PREORDER\n");
	preorder(root);
	printf("\n INORDER\n");
	inorder(root);
	printf("\n POSTORDER\n");
	postorder(root);
	return 0;
}
