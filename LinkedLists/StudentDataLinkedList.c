//STUDENT DATA LINKED LIST

#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

struct node {
	struct student {
		char name[20];
		int age, rollno;
	}S;
	struct node* next;
}*start = NULL;

struct node* current = NULL;
void create();
void display();
void insert_at_beg();
//void insert_at_pos();
void del_end();
void del_beg();
//void del_pos();
void search_list();
void main()
{
	int ch;
	printf("[1].Insert at the end\n[2].Insert at beginning\n[3].Deletion at the end\n[4].Deletion at the beginning\n[5].display\n[6].Search student\n\n");
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


	case 3:
		del_end();
		display();
		break;

	case 4:del_beg();
		display();
		break;

	case 5:
		display();
		break;

	case 6:search_list();
		display();
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
		printf("Enter the name:");
		scanf("%s", &newnode->S.name);
		printf("Enter the age:");
		scanf("%d", &newnode->S.age);
		printf("Enter the rollno:");
		scanf("%d", &newnode->S.rollno);
		newnode->next = start;
		start = newnode;
	}
}

void create()
{
	struct node* newnode;
	newnode = (struct node*)malloc(1 * sizeof(struct node));
	printf("Enter the name:");
	scanf("%s", &newnode->S.name);
	printf("Enter the age:");
	scanf("%d",&newnode->S.age);
	printf("Enter the rollno:");
	scanf("%d",&newnode->S.rollno);
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
			printf("[%s|%d|%d]->",temp->S.name, temp->S.age,temp->S.rollno);
			temp = temp->next;
		}
		printf("[%s|%d|%d]", temp->S.name, temp->S.age,temp->S.rollno);
		printf("\n\n");
		main();
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


void search_list() {
	struct node* temp = start;
	int data;
	printf("\nEnter the rollnumber to search:");
			scanf("%d", &data);
			for (int i = 0; data != temp->S.rollno; i++) {
				temp = temp->next;
			}

			if (data == temp->S.rollno) {
				printf("Student found !! :)\n\n[%s|%d|%d]\n\n", temp->S.name, temp->S.age, temp->S.rollno);

			}
			else
				printf("\n\nStudent not found with the given roll number\n\n");



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