#include<stdio.h>
#define MAX 10
void read(int a[MAX][MAX],int m,int n){
	int i,j;
	printf("Enter the elements of matrix:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
}
void display(int a[MAX][MAX],int m,int n){
	int i,j;
	printf("The matrix:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
void max_min(int a[MAX][MAX],int m,int n){
	int i,j,max,min;
	for(i=0;i<m;i++){
		max=a[0][0];min=a[0][0];
		for(j=0;j<n;j++){
			if(a[i][j]>max)
				max=a[i][j];
			if(a[i][j]<min)
				min=a[i][j];
		}
	}
	printf("The maximum element: %d",max);
	printf("\nThe minimum element: %d",min);
}
int main(){
	int a[MAX][MAX],m,n;
	printf("Enter the no. of rows: ");
	scanf("%d",&m);
	printf("Enter the no. of columns: ");
	scanf("%d",&n);
	read(a,m,n);
	display(a,m,n);
	max_min(a,m,n);
	return 0;
}
