#include<stdio.h>
int sum();
int multiply();
int trace();
int transpose();
int triangular();
int a[100][100], b[100][100],c[100][100],m,n,k,i,j,s=0,o,p,q;
int main()
{
	printf ("\n enter the no of rows: ");
	scanf("%d",& n);
	printf ("\n enter the no of columns: ");
	scanf("%d",& m);
	printf ("\n enter the elements of 1st array :\n ");
	for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
	scanf("%d",& a[i][j]);
    }
    printf ("\n enter the elements of 2nd array :\n ");
	for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
	scanf("%d",& b[i][j]);
    } 
    printf ("\n display the elements of 1st array :\n ");
    for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
	printf("%d \t",a[i][j]);
	printf("\n");
    }
    printf ("\n display the elements of 2nd array :\n ");
    for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
	printf("%d \t",b[i][j]);
	printf("\n");
    }
    printf("\n WANTING TO CONTINUE.. \n 1.YES \n 2.NO ");
	printf("\n ENTER YOUR OPTION:");
	scanf("%d",& q);
	while(q!=2)
	{
    printf("1. sum  2.multiply 3. trace  4.transpose 5.triangular ");
    scanf("%d",& o);
    switch (o)
    {
	case 1:
		sum();
		break;
	case 2:
	    multiply();
		break;
	case 3:
	    trace();
		break;
	case 4:
		transpose();
		break;
	case 5:
	    triangular();
		break;	
	default:
		printf("WRONG INPUT");
		break;
	}
	printf("\n WANTING TO CONTINUE.. \n 1.YES\n 2.NO ");
scanf("%d",& p);
q=p;
}
    return 0;
}
    
    
    int sum()
    {
    printf ("\n display the elements of summation array :\n ");
	for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
	{
	c[i][j]=a[i][j]+b[i][j];
	printf("%d \t",c[i][j]);
    }
    printf("\n");
    }
   }
    
    
    int multiply()
    {
    printf("\n the multiplication of the matrix is : \n");
    for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	{
	c[i][j]=0;
	{
	for(k=0;k<n;k++)	
	c[i][j]=c[i][j]+a[i][k]*b[k][j];
    }          
    printf("%d \t",c[i][j]); 
	}
	printf("\n");
   }
   }
   
   int trace()
   {
   	for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
	{
   if(i==j)
	s=s+a[i][j];
    }
   }
   printf("\n the trace of the matrix is : %d",s);
   }
   
   

    int transpose()
    {
    printf ("\n display the elements of transpose matrix :\n ");
    for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
	{
    if ((i!=j)&& (j>i))
    {
    s=a[i][j];
	a[i][j]=a[j][i];
    a[j][i]=s;	
    }
    printf("%d \t",a[i][j]);
	}
	printf("\n");	
	}
   }

    int triangular()
    {
	printf ("\n display the elements of lower triangular matrix :\n ");
    for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
	{
    if (i<j)
   	printf("0 \t");
   	else
    printf("%d \t",a[i][j]);
	}
	printf("\n");	
	}
	printf ("\n display the elements of upper triangular matrix :\n ");
    for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
	{
    if (i>j)
   	printf("0 \t");
   	else
    printf("%d \t",a[i][j]);
	}
	printf("\n");	
	}
   }
