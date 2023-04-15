//HASH TABLE

//Given a file of n employee records with a set of k of fees(4 digit) which uniquely determine the records in file f.
//Assume that file f is maintained in memory by a hash table HT of m memory locations with the L as the set of memory locations with L as the set of memory addresses 2 digit of locations in the HT.
//Let the keys in K and address in the HT. Let the keys in K and address in L are integers . Design and develop a program in C uses a hash function 
//H: K % L as H(K)=K % m. and implement hashing technique to map a given key K to the address space L. resolve the collision if any using linear probing.

#pragma warning(disable:4996)
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
struct record {
	char name[20];
	int id, flag;
}HT[10];

int hash(int key) {
	int value, slots = 10;
	value = key % slots;
	return value;
}

void main() {
	FILE* in;
	int i, j, k, n, id, loc, flag;
	char name[20];

	printf("Enter the number of records less than or equal to 10");
	scanf("%d",&n);
	in = fopen("input.txt","r");
	if (n <= 10) {
		for (k = 0; k < 10; k++) {
			HT[k].flag = 0;
		}
		for (i = 0; i < n; i++) {
			fscanf(in,"%d %s",&id,name);
			loc = hash(id);
			if (HT[loc].flag == 0) {
				printf("The address of %d record is %d\n",i+1,loc);
				strcpy(HT[loc].name, name);
				HT[loc].id = id;
				HT[loc].flag = 1;
			}
			else {
				printf(" Collision detected \n");
				for (j = loc + 1; (j % 10) < 10; j++) {
					if (!HT[j % 10].flag) {
						printf("The address of %d record is %d\n", i + 1, j%10);
						strcpy(HT[j % 10].name, name);
						HT[j % 10].id = id;
						HT[j % 10].flag = 1;
						break;
					}
				}
			}
		}
		fclose(in);
		printf("The hash table contents are\n");
		for(k=0;k<10;k++){
			if (HT[k].flag == 0)
				printf("\n #\t# \n");
			else
				printf(" %d\t%s \n",HT[k].id,HT[k].name);



		}
	}

}
