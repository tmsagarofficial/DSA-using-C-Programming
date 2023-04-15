//QUEUE OPERATIONS

#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#define MAX 5
void insertion();
void deletion();
void display();

int r = -1, f = 0, Q[100], data;
void main() {
	int choice = -1;
	printf("QUEUE OPERATION\n\n");

label1:
	printf("\n\nEnter ur choice: [1].ENQUEUE\t[2].DEQUEUE\t[3].DISPLAY=>?");
	scanf("%d", &choice);
	switch (choice) {
	case 1: {

		insertion();
		display();
		break;
	}
	case 2:deletion();
		display();
		break;
	case 3:display();
		break;
	default:printf("Invalid choice");
			break;
	}
	goto label1;



}
void deletion() {
	if (f > r)
		printf("\n UnderFlow \n");
	else {
		data = Q[f];
		f++;
		printf("Deleted element is %d\n",data);

	}
}
void insertion() {
	if (r >= MAX-1)
		printf("\n OverFlow \n");
	else {
		printf("Enter element to be inserted to the QUEUE ");
		scanf("%d", &data);
		r++;
		Q[r] = data;

	}
}
void display() {
	for (int i = f; i <= r; i++) {
		printf("%d\t",Q[i]);
	}
}
