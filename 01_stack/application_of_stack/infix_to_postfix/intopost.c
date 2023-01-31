#include<stdio.h>
#include<string.h>
char IsEmpty();
char Isfull();
//void Display();
void push(char);
char pop();
int peek();
int prec(char);

struct stack{
	int size;
	char tos;
	char s[];
}sta;

char IsEmpty()
{
	if(sta.tos==-1)
		return 1;
	return 0;
}

char IsFull()
{
	if(sta.tos==sta.size-1)
		return 1;
	return 0;
}

/*void Display()
{int i=0;
	if(!IsEmpty())
	{
		for(;i<=sta.tos;i++)
		{
			printf("Element at %d is %c",i,sta.s[i]);
		}
	}
	else
		printf("Stack is Empty\n");
}*/

void push(char element)
{
	if(!IsFull())
	{
		sta.s[++sta.tos]=element;
		printf("Pushed element: %c\n",sta.s[sta.tos]);
	}
	else
		printf("Stack is Full\n");
}

char pop()
{char x;
	if(!IsEmpty())
	{
		x=sta.s[sta.tos];
		sta.tos--;
	}
	else
		printf("Stack is Empty\n");
	return x;
}

int peek()
{int x=-1;
	if(!IsEmpty())
	{
		x=sta.s[sta.tos];
	}
	else
		printf("Stack is Empty\n");
	return x;
}

int prec(char ch)
{switch(ch)
	{
		case'*':
		case'/':
			return 3;
		case'+':
		case'-':
			return 2;
		case'(':
		case'[':
		case'{':
			return 1;
	}
}

void main()
{
	sta.size;
	sta.tos=-1;
	printf("Enter the number of element:");
	scanf("%d",&sta.size);
	sta.s[sta.size];
	int i,count=0,len;
	char ch,j=0,p,infix[50],postfix[50];
	printf("Enter the expression:");
	scanf("%s",infix);
	len=strlen(infix);
	printf("Length of the string: %d\n",len);
	for(i=0;i<len;i++)
	{ch=infix[i];
		switch(ch)
		{
			case'(':
			case'[':
			case'{':
				push(ch);
				break;
			case')':
			case']':
			case'}':
				while(1)
				{
					p=pop();
					if(p=='('||p=='['||p=='{')
						break;
					postfix[j++]=p;
					printf("%c\n",p);
				}
				break;
			case'*':
			case'+':
			case'-':
			case'/':
				while(!IsEmpty()&&prec(peek())>=prec(ch))
				{
						postfix[j++]=pop();
						printf("%c\n",pop());
				}

				push(ch);
				break;
			default:
			       postfix[j++]=ch;
			       printf("Postfix: %c\n",ch);
		}

	}
	while(!IsEmpty())
		postfix[j++]=pop();
	        printf("%c\n",pop());
	//postfix[j++]=pop();
	postfix[j++]='\0';
	printf("Postfix Expression is: ");
	for(i=0;i<=len-1;i++)
	{
		printf("%c",postfix[i]);
	}
	printf("\n");
}
			
