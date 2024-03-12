#include<stdio.h>
#include "btree.h"
#include "TreeLevel.h"
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

s
