/* STACK APPLICATION - BALANCING SYMBOLS */

#include<stdio.h>
#include<string.h>
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
	int s[50];
}sta;

//struct stack1 sta;
void main()
{
	sta.size = 50;
	sta.tos = -1;
	//printf("Enter the size of the stack: ");
	//scanf("%d", &sta.size);
	char ch, p, infix[sta.size];
	int i,len,flag;
	
	printf("Enter the expression:\n");
	scanf("%s", infix);

	len = strlen(infix);

	for(i=0; i<len; i++)
	{
		ch = infix[i];
		
		switch(ch)
		{
			case'(':
			case'{':
			case'[':
				push(ch);
				break;
			case')':
			case'}':
			case']':
				{
					if(!IsEmpty())
					{
						if((ch==')' && peek()=='(') || (ch=='}' && peek()=='{') || (ch==']' && peek()=='['))
							pop();
					}
					else
						flag=1;
				break;
				}
		}
		if(flag==1)
			break;
	}
	
	if(i==len && IsEmpty())
		printf("Expression is balanced\n");
	else
		printf("Expression is unbalanced\n");
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
