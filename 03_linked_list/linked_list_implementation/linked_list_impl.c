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
void search(int);
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
	menu();

	return;
}



void insert_at_beg(int ele)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));

	temp->data = ele;
	temp->next = list;
	list = temp;

	return;
}



void insert_at_end(int ele)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));

	temp->data = ele;
	temp->next = NULL;

	if(list==NULL)
	{
		list = temp;
	}

	else
	{
		current = list;

		while(current->next!=NULL)
			current = current->next;

		current->next = temp;
	}
	return;
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

	return;
}




void insert_after(int sele, int ele)
{
	if(list!=NULL)
	{
		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));

		current = list;
		while(current!=NULL && current->data!=sele)
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

	return;
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
		printf("\n");
	}

	else
		printf("The List is Empty\n");

	return;
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
		list = temp->next;
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
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	
	if(list!=NULL)
	{
		if(list->data == ele)
		{
			temp = list;
			list = temp->next;
			free(temp);
			printf("The element %d is deleted\n", ele);
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
				current->next = temp->next;
				free(temp);
				printf("The element %d is deleted\n", ele);
			}
		}
	}
	else
		printf("The List is Empty\n");
	return;	
}


void search(int sele)
{
	current = list;

	while(current!=NULL && current->data!=sele)
		current = current->next;

	if(current->data==sele)
		printf("We've found the element\n");
	else
		printf("The element doesn't exist in the list\n");
	return;
}


void menu()
{
int n, ele, sele, r;
	while(1)
	{
		printf("Enter 1 to insert your data at the beginning\n");
		printf("Enter 2 to insert your data at the end\n");
		printf("Enter 3 to insert your data before an element\n");
		printf("Enter 4 to insert your data after an element\n");
		printf("Enter 5 to traverse forward\n");
		printf("Enter 6 to delete at the beginning\n");
		printf("Enter 7 to delete at the end\n");
		printf("Enter 8 to delete at a specific element\n");
		printf("Enter 9 to search an element\n");
		printf("Enter 0 to exit the program\n");
		scanf("%d", &n);
		
		switch(n)
		{
			case 1:
				printf("Enter your Data: ");
				scanf("%d", &ele);
				insert_at_beg(ele);
				break;

			case 2:
				printf("Enter your Data: ");
				scanf("%d", &ele);
				insert_at_end(ele);
				break;

			case 3:
				printf("Enter the element you want your data to be inserted before\n");
				scanf("%d", &sele);
				printf("Enter your Data: ");
				scanf("%d", &ele);
				insert_before(sele, ele);
				break;
			case 4:	
				printf("Enter the element you want your data to be inserted after\n");
				scanf("%d", &sele);
				printf("Enter your Data: ");
				scanf("%d", &ele);
				insert_after(sele, ele);
				break;

			case 5: 
				printf("The Contents of the list are:\n");
				travel_forward();
				break;

			case 6:
				r = delete_at_beg();
				if(r==-1)
					printf("The List is Empty\n");
				else
					printf("The deleted element is %d\n", r);
				break;
			case 7:
				r = delete_at_end();
				if(r==-1)
					printf("The List is Empty\n");
				else
					printf("The deleted element is %d\n", r);
				break;
			case 8:
				printf("Enter the element you want to delete: ");
				scanf("%d", &ele);
				delete_specific(ele);
				break;

			case 9: 
				printf("Enter the element you want to search: ");
				scanf("%d", &sele);
				search(sele);
				break;
			case 0: 
				exit(0);
			default:
				printf("You have entered invalid input\n");
				printf("\n");
				break;
		}	
		
	}
	return;
}
