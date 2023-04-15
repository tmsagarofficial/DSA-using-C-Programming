//DOUBLE ENDED QUEUES

#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#define MAX 5
void insertionatr();//done
void deletionatr();//done
void insertionatf();//done
void deletionatf();//done
void display();

int r = -1, f = 0, Q[100], data;
void main() {
	int choice = -1;
	printf("QUEUE OPERATION\n\n");

label1:
	printf("\n\nEnter ur choice: [1].Insertion at front\t[2].Insertion at rear\t[3].Deletion at front\t[4].Deletion at rear\t[5].Display=>?");
	scanf("%d", &choice);
	switch (choice) {
	case 1: {

		insertionatf(data);
		display();
		break;
	}
	case 2: {

		insertionatr(data);
		display();
		break;
	}
	case 3: {
		deletionatf();
		display();
		break;
	}
	case 4: {
		deletionatr();
		display();
		break;
	}

	case 5:display();
		break;
	default:printf("Invalid choice");
			break;
	}
	goto label1;



}
void deletionatr() {//tt
	if (r==-1)
		printf("\n UnderFlow \n");
	else {
		data = Q[r];
		--r;
		printf("Deleted element is %d\n",data);

	}
}
void insertionatr() {//done
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

void deletionatf() {//done
	if (f > r)
		printf("\n UnderFlow \n");
	else {
		data = Q[f];
		++f;
		printf("Deleted element is %d\n", data);

	}
}
void insertionatf(int data) {
	if (f >= MAX - 1)
		printf("\n OverFlow \n");
	else {
		printf("Enter element to be inserted to the QUEUE ");
		scanf("%d", &data);
		f--;
		Q[f] = data;

	}
}