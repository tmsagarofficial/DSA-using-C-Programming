//DYNAMIC STACK

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
struct node
{
    int data;
    struct node* next;
};

struct node* top = NULL;

void display();
void push(int);
void pop();

int main()
{
    int n, ch;
    do
    {
        printf("\n\nDYNAMIC STACK OPERATIONS\n");
        printf("[1]. Push \n[2]. Pop\n[3]. Print\n[4]. Exit");
        printf("\nEnter Choice 0-3? : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element ");
            scanf("%d", &n);
            push(n);
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 3:
            display();
            break;
        }
    } while (ch != 0);
}

void push(int item)
{
    struct node* nptr = malloc(sizeof(struct node));
    nptr->data = item;
    nptr->next = top;
    top = nptr;
}

void display()
{
    struct node* t;
    t = top;
    while (t != NULL)
    {
        printf("\n%d", t->data);
        t = t->next;
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("\n\nStack is empty ");
    }
    else
    {
        struct node* t;
        t = top;
        top = top->next;
        printf("\n\n%d deleted", t->data);
        free(t);
    }
}

