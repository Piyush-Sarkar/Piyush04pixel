#include<stdio.h>
int first(int);
int middle(int); 
int last(int);
int n,i,a[50];                                                                        
int main()
{
	int s,c,j,item;
	printf("ENTER THE NO OF ELEMENTS IN AN ARRAY: ");
	scanf("%d",& n);
	printf("ENTER THE ELEMENTS IN AN ARRAY: \n " );
	for(i=0;i<n;i++)
	scanf("%d",& a[i]);
	printf("DISPLAYING ELEMENTS IN AN ARRAY:  \n" );
	for(i=0;i<n;i++)
	printf("%d \n",a[i]);
	printf("\n WANTING TO CONTINUE.. \n 1.YES \n 2.NO ");
	printf("\n ENTER YOUR OPTION:");
	scanf("%d",& c);
	while(c!=2)
	{
	printf("ENTER THE ELEMENT TO BE INSERTED IN ARRAY: ");
	scanf("%d",& item);
	printf(" FOR INSERTION: \n 1. IN THE FIRST \n 2. ANYWHERE IN THE ARRAY \n 3. IN THE LAST \n");
	printf("\n ENTER YOUR OPTION:");
	scanf("%d",& s);
	switch(s)
	{
	case 1:
		first(item);
		break;
	case 2:
	    middle(item);
		break;
	case 3:
		last(item);
		break;
	default:
		printf("WRONG INPUT");
		break;
	}
printf("\n WANTING TO CONTINUE.. \n 1.YES\n 2.NO ");
scanf("%d",& j);
c=j;
}
	return 0;
}
		   	 
int first(int x)
{
   if(n<50)  
   {
    i=n;
    while(i>0)
    {
    	a[i]=a[i-1];
    	i--;
    }
    a[0]=x;
    n=n+1;
   }
	printf("DISPLAYING ELEMENTS IN AN ARRAY:  \n" );
	for(i=0;i<n;i++)
	printf("%d \n",a[i]);
	return 0;  
}

int middle(int x)
{
	int pos;
	printf("ENTER THE POSITION TO BE INSERTED  IN ARRAY: ");
	scanf("%d",& pos);
	if(n<50)
	{
    i=n;
    while(i>pos-1)
    {
    	a[i]=a[i-1];
    	i--;
    }
    a[pos-1]=x;
    n=n+1;
}
	printf("DISPLAYING ELEMENTS IN AN ARRAY:  \n" );
	for(i=0;i<n;i++)
	printf("%d \n",a[i]);
	return 0;  
}		   

int last(int x)
{ 
if(n<50)
{
    a[n]=x;
    n=n+1;
	}
	printf("DISPLAYING ELEMENTS IN AN ARRAY:  \n" );
	for(i=0;i<n;i++)
	printf("%d \n",a[i]);
	return 0;  
}		   

