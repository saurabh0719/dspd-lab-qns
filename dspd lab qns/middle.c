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

void middle(Node_type *lptr,int n)
{	Node_type *optr,*tptr,*prev;
	optr=lptr;
	tptr=lptr;
	if(lptr!=NULL)
	{
	while((tptr!=NULL)&&(tptr->next!=NULL))
	{	prev=optr;
		optr=optr->next;
		tptr=tptr->next;
		tptr=tptr->next;
	}
	if(n%2==0)
		printf("%d and %d \n",prev->data,optr->data);
	else
		printf("%d \n",optr->data);
	}	
}

void main()
{	int n,m;
	printf("ENTER THE NO OF ELEMENTS : ");
	scanf("%d",&n);
	Node_type *list_ptr;
	
	list_ptr=createlist(n);
	middle(list_ptr,n);
	
}
	
