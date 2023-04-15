//DECIMAL TO BINARY CONVERSION

#include<stdio.h>
#pragma warning(disable:4996)
#define MAX 100
int pop();
void push(int);
void print();
int s[100] = { 0 }, top = -1, del, n, rem;
void main() {
    int ele;
    printf("Enter a decimal number to convert it into binary equivavlent");
    scanf("%d",&n);
    ele = n;
    while (n != 0) {
        rem = n % 2;
        push(rem);
        n = n / 2;
    }
    printf("DECIMAL:%d",ele);
    printf("\nBINARY:");
    while (top != -1)
        printf("%d", pop());
    printf("\n");

}

void push(ele) {
    if ((top + 1) == MAX)
        printf("\n\n :) STACK OVERFLOW\n\n");
    else{
        top++;
        s[top] = ele;

    }

}



int pop() {
    del=s[top];
    if (top == -1)
        printf(" :/ STACK UNDERFLOW");
    else {


        top--;
        return del;

    }

}