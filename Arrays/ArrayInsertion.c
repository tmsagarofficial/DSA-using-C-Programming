//ARRAY INSERTION OPERATION

#include<stdio.h>
#pragma warning(disable:4996)
#include<math.h>
#include<stdlib.h>
int n, arr[100] = { 0 };
void insertatbeg();
void insertatpos();
void insertatend();
int main(){
        char choice;
        printf("\nEnter the eleber of elements of the array:");
        scanf("%d",&n);


        printf("\nStart entering the array elements: ");
        for (int i = 0; i < n; i++)
            scanf("%d",&arr[i]);

        printf("\nThe entered array elemnts are: \n");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
        label1:
            printf("\nEnter ur choice\n[1].Insert an element at the BEGGINING\n[2].Insert an element at a desired POSITION\n[3].Insert an element at the END\n[X].Exit\n");
            insertatbeg();



        return 0;
    }
void insertatbeg() {

    printf("Enter the element: ");
    int ele = scanf("%d", &ele);



    for (int i = n ; i >= 0; i--) {
    arr[i+1] = arr[i];

    }
    arr[0] = ele;
    n++;


    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertatpos() {
    printf("Enter the position to insert an element: ");
    int pos = scanf("%d", &pos);
    printf("Enter the element: ");
    int ele = scanf("%d", &ele);
    n++;


    for (int i = n - 1; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = ele;

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void insertatend() {
    printf("Enter the element: ");
    int ele = scanf("%d", &ele);
    n++;



    arr[n] = ele;

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}