#include<stdio.h>
#include<stdlib.h>
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

int minvalue(BSTnode *root)
{
	BSTnode *temp=root;
	while(temp!=NULL && temp->left!=NULL)
		temp=temp->left;
	return temp->data;
}

int maxvalue(BSTnode *root)
{
	BSTnode *temp=root;
	while(temp!=NULL && temp->right!=NULL)
		temp=temp->right;
	return temp->data;
}

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

void sumeven(BSTnode *root)
{
	static int sume=0,sumo=0;
	BSTnode *temp=root;
	if(temp!=NULL)
	{
		if(temp->data%2==0)
			sume+=temp->data;
		else
			sumo+=temp->data;
			
		sumeven(temp->left);
		sumeven(temp->right);
	}
	printf("sum even = %d",sume);
	printf("odd = %d",sumo);
	
	
}
