#include <stdio.h>
int binary(int);
int i,n,elem,a[100];
int main ()
{
	int ans,elem;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Enter the array element\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter the element \n");
	scanf("%d",&elem);
	ans =binary(elem);
	printf("THE POSITION IS %d",ans);
	return 0;
}
	int binary( int x)
	{
		int st=0,mid;
		int ed=n-1;
		while(st<=ed)
		{
			mid=(st+ed)/2;
			if (a[mid]==x)
			return mid+1;
            else if(x<a[mid])
            ed=mid-1; 
            else if	(x>a[mid])
            st=mid+1;
		}
		
	}
