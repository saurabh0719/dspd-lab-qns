#include<stdio.h>
#include<stdlib.h>
typedef struct DL_Node_tag
{
	int data;
	struct DL_Node_tag *prev;
	struct DL_Node_tag *next;
}DL_Node;

DL_Node* DL_MakeNode(int d)
{
	DL_Node *nptr;
	nptr=(DL_Node*)malloc(sizeof(DL_Node));
	nptr->data=d;
	nptr->prev=NULL;
	nptr->next=NULL;
	return nptr;
}

DL_Node* DL_InsertAtStart(DL_Node *dlptr,int d)
{
	DL_Node *nptr;
	nptr=DL_MakeNode(d);
	nptr->next=dlptr;
	if(dlptr!=NULL)
	{
		dlptr->prev=nptr;
	}
	dlptr=nptr;
	return dlptr;
}
DL_Node* createlist(int num)
{	DL_Node *list_ptr,*nptr;
	int i,x;
	list_ptr=NULL;
	for(i=0;i<num;i++)
	{	scanf("%d",&x);
		list_ptr=DL_InsertAtStart(list_ptr,x);
	}
	return list_ptr;
}

void traverselist(DL_Node *list_ptr)
{	DL_Node *nptr;
	if(list_ptr==NULL)
		printf("EMPTY LIST \n");
	else
	{	nptr=list_ptr;
	while(nptr!=NULL)
	{	printf("%d ",nptr->data);
		nptr=nptr->next;
	}
	}
}

DL_Node* del(DL_Node *dlptr,int k)
{
	DL_Node *ptr=dlptr,*temp;
	while(ptr!=NULL)
	{
		if(ptr->data%k==0)
		{	
			temp=ptr->prev;
			if(temp==NULL)
			{
				dlptr=ptr->next;
				if(dlptr!=NULL)
				{
					dlptr->prev=NULL;
				}
				free(ptr);
				ptr=dlptr;
			}
			else
			{
			temp->next=ptr->next;
			if(ptr->next!=NULL)
			{
				ptr->next->prev=temp;
			}
			free(ptr);
			ptr=temp->next;
			}
		}
		else
		{
			ptr=ptr->next;
		}
	}
	return dlptr;
}
			


void main()
{
	DL_Node *dlptr;
	int n,k;
	printf("ENTER N : ");
	scanf("%d",&n);
	dlptr=createlist(n);
	printf("ENTER K : ");
	scanf("%d",&k);
	dlptr=del(dlptr,k);
	traverselist(dlptr);
}

