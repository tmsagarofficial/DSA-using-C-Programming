//DOUBLY LINKED LIST

#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next,*prev;
}*start = NULL;

struct node* current = NULL;


void insertatb();
void insertatp();
void create();
void deleteatb();
void deleteate();
void display();



void main() {

	printf("Enter ur choice: \n[1].Insert @ beggining [2].Insert @ end [3].Insert @ pos \n[4].Delete @ beggining [5].Delete @ end [6].Display");
	int ch;
	scanf("%d",&ch);
	switch (ch) { 
		case 1:insertatb();
			display();
			break;
		case 2:
			create();
			display();
			break;
		case 3:
			insertatp();
			display();
			break;
		case 4:
			deleteatb();
			display();
			break;
		case 5:
			deleteate();
			display();
			break;
		case 6:display();
			break;
	}



}

void create() {

	struct node* nn;
	nn = (struct node*)malloc(1*sizeof(struct node));
	nn->next = NULL;
	nn->prev = NULL;
	printf("Enter the data");
	scanf("%d",&nn->data);
	if (start == NULL) {
		start = nn;
		current = nn;
	}
	else {
		nn->prev = current;
		current->next = nn;
		current = nn;
	}
}


void display() {
	if (start == NULL) {
		printf("Doubly Linked->list Empty");
		main();
	}
	else {
		struct node* current = start;
		while (current->next != NULL)
		{
			printf("%d->", current->data);
			current = current->next;
		}
		printf("%d",current->data);
		printf("\n\n");
		main();
	}

}

void insertatb() {
	struct node* nn;
	nn = (struct node*)malloc(1 * sizeof(struct node));

	if (start == NULL)
	{

		create();
	}
	else {
		printf("Enter the data:");
		scanf("%d", &nn->data);
		nn->next = start;
		start->prev = nn;
		start = nn;
	}
}

void insertatp() {
	struct node* current = start;
	struct node* nn;
	int pos;
	nn = (struct node*)malloc(1 * sizeof(struct node));
	if (start == NULL)
	{
		create();
	}
	else {
		printf("\nEnter the position:");
		scanf("%d", &pos);
		printf("\nEnter the data:");
		scanf("%d", &nn->data);
		for (int i = 1; i < pos - 1; i++) {
			current = current->next;
		}
		nn->prev = current;
		nn->next = current->next;
		current->next = nn;

	}
}

void deleteatb() {
	if (start == NULL) {
		printf("List empty!!!");
		main();
	}
	else {
		struct node* temp = start;
		temp = start;
		if (temp->next == NULL) {
			start = start->next;
			free(temp);
		}
		else {
			start = start->next;
			start->prev = NULL;
			free(temp);
		}

	}
}

void deleteate() {
	if (start == NULL) {
		printf("List empty!!!");
		main();
	}
	else {
		struct node* temp = start;
		temp = current;
		if (temp->prev == NULL)
		{
			start = NULL;
			free(temp);
			current = NULL;
		}
		else {
			current = current->prev;
			free(temp);
			current->next = NULL;

		}

	}
}