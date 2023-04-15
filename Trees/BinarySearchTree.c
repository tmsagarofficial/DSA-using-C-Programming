//BINARY SEARCH TREE

#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* right;
	struct node* left;
};

typedef struct node* NODE;

NODE getnode()
{
	NODE x;
	x = (NODE)malloc(sizeof(struct node));
	if (x == NULL)
	{
		printf("Out of memory\n");
		exit(0);
	}
	return x;
}

NODE insert(int item, NODE root)
{
	NODE temp, cur, prev;
	temp = getnode();
	temp->data = item;
	temp->right = NULL;
	temp->left = NULL;
	if (root == NULL)
	{
		return temp;
	}
	prev = NULL;
	cur = root;
	while (cur != NULL)
	{
		prev = cur;
		if (item < cur->data)
			cur = cur->left;
		else
			cur = cur->right;
	}
	if (item < prev->data)
		prev->left = temp;
	else
		prev->right = temp;
	return root;
}

NODE delete(int item, NODE root) {
	NODE cur, par, suc, q;
	if (root == NULL) {
		printf("Tree is empty! Item not found\n");
		return root;
	}
	par = NULL;
	cur = root;



while (cur != NULL) {
	if (item == cur->data)
		break;
	par = cur;
	if (item < cur->data)
		cur = cur->left;
	else
		cur = cur->right;
}
if (cur == NULL) {
	printf("Item not found.\n");
	return root;
}

if (cur->left == NULL)
q = cur->right;
else if (cur->right == NULL)
q = cur->left;
else {
	suc = cur->right;
	while (suc->left != NULL)
		suc = suc->left;
	suc->left = cur->left;
	q = cur->right;
}
if (par == NULL)
return q;

if (cur == par->left)
par->left = q;
else
par->right = q;
free(cur);
return root;
}

void inorder(NODE root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void postorder(NODE root)
{
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}

void preorder(NODE root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void big(NODE root)
{
	NODE temp = root;
	if (root == NULL)
	{
		printf("Tree is empty\n");
	}
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	printf("Biggest element:%d\n", temp->data);
}

void small(NODE root)
{
	NODE temp = root;
	if (root == NULL)
	{
		printf("Tree is empty\n");
	}
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	printf("Smallest element:%d\n", temp->data);
	printf("\n");
}

void search(int key, NODE root)
{
	if (root == NULL)
	{
		printf("Tree is empty\n");
	}
	else
	{
		NODE temp = root;
		while (temp != NULL)
		{
			if (temp->data == key)
			{
				printf("Element %d found\n", key);
				return;
			}
			else
			{
				if (key > temp->data)
					temp = temp->right;
				else
					temp = temp->left;
			}
		}
		printf("Element %d not found\n", key);
	}
	printf("\n");
}

void main()
{
	NODE root, cur;
	int ch, item, key, n, m, del;
	root = NULL;
	do {
		printf("[1].insert\n[2].preorder\n[3].postorder\n[4].inorder\n[5].search\n[6].biggest and smallest element in the tree\n[7].delete\n[8].exit\n");
		printf("Enter your choice:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter the data to be inserted:");
			scanf("%d", &item);
			printf("\n");
			root = insert(item, root);
			break;

		case 2:
			if (root == NULL)
			{
				printf("Tree is empty\n");
				break;
			}
			printf("Preorder traversal is\n");
			preorder(root);
			printf("\n\n");
			break;

		case 3:
			if (root == NULL)
			{
				printf("Tree is empty\n");
				break;
			}
			printf("Postorder traversal is\n");
			postorder(root);
			printf("\n\n");
			break;

		case 4:
			if (root == NULL)
			{
				printf("Tree is empty\n");
				break;
			}
			printf("Preorder traversal is\n");
			inorder(root);
			printf("\n\n");
			break;

		case 5:
			printf("Enter key:");
			scanf("%d", &key);
			search(key, root);
			printf("\n");
			break;

		case 6:
			big(root);
			small(root);
			break;

		case 7:printf("Enter the element to delete :");
			scanf("%d", &del);
			delete(del, root);
			break;
		case 8:
			exit(0);

		default:
			printf("Enter valid choice..!\n");
		}
	} while (ch != 0);
}
