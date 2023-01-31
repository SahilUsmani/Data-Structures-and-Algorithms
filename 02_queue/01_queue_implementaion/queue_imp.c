/* Queue Implementation (FIFO) */

#include<stdio.h>
#include<stdlib.h>
int underflow(void);
int overflow(void);
void display(void);
void enque(int);
int deque(void);
void menu();
int qfront();
int qrear();

struct queue {
	int size;
	int front, rear;
	int q[];
}que;

void main()
{
	que.front=-1, que.rear=-1;
	que.size;

	printf("Enter the size of the queue: ");
	scanf("%d", &que.size);

	que.q[que.size];

	/*int n;
	printf("Enter 1 to see the size of Queue\n");
	printf("Enter 2 to Display the contents of the Queue\n");
	printf("Enter 3 to push an element into Queue\n");
	printf("Enter 4 to pop an element from Queue\n");
	do{
	scanf("%d", &n);
	}*/
	menu();
	return;
}

int qfront(void)
{
	return que.q[que.front];
}

int qrear()
{
	return que.q[que.rear];
}
int underflow(void)
{
	if(que.front==-1 && que.rear==-1)
		return 1;
	return 0;
}

int overflow(void)
{
	if(que.rear == que.size-1)
		return 1;
	return 0;
}

void display(void)
{
	if(!underflow())
	{
		for(int i=que.front; i<=que.rear; ++i)
		{
			printf("%d ", que.q[i]);
		}
		printf("\n");
	}
	else
		printf("The Queue is empty\n");
	return;
}

void enque(int ele)
{
	if(!overflow())
	{	if(que.front==-1 && que.rear==-1)
		{	
			que.front++;
		}
		que.rear++;
		que.q[que.rear] = ele;
	}
	else
		printf("Queue is Full\n");
	return;	
}

int dequeue(void)
{
	int x =-1;
	if(!underflow())
	{
		x = que.q[que.front];
		if(que.front == que.rear){
			que.front = -1;
			que.rear = -1;
		}
		else
	         	que.front++;
	}
	else
		printf("The Queue is empty\n");
	return x;
}

void menu()
{	
	int n;
	while(1)
	{
		printf("Enter 1 to see the size of Queue\n");
		printf("Enter 2 to Display the contents of the Queue\n");
		printf("Enter 3 to push an element into Queue\n");
		printf("Enter 4 to pop an element from Queue\n");
		printf("Enter 5 to display front element\n");
		printf("Enter 6 to display rear element\n");
		printf("Enter 9 to exit the program\n");
		scanf("%d", &n);
		
		switch(n)
		{
			case 1:
				printf("The size of the Queue is %d\n", que.size);
				break;
			case 2:
				printf("The contents of the Queue are:\n");
				display();
				break;
			case 3:
				for(int i=0; i<que.size; i++)
				{
					int j;
					printf("Enter the %d element of the array: ", i+1);
					scanf("%d", &j);
					enque(j);
				}
				break;
			case 4:	
				printf("The dequeued element is %d\n", dequeue());
				break;
			case 5: 
				printf("The front element is %d\n", qfront());
				break;
			case 6:
				printf("The rear element is %d\n", qrear());
				break;
			case 9: 
				exit(0);
			default:
				printf("You have entered invalid input\n");
		}	
	//	while(!(n==1||n==2||n==3||n==4));
			/*	{
					printf("Enter 1 to see the size of Queue\n");
					printf("Enter 2 to Display the contents of the Queue\n");
					printf("Enter 3 to push an element into Queue\n");
					printf("Enter 4 to pop an element from Queue\n");
				}*/	
	}
	return;
}





