#include<stdio.h>
#include "fulltree.h"
int main()
{
	BSTnode *root=NULL;
	BSTnode *root1,*root2,*root3,*root4=NULL;
	int ans;
	int choice,ele,nodes;
	do
	{
	printf("\n\n");
	printf("1) create\n");
	printf("2) insert\n");
	printf("3) search\n");
	printf("4) Display\n");
	printf("5) Counts Nodes\n");
	printf("6) Copy Tree\n");
	printf("7) Mirror Tree\n");
	printf("8) Compare Trtee\n");
	printf("9) Exit\n");
	printf("Enter The Choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			root=create(root);
			break;
			
		case 2:
			printf("Enter the Elements To Insert : ");
			scanf("%d",&ele);
			insert(root,ele);
			break;
			
		case 3:
			printf("Enter The Elements To Search : ");
			scanf("%d",&ele);
			if(search(root,ele)!=NULL)
			{
				printf("Element Is Present In Tree.\n");
			}
			else
			{
				printf("Element Is Not Present In Tree.\n");
			}
			break;
			
		
		case 4:
			printf("Tree Is : \n");
			printf("\nInorder : ");
			inorder(root);
			printf("\npreorder : ");
			preorder(root);
			printf("\npostorder : ");
			postorder(root);
			break;
		
			
		case 5:
			printf("\nTotal Nodes Of Tree Is : %d",countnodes(root));
			printf("\nTotal Leaf Node In Tree : %d",countleaf(root));
			printf("\nMinimum Value In Tree Is : %d",minvalue(root));
			printf("\nMaximum Value In Tree Is : %d",maxvalue(root));
			printf("\nSum Of Total Elements Is : %d",sumbst(root));
			break;
			
		case 6:
				root2=treecopy(root);
				printf(" 1st Tree is : \n");
				inorder(root);
				printf("\nCopy Tree IS : \n");
				inorder(root2);
				break;
				
		case 7:
			root3=mirror(root);
			printf("\nMirror Tree Is : \n");
			inorder(root3);
			break;
			
		case 8:
			
			printf("\nEnter The Second Tree : \n");
			root4=create(root4);
				ans=compare(root,root4);
				if(ans!=0)
					printf("\nBoth tree are same");
				else
					printf("\nBoth Tree Are not same");
			break;
			
		case 9:
			exit(0);
	}
	}while(choice!=9);
	
	return 0;
}
