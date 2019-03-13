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

Node_type* merge(Node_type *lptr1,Node_type *lptr2)
{
	Node_type *head,*ptr1,*ptr2,*tail;
	if(lptr1==NULL)
	{
		head=lptr2;
	}
	else if(ptr2==NULL)
	{
		head=lptr1;
	}
	else 
	{
		head=lptr1;
		tail=lptr1;
		ptr1=lptr1->next;
		ptr2=lptr2;
		while(ptr1!=NULL && ptr2!=NULL)
		{
			tail->next=ptr2;
			tail=tail->next;
			ptr2=ptr2->next;
			tail->next=ptr1;
			tail=tail->next;
			ptr1=ptr1->next;
		}
		if(ptr1!=NULL)
		{
			tail->next=ptr1;
		}
		else if(ptr2!=NULL)
		{
			tail->next=ptr2;
		}
	}
	return head;
}	

void main()
{
	Node_type *lptr1,*lptr2,*new;
	int num1,num2;
	printf("ENTER NUM1 : ");
	scanf("%d",&num1);
	printf("ENTER NUM2 : ");
	scanf("%d",&num2);
	lptr1=createlist(num1);
	lptr2=createlist(num2);
	new=merge(lptr1,lptr2);
	traverselist(new);
}
