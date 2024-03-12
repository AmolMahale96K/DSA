#include<stdio.h>
#include<stdlib.h>
#include "btree.h"
#include "treetraversal.h"

BSTnode *treecopy(BSTnode *root)
{
	BSTnode *newnode;
	if(root!=NULL)
	{
		newnode=(BSTnode*)malloc(sizeof(BSTnode));
		newnode->data=root->data;
		newnode->left=treecopy(root->left);
		newnode->right=treecopy(root->right);
		return newnode;
		
	}
	else
		return NULL;
}


BSTnode *mirror(BSTnode *root)
{
		BSTnode *temp=root,*temp1;
		if(temp!=NULL)
		{
			if(temp->left!=NULL)
				mirror(temp->left);
			if(temp->right!=NULL)
				mirror(temp->right);
			temp1=temp->left;
			temp->left=temp->right;
			temp->right=temp1;
					
		}
		return temp;
		
}


int main()
{
	BSTnode *root=NULL,*root1,*root3,*root4=NULL;
	root=create(root);
	root1=treecopy(root);
	printf(" 1st Tree is : \n");
	inorder(root);
	printf("\nCopy Tree IS : \n");
	inorder(root1);
	root3=mirror(root);
	printf("\nMirror Tree Is : \n");
	inorder(root3);
	
	return 0;
	
}
