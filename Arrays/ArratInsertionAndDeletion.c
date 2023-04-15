//ARRAY INSERTION AND DELETION

#pragma warning(disable:4996)
#include<stdlib.h>
#include<stdio.h>
void main()
{
    int a[50], n, i, pos, ele, choice = 0;
    printf("Enter the number of elements in the array:");
    scanf_s("%d", &n);
    printf("Enter the elements in an array:");
    for (i = 0; i < n; i++)
    {
        printf("a[%d]=",i);
        scanf_s("%d", &a[i]);
    }
    printf("\nInsertion Operation\n");
    printf("\nEnter the element to be inserted:");
    scanf_s("%d", &ele);
    printf("\nEnter your choice:\n[1].Insert an element at the beginning\n[2].Insert an element at a desired position\n[3].Insert an element at the end\n");
    scanf_s("%d", &choice);
    switch (choice)
        case 1:
    {

        {
            for (i = n - 1; i >= 0; i--)
            {
                a[i + 1] = a[i];
            }
            a[0] = ele;
            n++;
            break;
        }
        case 2:
        {
            printf("Enter the position to insert the element:");
            scanf_s("%d", &pos);
            for (i = n - 1; i >= pos - 1; i--)
            {
                a[i + 1] = a[i];
            }
            a[pos - 1] = ele;
            n++;

            break;
        }
        case 3:
        {
            a[n] = ele;
            n++;
            break;
        }
    }
    printf("The array after Insertion of the element %d is :",ele);
    for (i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
    printf("\n\nDeletion operation\n");
    printf("\nEnter your choice:\n1.at the beginning\n2.at desired position\n3.at the end\n");
    scanf_s("%d", &choice);
    switch (choice)
        case 1:
    {

        {
            a[0] = 0;
            for (i = 0; i <= n; i++)
            {
                a[i] = a[i+1];
            }

            n--;
            break;
        }
        case 2:
        {
            printf("Enter the position to delete the element:");
            scanf_s("%d", &pos);
            for (i = pos-1; i <=n - 1; i++)
            {
                a[i] = a[i+1];
            }

            n--;

            break;
        }
        case 3:
        {
            a[n] = 0;
            n--;
            break;
        }
    }
    printf("The array after Deletion of the element is : ");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
    printf("\n\n\n");
}