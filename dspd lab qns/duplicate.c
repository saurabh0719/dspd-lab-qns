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


void duplicate(Node_type *lptr)
{	Node_type *p,*q,*ptr;
	if(lptr==NULL)
		printf("EMPTY LIST ");
	else
	{
		q=lptr->next;
		p=lptr;
		while(q!=NULL)
		{	if(p->data==q->data)
			{	p->next=q->next;
				ptr=q;
				q=q->next;
				free(ptr);
			}
			else
			{	p=p->next;
				q=q->next;
			}
		}
		traverselist(lptr);
	}
}
	
	
void main()
{	int n,m;
	printf("ENTER THE NO OF ELEMENTS : ");
	scanf("%d",&n);
	Node_type *list_ptr;
	list_ptr=createlist(n);
	duplicate(list_ptr);
}
