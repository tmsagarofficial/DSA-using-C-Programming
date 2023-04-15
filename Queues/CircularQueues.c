//CIRCULAR QUEUES

#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#define MAX 5
void CQinsertion();
void CQdeletion();
void CQdisplay();
void CQdisplay1();

int r = -1, f = 0, CQ[100], data,c=0;
void main() {
	int choice = -1;
	printf("CIRCULAR QUEUE OPERATION\n\n");

label1:
	printf("\n\nEnter ur choice: [1].ENQUEUE\t[2].DEQUEUE\t[3].DISPLAY=>?");
	scanf("%d", &choice);
	switch (choice) {
	case 1: {
		CQinsertion();
		CQdisplay1();
		break;
	}
	case 2:CQdeletion();
		CQdisplay1();
		break;
	case 3:CQdisplay1();
		break;
	default:printf("Invalid choice");
		break;
	}
	goto label1;



}
void CQdeletion() {
	if (c==0)
		printf("\n UnderFlow \n");
	else {
		data = CQ[f];
		f=(f+1)%MAX;
		printf("deleted element is %d\n", data);
		c--;

	}
}
void CQinsertion() {
	if (c==MAX)
		printf("\n OverFlow \n");
	else {
		printf("Enter element to be inserted to the QUEUE ");
		scanf("%d", &data);
		r = (r+1) % MAX;
		CQ[r] = data;
		c++;

	}
}

void CQdisplay1() {
	int tt = f;
	if (c == 0)
		printf("Empty circular queue");
	else {
		while (tt != r) {
			printf("%d\t", CQ[tt]);
			tt = (tt + 1) % MAX;
		}
		printf("%d\t",CQ[r]);
	}
}


