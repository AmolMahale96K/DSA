#include<stdio.h>
#include<stdlib.h>
#include "btree.h"
#include "bstcount.h"
int main()
{
	BSTnode *root=NULL;
	int choice;
	root=create(root);
	do{
	printf("\n\n");
	printf("1) Count Nodes \n");
	printf("2) Count Leaf Nodes \n");
	printf("3) Min Value\n");
	printf("4) Max Value\n");
	printf("5) Sum Of Total Nodes\n");
	printf("6) Exit");
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
				printf("Minimum Value In Tree Is : %d",minvalue(root));
				break;
				
			case 4:
				printf("Maximum Value In Tree Is : %d",maxvalue(root));
				break;
				
			case 5:
				printf("Sum Of Total Elements Is : %d",sumbst(root));
				break;
				
			case 6:
				exit(0);
		}
	}while(choice!=6);
	return 0;
}
