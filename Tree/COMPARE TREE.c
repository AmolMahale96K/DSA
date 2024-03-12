#include<stdio.h>
#include<stdlib.h>
#include "btree.h"
//compare Tree Function
int compare(BSTnode *root1,BSTnode *root2)
{
	if(root1==NULL && root2==NULL)
		return 1;
	else
		if(root1!=NULL && root2!=NULL)
				if(compare(root1->left,root2->left))
					return compare(root1->right,root2->right);
	return 0;
}


int main()
{
	BSTnode *root=NULL,*root1=NULL;
	int ans;
	printf("Enter The First Tree : \n");
	root=create(root);
	printf("\nEnter The Second Tree : \n");
	root1=create(root1);
	
	ans=compare(root,root1);
	if(ans!=0)
		printf("\nBoth tree are same");
	else
		printf("\nBoth Tree Are not same");
	return 0;
	
}
