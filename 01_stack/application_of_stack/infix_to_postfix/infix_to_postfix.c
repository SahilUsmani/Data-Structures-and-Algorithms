/* STACK APPLICATION - INFIX TO POSTFIX*/

#include<stdio.h>
#include<string.h>
void push(char);
int pop(void);
int peek(void);
int IsEmpty(void);
int IsFull(void);
void Display(void);
int prec (char);

struct stack1{
//	int s[]; writing this here gives "error: flexible array member not at the end of struct"
	int size;
	int tos;
	int s[];
}sta;

//struct stack1 sta;
void main()
{
	sta.size;
	sta.tos = -1;
	printf("\nEnter the size of the stack: ");
	scanf("%d", &sta.size);
	sta.s[sta.size];

	char ch, p, infix[sta.size], postfix[sta.size];
	int i, j=0, len;
	printf("Enter the expression: ");
	scanf("%s",infix);
	len = strlen(infix);
	printf("\nLength of the string: %d\n",len);
	for(i=0; i<len; i++)
	{
		ch = infix[i];

		switch(ch)
		{
			case '(':
			case '[':
			case '{':
				push(ch);
				break;

			case ')':
			case ']':
			case '}':
				while(1)
				{
					p = pop();
					if(p == '(' || p == '[' || p == '{')
						break;
					postfix[j++] = p;
					printf("\nThe Popped Element is %c\n", p);
				}
				break;

			case '*':
			case '+':
			case '-':
			case '/':
				while(!IsEmpty() && prec(peek()) >= prec(ch))
				{
					p = postfix[j++] = pop();
					printf("\nThe Popped Element is %c\n", p);
				}

				push(ch);
				break;
			
			default:
				postfix[j++] = ch;
		}
	}
	while(!IsEmpty())
	{
		p = postfix[j++] = pop();
		printf("\nThe Popped Element is %c\n\n", p);
	}
	postfix[j++] = '\0';

	
	puts(postfix);
//	printf("\n");

}

void push(char element)
{	
	if(!IsFull())
	{	
		sta.tos++;
		sta.s[sta.tos] = element;
		// (or we can write above two lines like this - sta.s[++sta.tos] = element;
		printf("\nThe Pushed Element is %c\n", sta.s[sta.tos]);
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

int prec(char ch)
{
	switch(ch)
	{
		case '*':
		case '/':
			return 3;

		case '+':
		case '-':
			return 2;

		case '(':
		case '[':
		case '{':
			return 1;
	}
}
