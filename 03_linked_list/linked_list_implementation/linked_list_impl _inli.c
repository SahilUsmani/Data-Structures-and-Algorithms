/* LINKED LIST IMPLEMENTAION */

#include<stdio.h>
#include<stdlib.h>
void insert_at_beg(int);
void insert_at_end(int);
void insert_before(int, int);
void travel_forward(void);
void travel_backward(void);
int delete_at_beg(void);
int delete_at_end(void);
void delete_specific(int);
void insert_list(int);
void menu(void);

struct node{
	int data;
	struct node* next;
};

struct node *list;
struct node *current;
//struct node *temp;
//temp = (struct node*)malloc(sizeof(struct node));

void main()
{
	list = NULL;
	//current = list;
//	temp = (struct node*)malloc(sizeof(struct node));
	menu();
}

void insert_at_beg(int ele)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = ele;
	temp->next = list;
	list = temp;
}

void insert_at_end(int ele)
{
	if(list!=NULL)
	{
		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));
	
		current = list;

		while(current!=NULL)
			current = current->next;

		temp->data = ele;
		temp->next = current->next;
		current->next = temp;
	}
	else
		printf("The List is Empty\n");
}

void insert_before(int sele, int ele)
{
	if(list!=NULL){
		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));
		if(list->data == sele)
		{
			temp->data = ele;
			temp->next = list;
			list = temp;
		}
		else
		{
			current = list;

			while(current!=NULL && current->next->data!=sele)
				current = current->next;
		
			if(current->next == NULL)
				printf("Element not found\n");
			else
			{
				temp->data = ele;
				temp->next = current->next;
				current->next = temp;
			}
		}
	}
	else
		printf("The List is Empty\n");

}	

void insert_after(int sele, int ele)
{
	if(list!=NULL)
	{
		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));

		current = list;
		while(current!=NULL && current->data==sele)
			current = current->next;

		if(current->data != sele)
			printf("Element not found\n");
		else
		{
			temp->data = ele;
			temp->next = current->next;
			current->next = temp;
		}
	}
	else
		printf("The List is Empty\n");
}

void travel_forward(void)
{
	if(list!=NULL)
	{
		current = list;
		while(current!=NULL)
		{
			printf("%d ", current->data);
			current = current->next;
		}
	}
	else
		printf("The List is Empty\n");
}

void travel_backward(void)
{

}

int delete_at_beg(void)
{
	int x = -1;

	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));

	if(list!=NULL)
	{
		struct node *temp;
		temp = list;
		x = temp->data;
		list = NULL;
		free(temp);
	}

	return x;
}

int delete_at_end(void)
{
	int x = -1;
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));

	if(list!=NULL){
		if(list->next == NULL)
		{
			temp = list;
			x = temp->data;
			list = temp->next;
			free(temp);	
		}
		else
		{
			current = list;
			while(current->next->next!=NULL)
				current = current->next;
			temp = current->next;
			x = temp->data;
			current->next = NULL;
			free(temp);
		}
	}
	return x;
}

void delete_specific(int ele)
{
//	int x = -1;

	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	
	if(list!=NULL)
	{
		if(list->data == ele)
		{
			temp = list;
//			x = temp->data;
			list = temp->next;
			free(temp);
		}
		else
		{
			current = list;
			while(current->next!=NULL && current->next->data!=ele)
				current = current->next;
			if(current->next == NULL)
				printf("Element not found\n");
			else
			{
				temp = current->next;
//			x = temp->data;
				current->next = temp->next;
				free(temp);
			}
		}
	}
//	return x;				
}

/*void insert_list(int ele)
{
	struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
	if(list==NULL)
        {
        	temp->data = ele;
        	temp->next = NULL;
        	list = temp;       
        }
        else
	{
                current = list;
                while(current!=NULL)
                        current = current->next;

                temp->data = ele;
                temp->next = NULL;
                current->next = temp;
	}
}*/

void menu()
{
int n, ele, sele;
	while(1)
	{
		printf("\nEnter 1 to insert your data into the list\n");
		printf("\nEnter 2 to Display the contents of the list\n");
		printf("\nEnter 3 to insert your data at the begining\n");
		printf("\nEnter 4 to insert your data at the end\n");
		printf("\nEnter 5 to display front element\n");
		printf("\nEnter 6 to display rear element\n");
		printf("\nEnter 9 to exit the program\n");
		scanf("%d", &n);
		
		switch(n)
		{
			case 1:
				printf("Enter your Data: ");
				scanf("%d", &ele);
				insert_list(ele);
//
				break;
			case 2:
				printf("The contents of the list are:\n");
				travel_forward();
				break;
			case 3:
				printf("Enter your Data: ");
				scanf("%d", &ele);
				insert_at_beg(ele);
				
				break;
			case 4:	
				printf("Enter your Data: ");
				scanf("%d", &ele);
				insert_at_end(ele);
				break;
			/*case 5: 
				printf("The front element is %d\n", qfront());
				break;
			case 6:
				printf("The rear element is %d\n", qrear());
				break;*/
			case 9: 
				exit(0);
			default:
				printf("You have entered invalid input\n");
		}	
		
	}
	return;
}
