//PATTERN MATCHING 

#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int i = 0, j = 0;
int main() {

    char str1[100], str2[100];
    printf("Enter the string:");
    gets(str1);
    printf("Enter the pattern:");
    gets(str2);

    int l1 = strlen(str1);
    int l2 = strlen(str2);

    for (i = 0; str1[i] != '\0'; i++) {
        if (str2[j] == str1[i]) {
            for (j = 0; j<l2; j++) {
                i++;
            }

            break;
        }

    }
    printf("Pattern found at %d", i - l2 + 1);

}