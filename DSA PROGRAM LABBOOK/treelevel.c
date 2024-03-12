//SET A
/*  a) Write a C program which uses Binary search tree library 
    and displays nodes at each level,
	 count of node at each level and total levels in the tree. */

#include<stdio.h>
#include "btree.h"
static int sum=0;
void displaylevel(BSTnode *root,int level)
{

	if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    }
    else if (level > 1) 
	{
        displaylevel(root->left, level - 1);
        displaylevel(root->right, level - 1);
    }
}

int NodesAtLevel(BSTnode *root, int level)
 {
    if (root == NULL) {
        return 0;
    }
    if (level == 1) {
        return 1;
    }
    else if (level > 1) {
        int leftCount = NodesAtLevel(root->left, level - 1);
        int rightCount = NodesAtLevel(root->right, level - 1);
        return leftCount + rightCount;
    }
    return 0;
}
//main fun
int main()
{
	BSTnode *root=NULL;
	int choice,nodes,l;
	root=create(root);
	do
	{
	
	printf("\n1) Count Nodes Each Level\n");
	printf("2) Display Nodes Each Level\n");
	printf("3) Sum Of All Elements Of Specific Level\n");
	printf("4) Exit\n");
	printf("Enter Your Choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\nEnter The Level To Count Nodes : ");
			scanf("%d",&l);
			nodes=NodesAtLevel(root,l);
			printf("%d Nodes Present In %d Level.",nodes,l);
			printf("\n");
			break;
			
		case 2:
			printf("\nEnter The Level To Display Nodes : ");
			scanf("%d",&l);
			displaylevel(root,l);
			printf("\n");
			break;
			
		case 3:
			printf("\nEnter The Level To sum Nodes : ");
			scanf("%d",&l);
			
			printf("SUM = %d ",sumlevel(root,l));
			printf("\n");
			exit(0);
			break;
			
		case 4:
			exit(0);
	}
}while(choice!=4);
	return 0;
	
}




int sumlevel(BSTnode *root,int level)
{
	
	if (root == NULL) {
        return sum;
    }
    if (level == 1) {
        sum=sum+root->data;
    }
    else if (level > 1) 
	{
        sumlevel(root->left, level - 1);
        sumlevel(root->right, level - 1);
    }
}


