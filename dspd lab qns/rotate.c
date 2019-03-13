#include<stdio.h>
#include<stdlib.h>
typedef struct Node_tag
{	int data;
	struct Node_tag *next;
}Node_type;

Node_type* InsertAtStart(Node_type *list_ptr,int d)
{	Node_type *nptr;
	nptr=(Node_type*)malloc(sizeof(Node_type));
	nptr->data=d;
	nptr->next=list_ptr;
	list_ptr=nptr;
	return list_ptr;
}

Node_type* createlist(int num)
{	Node_type *list_ptr,*nptr;
	int i,x;
	list_ptr=NULL;
	for(i=0;i<num;i++)
	{	scanf("%d",&x);
		list_ptr=InsertAtStart(list_ptr,x);
	}
	return list_ptr;
}

Node_type* rotate(int k,Node_type *list_ptr)
{
	Node_type *nptr,*list_ptr1=list_ptr,*ptr;
	nptr=list_ptr;
	int i=0;
	while(i<k-1)
	{
		nptr=nptr->next;
		i++;
	}
	list_ptr1=nptr->next;
	nptr->next=NULL;
	ptr=list_ptr1;
	while(ptr->next!=NULL)
	{	
		ptr=ptr->next;
	}
	ptr->next=list_ptr;
	return list_ptr1;
	
}
	
void traverselist(Node_type *list_ptr)
{	Node_type *nptr;
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
void main()
{	Node_type *list_ptr;
	int n,k;
	printf("ENTER THE NO OF NODES : ");
	scanf("%d",&n);
	list_ptr=createlist(n);
	printf("ENTER THE VALUE OF K : ");
	scanf("%d",&k);
	list_ptr=rotate(k,list_ptr);
	traverselist(list_ptr);
}
	
	
