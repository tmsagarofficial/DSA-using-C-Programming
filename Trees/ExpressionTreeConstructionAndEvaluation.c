//EXPRESSION TREE CONSTRUCTION AND EVALUATION

#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node {
	char data;
	struct node* rlink;
	struct node* llink;
}*root = NULL;
typedef struct node* NODE;

NODE getnode()
{
	NODE temp = (NODE)malloc(sizeof(struct node));
	return temp;
}

NODE create_tree(char postfix[])
{
	NODE temp, st[30];
	int i, k;
	char symbol;
	for (i = k = 0; (symbol = postfix[i]) != '\0'; i++)
	{
		temp = getnode();
		temp->data = symbol;
		temp->llink = temp->rlink = NULL;
		if (isalnum(symbol))
			st[k++] = temp;
		else
		{
			temp->rlink = st[--k];
			temp->llink = st[--k];
			st[k++] = temp;
		}
	}
	return st[--k];
}


void postorder(NODE cur)
{
	if (cur == NULL)return;
	postorder(cur->llink);
	printf("%c,", cur->data);
	postorder(cur->rlink);

}

float eval(NODE root)
{
	float num;
	switch (root->data)
	{
	case '+':
		return eval(root->llink) + eval(root->rlink);

	case '-':
		return eval(root->llink) - eval(root->rlink);

	case '/':
		return eval(root->llink) / eval(root->rlink);

	case '*':
		return eval(root->llink) * eval(root->rlink);

	case '$':
	case '^':
		return pow(eval(root->llink), eval(root->rlink));

	default:
		if (isalpha(root->data))
		{
			printf("%c=", root->data);
			scanf("%f", &num);
			return num;
		}
		else
		{
			return root->data - '0';
		}
	}
}

void main()
{
	printf("\nEnter the postfix expression : ");
		char l[20];
		gets(l);
		root = create_tree(l);
		printf("\nThe Inorder traversal of Tree : ");
		postorder(root);

		float res=eval(root);
		printf("\nThe Evaluated Expression of the Tree is : %f",res);
}