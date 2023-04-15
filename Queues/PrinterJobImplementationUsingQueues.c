//PRINTER JOB QUEUE IMPLEMENTATION USING QUEUES

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
    printf("PRINTER JOB QUEUE\n\n");

label1:
    printf("\n\nEnter ur choice: [1].NEW JOB\t[2].PRINT NEXT\t[3].DISPLAY JOB QUEUE=>?");
    scanf("%d", &choice);
    switch (choice) {
    case 1: {

        insertion(data);
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
        printf("\n NO MORE JOBS LEFT \n");
    else {
        data = Q[f];
        f++;
        printf("JOB J-%d done\n", data);

    }
}
void insertion(int data) {
    if (r >= MAX - 1)
        printf("\n TOO MANY JOBS LEFT \n");
    else {
        printf("ENTER THE JOB ");
        scanf("%d", &data);
        r++;
        Q[r] = data;

    }
}
void display() {
    for (int i = f; i <= r; i++) {
        printf("J-%d\t", Q[i]);
    }
}