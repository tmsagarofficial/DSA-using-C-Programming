//POLYNOMIAL ADDITION

#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)
struct node
{
	int cf, px, py, pz;
	struct node* next;
}*head = NULL;
typedef struct node* NODE;




NODE getnode()
{
	NODE x;
	x = (NODE)malloc(sizeof(struct node));
	if (x == NULL)
	{
		printf("out of memory");
		exit(0);
	}
	return x;
}

NODE read_poly(NODE h)
{
	int i, n;
	int cf, px, py, pz;
	printf("Enter the number of terms: \n");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("Enter the cf and power of x,y,z: \n");
		scanf("%d%d%d%d", &cf, &px, &py, &pz);
		h = insert_rear(cf, px, py, pz, h);
	}
	return h;
}

NODE insert_rear(int cf, int px, int py, int pz, NODE head)
{
	NODE nn, temp;
	nn = getnode();
	nn->cf = cf;
	nn->px = px;
	nn->py = py;
	nn->pz = pz;
	temp = head->next;
	while (temp->next != head)
	{
		temp = temp->next;
	}
	temp->next = nn;
	nn->next = head;
	return head;
}


void display(NODE h)
{
	NODE temp = h->next;
	while (temp != h)
	{
		printf("%d x^%dy^%dz^%d", temp->cf, temp->px, temp->py, temp->pz);
		if (temp->next != h)
			printf(" + ");
		temp = temp->next;
	}
}

NODE Add_poly(NODE h1, NODE h2, NODE h3)
{
	NODE p1, p2;
	int cf1, px1, py1, pz1, sum;
	p1 = h1->next;
	while (p1 != h1)
	{
		cf1 = p1->cf;
		px1 = p1->px;
		py1 = p1->py;
		pz1 = p1->pz;
		p2 = search(p1, h2);
		if (p2 != h2)
		{
			sum = cf1 + p2->cf;
			h3 = insert_rear(sum, px1, py1, pz1, h3);
			p2->cf = -999;
		}
		else
		{
			h3 = insert_rear(cf1, px1, py1, pz1, h3);
		}
		p1 = p1->next;
	}
	h3 = Copy_poly(h2, h3);
	return h3;
}


NODE search(NODE p1, NODE h2)
{
	NODE temp = h2->next;
	while (temp != h2)
	{
		if (temp->px == p1->px && temp->py == p1->py && temp->pz == p1->pz)
		{
			break;
		}
		temp = temp->next;
	}
	return temp;
}



NODE Copy_poly(NODE h2, NODE h3)
{
	NODE temp = h2->next;
	int cf2, px2, py2, pz2;
	while (temp != h2)
	{
		if (temp->cf != -999)
		{
			cf2 = temp->cf;
			px2 = temp->px;
			py2 = temp->py;
			pz2 = temp->pz;
			h3 = insert_rear(cf2, px2, py2, pz2, h3);
		}
		temp = temp->next;
	}
	return h3;
}


void main()
{
	NODE h1, h2, h3;
	h1 = getnode();
	h2 = getnode();
	h3 = getnode();
	h1->next = h1;
	h2->next = h2;
	h3->next = h3;
	printf("Enter the first polynomial: \n");
	h1 = read_poly(h1);
	printf("Poly 1: ");
	display(h1);
	printf("\nEnter the second polynomial: \n");
	h2 = read_poly(h2);
	printf("\nPoly 2: ");
	display(h2);
	printf("\n");
	h3 = Add_poly(h1, h2, h3);
	printf("\nAdded poly: ");
	display(h3);
}