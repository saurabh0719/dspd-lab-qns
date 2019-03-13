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
	int i;
	list_ptr=NULL;
	for(i=0;i<num;i++)
	{	list_ptr=InsertAtStart(list_ptr,i);
	}
	return list_ptr;
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


Node_type* reverse(Node_type *head,Node_type *mid,Node_type *tail)
{	
	if(head!=NULL)
	{	
		mid->next=tail;		
		mid=reverse(head->next,head,mid);
	}
	else
	{	mid->next=tail;	
		return mid;
	}
}


void main()
{	
	Node_type *list_ptr,*ptr=NULL;
	int n;
	printf("ENTER NO OF NODES : ");
	scanf("%d",&n);
	list_ptr=createlist(n);
	list_ptr=reverse(list_ptr->next,list_ptr,ptr);
	traverselist(list_ptr);
}







