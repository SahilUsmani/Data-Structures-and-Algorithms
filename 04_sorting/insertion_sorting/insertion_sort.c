#include<stdio.h>
#include<stdlib.h>

void menu(int[], int);
void display(int[], int);
void bubble(int[], int);
void selection(int[], int);
void insertion(int[], int);
void swap(int *, int *);
int partition(int[], int, int);
void quicksort(int[], int, int);

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
		printf("\nPress 1 to Display the array\n");
		printf("Press 2 to Bubble Sort the array\n");
		printf("Press 3 to Selection Sort the array\n");
		printf("Press 4 to Insertion Sort the array\n");
		printf("Press 5 to Quick Sort the array\n");
		printf("Press 0 to Exit from the program\n");
		scanf("%d", &num);
		switch(num)
		{
			case 1:
				printf("\nThe Contents of the Array are:\n");
				display(a, size);
				printf("\n");
				break;

			case 2:
				bubble(a, size);
				printf("\nThe array has been Bubble Sorted\n");
				break;

			case 3:
				selection(a, size);
				printf("\nThe array has been Selection Sorted\n");
				break;

			case 4:
				insertion(a, size);
				printf("\nThe array has been Insertion Sorted\n");
				break;

			case 5: 
				quicksort(a, a[0], a[size-1]);
				printf("\nThe array has been Quick sorted\n");
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
		/*	{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;

				flag = 1;	
			}*/
			{
				swap(&a[j], &a[j+1]);
				flag = 1;
			}
		}
		if(flag==0)
			break;
	}
}

void insertion(int a[], int size)
{
	int i, j, temp;
	for(i=1; i<size; i++)
	{
		j = i-1;
		temp = a[i];

		while(j>=0 && a[j]>temp)
		{
			a[j+1] = a[j];
			j--;
		}

		a[j+1] = temp;
	}	
}

void selection(int a[], int size)
{
	int i, j, loc;
	for(i=0; i<size-1; i++)
	{
		loc = i;
		for(j=i+1; j<=size-1; j++)
		{
			if(a[j]<a[loc])
				loc = j;
		}
		if(loc!=i)
		{
			swap(&a[i], &a[loc]);
		}
	}
}

int partition(int a[], int low, int high)
{
	int pivot = low;            // if I use pivot = a[low] it'll give segmentation error core dumped
	int start = low + 1;
	int end = high;

	if(start<end)
	{
		while(1)
		{
			while(a[start]<=a[pivot] && start<high)
				start++;
			while(a[end]>a[pivot])
				end--;
			if(start<end)
				swap(&a[start], &a[end]);
			else
				break;
		}
		swap(&a[pivot], &a[end]);
	}
	return end;
}

void quicksort(int a[], int low, int high)
{
	int j;
	if(low<high)
	{
		j = partition(a, low, high);
		quicksort(a, low, j-1);
		quicksort(a, j+1, high);	
	}
}

void swap(int *first, int *next)
{
	int temp;
	temp = *first;
	*first = *next;
	*next = temp;
}
