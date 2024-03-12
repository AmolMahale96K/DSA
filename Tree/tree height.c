#include<stdio.h>
#include<stdlib.h>
#include "btree.h"
int height(BSTnode *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return(1+max(height(root->left),height(root->right)));
	}
}
int max(int x,int y)
{
	if(x>y)
	{
		return x;
	}
	else
		return y;
}

void printSpacing(int count) 
{
	int i;
    for (i = 0; i < count; i++) 
	{
        printf(" ");
    }
}

void printTree(BSTnode *root, int level) {
    if (root == NULL) {
        return;
    }
    printTree(root->right, level + 1);
    printSpacing(level * 4);
    printf("%d\n", root->data);
    printTree(root->left, level + 1);
}




int main()
{
	int h;
	BSTnode *root=NULL;
	root=create(root);
	h=height(root);
	printf("\n");
	printf("Height Of Tree Is : %d",h);
	printf("\n");
	printf("Binary Search Tree In Pictorial Form : \n");
	printTree(root,2);
	return 0;
}
