#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int elem;
	struct node *left, *right;
	int height;
}*BST, nodeType;

void insert(BST *B, int x);

int main()
{
	BST B;
	B = NULL;
	insert(&B, 1);

	return 0;
}

void insert(BST *B, int x)
{
	if((*B)==NULL){
		(*B) = (BST)malloc(sizeof(nodeType));
		(*B)->elem = x;
		(*B)->left = (*B)->right = NULL;
	} 
	if(x < (*B)->elem){
		insert(&(*B)->left, x);
	}else if(x > (*B)->elem){
		insert(&(*B)->right, x);
	}
	
	(*B)->height = 1+max(height((*B)->left), ((*B)->right));
	
	int balance;
	balance = getBalance((*B));
	
	
	
}

int max(int x, int y)
{
	return (x > y)?x:y;
}

int height(BST B)
{
	return (B==NULL)?0:B->height;
}

int getBalance(BST B)
{
	if(B==NULL){
		return 0;
	}
	return height(B->left) - height(B->right);
}
