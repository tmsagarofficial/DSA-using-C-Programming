//CIRCULAR SINGLY LINKEDIST

#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
}*start = NULL;
struct node* current = NULL;
void insert_at_end();
void insert_at_beg();
void insert_at_pos();
void delete_at_beg();
void delete_at_end();
void delete_at_pos();
void display();

void main()
{
	int ch;
	do {
		printf("1.insert at beginning\n2.insert at end\n3.insert at pos\n4.delete at beginning\n5.delete at end\n6.delete at pos\n7.Display\n8.exit\n");
		printf("Enter your choice:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			insert_at_beg();
			display();
			break;

		case 2:
			insert_at_end();
			display();
			break;

		case 3:
			insert_at_pos();
			display();
			break;

		case 4:
			delete_at_beg();
			display();
			break;

		case 5:
			delete_at_end();
			display();
			break;

		case 6:
			delete_at_pos();
			display();
			break;

		case 7:
			display();
			break;

		case 8:
			exit(0);

		default:
			printf("\nEnter valid choice..!");
			main();
		}
	} while (ch != 0);
}

void insert_at_beg()
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
		start->next = start;
	}
	else
	{
		newnode->next = start;
		start = newnode;
		current->next = newnode;
	}
}

void insert_at_end()
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
		start->next = start;
	}
	else
	{
		current->next = newnode;
		current = newnode;
		newnode->next = start;
	}
}

void insert_at_pos()
{
	struct node* newnode;
	struct node* temp = start;
	int pos;
	newnode = (struct node*)malloc(1 * sizeof(struct node));
	if (start == NULL)
	{
		insert_at_end();
	}
	else
	{
		printf("\nenter the position to insert:");
		scanf("%d", &pos);
		printf("Enter the data:");
		scanf("%d", &newnode->data);
		for (int i = 0; i < pos - 1; i++)
			temp = temp->next;
		newnode->next = temp->next;
		temp->next = newnode;
	}
}

void delete_at_beg()
{
	if (start == NULL)
	{
		printf("\nEmpty list..!");
		exit(0);
	}
	else
	{
		if (start == current)
		{
			free(start);
			start = NULL;
			current = NULL;
		}
		else
		{
			struct node* temp = start;
			temp = start;
			start = start->next;
			current->next = start;
			free(temp);
		}
	}
}

void delete_at_end()
{
	if (start == NULL)
	{
		printf("\nEmpty list..!");
		printf("\n");
		main();
	}
	struct node* temp = start, * temp1;
	temp1 = start;
	while (temp->next != start)
	{
		temp1 = temp;
		temp = temp->next;
	}
	if (temp == start)
		start = NULL;
	free(temp);
	temp1->next = start;
}

void delete_at_pos()
{
	struct node* delete1;
	if (start == NULL)
	{
		printf("Empty list");
		return;
	}
	struct node* temp = start;
	int pos;
	printf("\nenter the position to delete:");
	scanf("%d", &pos);
	if (pos == 0)
	{
		delete_at_beg();
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
		{
			temp = temp->next;
		}
		delete1 = temp->next;
		temp->next = temp->next->next;
		free(delete1);
	}
}

void display()
{
	struct node* temp = start;
	if (start == NULL)
		printf("\nEmpty list..!");
	else
	{
		while (temp->next != start)
		{
			printf("%d\t", temp->data);
			temp = temp->next;
		}printf("%d\t", temp->data);
	}
	printf("\n\n");
}
