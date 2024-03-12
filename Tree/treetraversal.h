#include<stdio.h>

//display
void preorder(BSTnode *root)
{
	BSTnode *temp=root;
	if(temp!=NULL)
	{
		preorder(temp->left);
		printf("%d\t",temp->data);
		preorder(temp->right);
	}
}

void inorder(BSTnode *root)
{
	BSTnode *temp=root;
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d\t",temp->data);
		inorder(temp->right);
	}
}

void postorder(BSTnode *root)
{
	BSTnode *temp=root;
	if(temp!=NULL)
	{
		printf("%d\t",temp->data);
		postorder(temp->left);
		postorder(temp->right);
		
	}
}


