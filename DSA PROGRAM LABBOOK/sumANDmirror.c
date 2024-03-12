//SET C
/*  a) Write a C program which uses Binary search tree library 
     and implements following two 
	 int sumodd(T) - returnssum of all odd numbers from BST
	intsumeven(T)- returnssum of all even numbers from BST 
	mirror(T)-converts given tree into its mirror image.   */

#include<stdio.h>
#include<stdlib.h>
#include "btree.h"

int sumbst(BSTnode *root)
{
	static int sum=0;
	BSTnode *temp=root;
	if(temp!=NULL)
	{
		sum+=temp->data;
		sumbst(temp->left);
		sumbst(temp->right);
	}
	return sum;
}

int sumeven(BSTnode *root)
{
	static int sume=0;
	BSTnode *temp=root;
	if(temp!=NULL)
	{
		if(temp->data%2==0)
			sume+=temp->data;
		sumeven(temp->left);
		sumeven(temp->right);
	}
	return sume;
}

int sumodd(BSTnode *root)
{
	static int sumo=0;
	BSTnode *temp=root;
	if(temp!=NULL)
	{
		if(temp->data%2!=0)
			sumo+=temp->data;
		sumodd(temp->left);
		sumodd(temp->right);
	}
	return sumo;	
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
	BSTnode *root=NULL,*root1=NULL;
	root=create(root);
	printf("\n");
	printf("Sum Of All Nodes is : %d\n",sumbst(root));
	printf("Sum Of Even Elements Nodes Is : %d\n",sumeven(root));
	printf("Sum Of Odd Elements Nodes Is : %d\n",sumodd(root));
	root1=mirror(root);
	printf("Mirror Tree Is :\n");
	inorder(root1);
	return 0;
}
