//STACK OPERATIONS

#pragma warning(disable:4996)
#include<stdio.h>
#define MAX 5
int s[100], n, top = -1;
void push(int);
void pop();
void print();
void main()
{
	int choice, ele;
	do
	{
		printf("enter choice\n 1.push 2.pop\n 3.print 4.exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("enter the element to be pushed");
			scanf("%d",&ele);
			push(ele);
			print();
			break;
		case 2:
			pop();
			print();
			break;
		case 3:
			print();
			break;
		default:
			printf("invalid choice");
			break;
		}
	} while (choice != 4);
}
void pop()
{
	if (top == -1)
		printf("stack operations");
	else
	{
		int del;
		del = s[top];
		top--;
	}
}
void print()
{
	for (int i = top; i >= 0; i--)
		printf("%d", s[i]);
}
void push(int ele)
{
	if ((top + 1) == MAX)
		printf("stack operations");
	else
	{
		top++;
		s[top] = ele;

	}
}
