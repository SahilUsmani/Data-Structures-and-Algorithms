#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int pop();
int isempty();
int isfull();
void push(char element);
int peak();
void display();
int priority(char ch)
{
   switch(ch)
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
struct stack
{
   int s[50];
   int size;
   int tos;
};
struct stack stk;
int j=0;

int isempty()
{
  if(stk.tos==-1)
    {
      return 1;
    }
  else
  {
   return 0;
  }
}

int isfull()
{
  if(stk.tos==stk.size-1)
   {
     return 1;
   }
else
  {
    return 0;
  }
}



void push(char element)
{
    if(!isfull())
     {
       stk.tos++;
       stk.s[stk.tos]=element;
     }
    else
    {
      printf("stack is full");
    }
}

int pop()
{
   int x=-1;
   if(!isempty())
    {
       x=stk.s[stk.tos--];
    }
   else
   {
    printf("\n3");
   }
   return x;
}

int peak()
{
    int x=-1;
    if(!isempty())
    {
      x=stk.s[stk.tos];

    }
    else
    {
      printf("\n2");
    }
      return x;
}

void display(char *post)
 {
     if(!isempty())
      {
        for(int i=0;i<j;i++)
          {
             printf("\narray of stack:%c",post[i]);
          }
      }
       else
        {
           printf("\n");
        }
}


int main()
{
   int i,len;
   char ch,p;
   char post[30];
   char infix[30];
   stk.tos=-1;
   stk.size=20;
   printf("\nenter the expression:");
   scanf("%s",infix);
   len=strlen(infix);
   for(i=0;i<len;i++)
        {
             ch=infix[i];
             switch(ch)
               {
                 case '(':
                 case '{':
                 case '[':  push(ch);
                            break;
                 case ')':
                 case '}':
                 case ']':
                           while(i)
                            {
                              p=pop();
                              if(p=='('||p=='{'||p=='[')
                                break;
                              post[++j]=p;
                             }
                             break;
                case'*':
                case'+':
                case'-':
                case'/':
                         while((!isempty())&& (priority(peak())>=priority(ch)))
                            {
                               post[++j]=pop();
                            }

                              push(ch);
                                                 
                           break;
              default : post[++j]=ch;
                        break;
               }//end switch      
          }//forend
   while(!isempty())
    {
        post[++j]=pop();
    }
   post[++j]='\0';
   printf("postfix value:%s\n",post);
  
}//end

