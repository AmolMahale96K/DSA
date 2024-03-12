//node data wise comparison
#include<stdio.h>
#include "btree.h"

int isSameBST(BSTnode *root1, BSTnode *root2) 
{
    if (root1 == NULL && root2 == NULL) 
	{
        return 1;
    }
    if (root1 == NULL || root2 == NULL) 
	{
        return 0;
    }
    if (root1->data != root2->data)
	 {

        return 0;
    }
    return isSameBST(root1->left, root2->left) && isSameBST(root1->right, root2->right);
}

int  main()
{
	int ans;
	BSTnode *root=NULL,*root1=NULL;
	printf("Enter The First Tree : \n");
	root=create(root);
	printf("Enter The second Tree : \n");
	root1=create(root1);
	ans=isSameBST(root,root1);
	if(ans!=0)
		printf("Both Tree Same ");
	else
		printf("Tree NOt Same");
		
	return 0;
	
}
