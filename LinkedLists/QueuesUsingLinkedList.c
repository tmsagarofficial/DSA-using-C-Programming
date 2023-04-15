//QUEUES USING SINGLY LINKED-LIST

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
void del_beg();
void main()
{
	int ch;
	printf("[1].ENQUEUE\n[2].DEQUEUE\n[3].DISPLAY\n\n\n");
	printf("\nEnter your choice:");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		create();
		display();
		break;

	case 2:del_beg();
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
		printf("\nList empty\n\n");
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


void del_beg() {
	struct node* temp = start;
	if (start == NULL)
	{
		printf("\nList empty\n");
		main();
	}
	else {
		temp = start;
		start = start->next;
		free(temp);
	}
}
