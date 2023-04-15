//STACKS USING SINGLY LINKED-LIST


#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
}*start = NULL;

struct node* current = NULL;
void create();
void display();
void del_end();
void main()
{
	int ch;
	printf("[1].Push operation\n[2].Pop operation\n[3].Display\n\n");
	printf("\nEnter your choice:");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		create();
		display();
		break;

	case 2:del_end();
		display();
		break;

	case 3:
		display();
		break;

	default:
		printf("\nenter valid choice..!");
		main();
	}
}



void create()
{
	struct node* newnode;
	newnode = (struct node*)malloc(1 * sizeof(struct node));
	printf("Enter the data:");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
	if (start == NULL)
	{
		start = newnode;
		current = newnode;
	}
	else
	{
		current->next = newnode;
		current = newnode;
	}

}

void display()
{
	if (start == NULL)
	{
		printf("List empty\n\n");
		main();
	}
	else
	{
		struct node* temp = start;
		while (temp->next != NULL)
		{
			printf("| %d ", temp->data);
			temp = temp->next;
		}
		printf("| %d |", temp->data);
		printf("\n\n");
		main();
	}
}


void del_end()
{
	if (start == NULL)
	{
		printf("\nEmpty list..!");
		printf("\n");
		main();
	}
	struct node* temp = start, * temp1;
	temp1 = start;
	while (temp->next != NULL)
	{
		temp1 = temp;
		temp = temp->next;
	}
	if (temp == start)
		start = NULL;

	free(temp);
	temp1->next = NULL;
}

