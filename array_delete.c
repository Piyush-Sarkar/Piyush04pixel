#include<stdio.h>
int first(int);
int middle(int); 
int last(int);
int n,i,a[50];                                                                        
int main()
{
	int s,c,j,pos;
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
	printf(" FOR DELETION: \n 1. IN THE FIRST \n 2. ANYWHERE IN THE ARRAY \n 3. IN THE LAST \n");
	printf("\n ENTER YOUR OPTION:");
	scanf("%d",& s);
	switch(s)
	{
	case 1:
	pos=1;
	first(pos);
	break;
	case 2:
	printf("ENTER THE POSITION TO BE DELETED IN ARRAY: ");
	scanf("%d",& pos);
    middle(pos);
	break;
	case 3:
	pos=n-1;                                                                                                         
	last(pos);
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


int middle(int x)
{
	x=x-1;
	for(i=x;i<n;i++)
   { 
	a[i]=a[i+1];
   }
n=n-1;
printf("DISPLAYING ELEMENTS IN AN ARRAY:  \n" );
for(i=0;i<n;i++)
printf("%d \n",a[i]);
return 0;
}


int last(int x)
{
	printf("DISPLAYING ELEMENTS IN AN ARRAY:  \n" );
	n=n-1;
	for(i=0;i<n;i++)
	printf("%d \n",a[i]);
return 0;
}
	

int first( int x)
{
	for(i=0;i<n;i++)
   { 
	a[i]=a[i+1];
   }
n=n-1;
printf("DISPLAYING ELEMENTS IN AN ARRAY:  \n" );
for(i=0;i<n;i++)
printf("%d \n",a[i]);
return 0;
}
