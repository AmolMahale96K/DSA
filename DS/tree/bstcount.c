//SET A
/* b) Write a program which uses binary search tree library
 and counts the total nodes and total eaf nodes in the tree.
    int count(T) - returns the total number of nodes from BST 
	int countLeaf(T) - returns the total number of leaf nodes from BST    */
#include<stdio.h>
#include<stdlib.h>
#include "btree.h"
int countnodes(BSTnode *root)
{
	static int count=0;
	BSTnode *temp=root;
	if(temp!=NULL)
	{
		count++;
		countnodes(temp->left);
		countnodes(temp->right);
	}
	return count;
}

int countleaf(BSTnode *root)
{
	static int leaf=0;
	BSTnode *temp=root;
	if(temp!=NULL)
	{
		if((temp->left==NULL) && (temp->right==NULL))
			leaf++;
			countleaf(temp->left);
			countleaf(temp->right);
	}
	return leaf;
} 

int main()
{
	BSTnode *root=NULL;
	int choice;
	root=create(root);
	do
	{
	printf("\n\n");
	printf("1) Count Nodes \n");
	printf("2) Count Leaf Nodes \n");
	printf("Enter Your Choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
			case 1:
				printf("Total Nodes Of Tree Is : %d",countnodes(root));
				break;
				
			case 2:
				printf("Total Leaf Node In Tree : %d",countleaf(root));
				break;
			case 3:
				exit(0);	
				
		}
	}while(choice!=3);
	return 0;
}
