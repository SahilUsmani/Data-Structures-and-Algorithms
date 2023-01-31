#include <stdio.h>
int main()
{
	int a[20][20];
	int r,c;
	int sum =0;
	printf("Enter rows,columns: ");
	scanf("%d,%d",&r,&c);
	printf("\nEnter elements of array");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			scanf("%d",&a[i][j]);
	}
	printf("\n Matrix:\n");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			printf("%d",a[i][j]);
		printf("\n");
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(i>j)
				sum = sum + a[i][j];
		}
	}
	printf("Sum of elements of lower triangular matrix = %d\n",sum);
	return 0;
}

