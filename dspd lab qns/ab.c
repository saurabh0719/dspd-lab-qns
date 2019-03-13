#include<stdio.h>
#include<stdlib.h>
typedef struct Node_tag
{	char data;
	struct Node_tag *next;
}Node_type;

typedef struct stack_tag
{	Node_type *top;
}stack_type;

typedef enum{FAILURE,SUCCESS}status_code;

void Initialize(stack_type *stck_ptr)
{	stck_ptr->top=NULL;
}

Node_type* InsertAtStart(Node_type *list_ptr,char d)
{	Node_type *nptr;
	nptr=(Node_type*)malloc(sizeof(Node_type));
	nptr->data=d;
	nptr->next=list_ptr;
	list_ptr=nptr;
	return list_ptr;
}

Node_type* createlist(int *num)
{	Node_type *list_ptr,*nptr;
	
	int i=0;
	list_ptr=NULL;
	char ch=' ';
	while(ch!='.')
	{	scanf(" %c",&ch);
		if(ch!='.')
		{	list_ptr=InsertAtStart(list_ptr,ch);
			i++;
		}
	}
	*num=i;
	return list_ptr;
}


Node_type* MakeNode(char d)
{	Node_type *nptr;
	nptr=(Node_type*)malloc(sizeof(Node_type));
	if(nptr!=NULL)
	{	nptr->data=d;
		nptr->next=NULL;
	}
	return nptr;
}

status_code Push(stack_type *sptr,char d)
{	Node_type *nptr;
	status_code ret_val=SUCCESS;
	nptr=MakeNode(d);
	if(nptr==NULL)
	{	ret_val=FAILURE;
	}
	else
	{	nptr->next=sptr->top;
		sptr->top=nptr;
	}
	return ret_val;
}

status_code Pop(stack_type *sptr,char *d)
{	Node_type *ptr;
	status_code sc=SUCCESS;
	if(sptr->top==NULL)
	{	sc=FAILURE;
	}
	else
	{	ptr=sptr->top;
		sptr->top=ptr->next;
		*d=ptr->data;
		free(ptr);
	}
	return sc;
}

status_code isEmptyStack(stack_type *sptr)
{	status_code sc=FAILURE;
	if(sptr->top==NULL)
		sc=SUCCESS;
	return sc;
}


void main()
{	stack_type stck;
	status_code sc;
	Initialize(&stck);
	int num,i=0,flag=0;
	char ch;
	Node_type *list_ptr=NULL,*nptr;
	printf("ENTER THE STRING : ");
	list_ptr=createlist(&num);
	
	nptr=list_ptr;
	while(nptr->data=='b')
	{	sc=Push(&stck,nptr->data);
		nptr=nptr->next;
	}
	while((nptr!=NULL)&&(flag==0))
	{	sc=Pop(&stck,&ch);
		if(sc==FAILURE)
		{	flag=1;
		}
		nptr=nptr->next;
	}
	if((flag==0)&&(isEmptyStack(&stck)==FAILURE))
	{	flag=1;
	}
	
	if(flag==0)
		printf("TRUE\n");
	else
		printf("FALSE\n");
}













