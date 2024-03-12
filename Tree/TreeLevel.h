#include<stdio.h>
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

