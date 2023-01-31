#include<stdio.h>
#include<stdlib.h>

void menu(int*, int);
void display(int*, int);
void bubble(int*, int);

void main()
{
	int n, i;
	printf("Enter the size of the array: ");
	scanf("%d", &n);

	int arr[n];
	for(i=0; i<n; i++)
	{
		printf("Enter the no. %d element of the array: ", i+1);
		scanf("%d", &arr[i]);
	}

	menu(arr, n);

}

void menu(int a[], int size)
{
	int num;

	while(1)
	{
		printf("\n\nPress 1 to Display the array\n");
		printf("Press 2 to Bubble Sort the array\n");
		printf("Press 0 to Exit from the program\n");
		scanf("%d", &num);
		switch(num)
		{
			case 1:
				printf("\nThe Contents of the Array are:\n");
				display(a, size);
				break;

			case 2:
				bubble(a, size);
				printf("\nThe array has been Bubble Sorted\n");
				break;

			case 0:
				exit(0);
				break;

			default:
				printf("Invalid Input\n");
				break;

		}
	}
}

void display(int a[], int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("%d ",a[i]);
	}
}

void bubble(int a[], int size)
{
	int i, flag, j, temp;
	for(i=0; i<size-1; i++)
	{
		flag = 0;
		for(j=0;j<size-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;

				flag = 1;	
			}
		}
		if(flag==0)
			break;
	}
}
