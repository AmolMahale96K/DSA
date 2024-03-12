#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};
typedef struct node BSTnode;
BSTnode *create(BSTnode *root)
{
	BSTnode *newnode,*temp,*parent;
	int i,n,num;
	printf("How Many Nodes : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		newnode=(BSTnode*)malloc(sizeof(BSTnode));
		scanf("%d",&num);
		newnode->data=num;
		newnode->left=newnode->right=NULL;
		if(root==NULL)
		{
			root=newnode;
			continue;
		}
		temp=root;
		while(temp!=NULL)
		{
			parent=temp;
			if(num<temp->data)
			{
				temp=temp->left;
			}
			else
			{
				temp=temp->right;
			}
			
		}
		if(num<parent->data)
		{
			parent->left=newnode;
		
		}
		else
		{
			parent->right=newnode;
		}
	}
	return(root);
}

//search
BSTnode *search(BSTnode *root,int key)
{
	BSTnode *temp=root;
	while(temp!=NULL)
	{
		if(key==temp->data)
			return(temp);
		if(key<temp->data)
			temp=temp->left;
		else
			temp=temp->right;
		
	}
	return NULL;
}

//insert
BSTnode *insert(BSTnode *root,int ele)
{
	BSTnode *newnode,*temp=root,*parent;
	newnode=(BSTnode*)malloc(sizeof(BSTnode));
	newnode->data=ele;
	newnode->right=newnode->left=NULL;
	if(root==NULL)
	{
		root=newnode;
		return(root);
	}
	while(temp!=NULL)
	{
		parent=temp;
		if(ele<temp->data)
		{
			temp=temp->left;
		}
		else
		{
			temp=temp->right;
		}
	}
	if(ele<parent->data)
	{
		parent->left=newnode;
	}
	else
	{
		parent->right=newnode;
	}
	return(root);
}


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


//display
void preorder(BSTnode *root)
{
	BSTnode *temp=root;
	if(temp!=NULL)
	{
		preorder(temp->left);
		printf("%d\t",temp->data);
		preorder(temp->right);
	}
}

void inorder(BSTnode *root)
{
	BSTnode *temp=root;
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d\t",temp->data);
		inorder(temp->right);
	}
}

void postorder(BSTnode *root)
{
	BSTnode *temp=root;
	if(temp!=NULL)
	{
		printf("%d\t",temp->data);
		postorder(temp->left);
		postorder(temp->right);
		
	}
}
BSTnode *treecopy(BSTnode *root)
{
	BSTnode *newnode;
	if(root!=NULL)
	{
		newnode=(BSTnode*)malloc(sizeof(BSTnode));
		newnode->data=root->data;
		newnode->left=treecopy(root->left);
		newnode->right=treecopy(root->right);
		return newnode;
		
	}
	else
		return NULL;
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

int compare(BSTnode *root1,BSTnode *root2)
{
	if(root1==NULL && root2==NULL)
		return 1;
	else
		if(root1!=NULL && root2!=NULL)
			if(root1->data==root2->data)
				if(compare(root1->left,root2->left))
					return compare(root1->right,root2->right);
	return 0;
}
