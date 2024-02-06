#include<stdio.h>
void display(int[],int);
void selectionsort(int[],int);
void bubblesort(int[],int);
void insertionsort(int[],int);
void mergesort(int[],int,int);
void merge(int[],int,int,int);
void display(int x[],int y)
{
	int k;
	for(k=0;k<y;k++)
	printf("%d ",x[k]);
}
void selectionsort(int x[],int y)
{
	int i,j,min,t;
	for(i=0;i<y;i++)
	{
		min=i;
		for(j=i+1;j<y;j++)
		{
			if(x[j]<x[min])
			min=j;
		}
		if(min!=i)
		{
			t=x[i];
			x[i]=x[min];
			x[min]=t;
		}
	}
}
void bubblesort(int x[],int y)
{
	int i,j,f,t;
	for(i=0;i<y;i++)
	{
		for(j=0;j<(y-i-1);j++)
		{
			f=0;
			if(x[j]>x[j+1])
			{
				t=x[j];
				x[j]=x[j+1];
				x[j+1]=t;
				f=1;
			}
		}
		if(f==0)
		break;
	}
}
void insertionsort(int x[],int y)
{
	int i,j,t;
	for(i=1;i<y;i++)
	{
		t=x[i];
		j=i-1;
		while(j>=0 && t<x[j])
		{
			x[j+1]=x[j];
			j--;
		}
		x[j+1]=t;
	}
}
void mergesort(int x[],int lb,int ub)
{
	int mid;
	if(lb<ub)
	{
		mid=lb+(ub-lb)/2;
		mergesort(x,lb,mid);
		mergesort(x,mid+1,ub);
		merge(x,lb,mid,ub);
	}
}
void merge(int x[],int p,int q,int r)
{
	int i,j,k;
	int n1=q-p+1;
	int n2=r-q;
	int L[n1],M[n2];
	for(i=0;i<n1;i++)
	L[i]=x[p+i];
	for(j=0;j<n2;j++)
	M[j]=x[q+1+j];
	i=0;
	j=0;
	k=p;
	while(i<n1 && j<n2)
    {
    	if(L[i]<=M[j])
    	{
    		x[k]=L[i];
    		i++;
		}
		else
		{
			x[k]=M[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		x[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		x[k]=M[j];
		j++;
		k++;
	}
}
int main()
{
	int a[50];
	int n,i,ch,f=0;
	printf("\nEnter the number of elements:\n");
	scanf("%d",&n);
	printf("\nEnter the array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nThe original array is:\n");
	display(a,n);
	printf("\n\tMENU:\t\n");
	printf("\n\t1.SELECTION SORT\t\n");
	printf("\n\t2.BUBBLE SORT\t\n");
	printf("\n\t3.INSERTION SORT\t\n");
	printf("\n\t4.MERGE SORT\t\n");
	printf("\nEnter your choice:\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			selectionsort(a,n);
			break;
		case 2:
			bubblesort(a,n);
			break;
		case 3:
			insertionsort(a,n);
			break;
		case 4:
			mergesort(a,0,n-1);
			break;
		default:
			f=1;
			printf("\nWrong choice\n");
	}
	if(f==0)
	{
		printf("\nThe sorted array is:\n");
		display(a,n);
	}
	return 0;
}
