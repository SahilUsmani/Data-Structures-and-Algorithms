/* STACK IMPLEMENTATION (LIFO) */

#include<stdio.h>
void push(int);
int pop(void);
int peek(void);
int IsEmpty(void);
int IsFull(void);
void Display(void);
struct stack1{
//	int s[]; writing this here gives error: flexible array member not at the end of struct
	int size;
	int tos;
	int s[];
}sta;

//struct stack1 sta;
void main()
{
	sta.size;
	sta.tos = -1;
	printf("Enter the size of the stack: ");
	scanf("%d", &sta.size);
	sta.s[sta.size];

	for(int i=0; i<sta.size; i++)
	{
		int j;
		printf("Enter the Element no. %d: ", i+1);
		scanf("%d", &j);
		push(j);
	}

	Display();
	
	printf("The Top of Stack is: %d\n", peek());
	pop();
	return;
}

void push(int element)
{	
	if(!IsFull())
	{	
		sta.tos++;
		sta.s[sta.tos] = element;
		// (or we can write above two lines like this - sta.s[++sta.tos] = element;
	//	printf("The Pushed Element is %d\n", sta.s[sta.tos]);
	}
	else
	{
		printf("The Stack is full\n");
	}
}

int pop()
{	
	int x = -1;
	if(!IsFull())
	{
		x = sta.s[sta.tos];
		sta.tos--;
	}
	else
		printf("The Stack is Empty\n");
	return x;
}

int peek()                                  // To Display the Top of Stack
{
	int x = -1;
	if(!IsEmpty())
	{
		x = sta.s[sta.tos];
	}
	else
		printf("The Stack is Empty\n");
	return x;
}
int IsEmpty(void)
{
	if(sta.tos == -1)
		return 1;
	return 0;
}

int IsFull(void)
{
	if(sta.tos==(sta.size-1))
		return 1;
	return 0;
}

void Display(void)
{
	if(!IsEmpty())
	{
		for(int i=0; i<sta.size; i++)
		{
			printf("Element at index %d is %d\n", i, sta.s[i]);
		}
	}
	else
		printf("The Stack is Empty\n");
}
