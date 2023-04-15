//REPLACE VALUE OF KTH NODE WITH X

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
void insert_at_beg();
void insert_at_pos();
void del_end();
void del_beg();
void del_pos();
void kthnodex();
void main()
{
	int ch;
	printf("[1].Insert at the end\n[2].Insert at beginning\n[3].Insert at position\n[4].Deletion at the end\n[5].Deletion at the beginning\n[6].Deletion at a position\n[7].display\n[8].Replace Kth field with X\n\n");
	printf("\nEnter your choice:");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		create();
		display();
		break;

	case 2:
		insert_at_beg();
		display();
		break; 

	case 3:insert_at_pos();
		display();
		break;

	case 4:del_end();
		display();
		break;

	case 5:del_beg();
		display();
		break;

	case 6:del_pos();
		display();
		break;

	case 7:
		display();
		break;

	case 8:kthnodex();
		break;

	default:
		printf("\nenter valid choice..!");
		main();
	}
}

void insert_at_beg()
{
	struct node* newnode;
	newnode = (struct node*)malloc(1 * sizeof(struct node));

	if (start == NULL)
	{
		create();
	}
	else
	{
		printf("Enter the data:");
		scanf("%d", &newnode->data);
		newnode->next = start;
		start = newnode;
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
			printf("%d->", temp->data);
			temp = temp->next;
		}
		printf("%d", temp->data);
		printf("\n\n");
		main();
	}
}

void insert_at_pos() {
	struct node* temp = start;
	struct node* newnode;
	int pos;
	newnode = (struct node*)malloc(1 * sizeof(struct node));
	if (start == NULL)
	{
		create();
	}
	else {
		printf("\nEnter the position:");
		scanf("%d", &pos);
		printf("\nEnter the data:");
		scanf("%d", &newnode->data);
		for (int i = 0; i < pos - 1; i++) {
			temp = temp->next;
		}

		newnode->next = temp->next;
		temp->next = newnode;

	}
}

void del_beg() {
	struct node* temp = start;
	if (start == NULL)
	{
		printf("List empty");
		main();
	}
	else {
		temp = start;
		start = start->next;
		free(temp);
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

void del_pos()
{
	if (start == NULL)
	{
		printf("Empty list");
		return;
	}
	struct node* temp = start;
	int pos;
	printf("\nenter the position to insert:");
	scanf("%d", &pos);
	if (pos == 0)
	{
		if (start->next == NULL)
		{
			free(start);
			start = NULL;
			return;
		}
		else
		{
			free(start);
			start = start->next;
			return;
		}
	}

	for (int i = 0; i < pos - 1; i++)
	{
		if (temp->next == NULL)
		{
			printf("Invalid position");
			exit(0);
		}
		temp = temp->next;
	}
	temp->next = temp->next->next;
	free(temp->next);
}

void kthnodex() {
	struct node* temp = start;
	struct node* newnode;
	newnode= (struct node*)malloc(1 * sizeof(struct node));
	int pos;
	int x;

	printf("\nEnter the value of k:");
	scanf("%d", &pos);
	printf("\nEnter the data:");
	scanf("%d", &x);
	for (int i = 0; i!=temp->data; i++) {
		temp = temp->next;
	}
	newnode->next = temp->next;
	temp->next = newnode;

}
