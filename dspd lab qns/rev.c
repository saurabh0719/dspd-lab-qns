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


DL_Node* reverse(DL_Node *dlptr)
{
	DL_Node *head,*mid,*tail;
	head=dlptr;
	mid=NULL;
	while(head!=NULL)
	{
		tail=mid;
		mid=head;
		head=head->next;
		mid->next=tail;
		mid->prev=head;
	}
	DL_Node *nptr;
	if(dlptr==NULL)
		printf("EMPTY LIST \n");
	else
	{	nptr=dlptr;
	while(nptr!=NULL)
	{	printf("%d ",nptr->data);
		nptr=nptr->prev;
	}
	}
	
	return mid;
}

void main()
{
	DL_Node *dlptr;
	int n;
	printf("ENTER N : ");
	scanf("%d",&n);
	dlptr=createlist(n);
	dlptr=reverse(dlptr);
	printf("\n");
	traverselist(dlptr);
}
	
