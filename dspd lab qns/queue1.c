#include<stdio.h>
#include<stdlib.h>
typedef struct Node_tag
{	int data;
	struct Node_tag *next;
}Node_type;

typedef struct stack_tag
{	Node_type *top;
}stack_type;

typedef enum{FAILURE,SUCCESS}status_code;

void Initialize(stack_type *stck_ptr)
{	stck_ptr->top=NULL;
}
Node_type* MakeNode(int d)
{	Node_type *nptr;
	nptr=(Node_type*)malloc(sizeof(Node_type));
	if(nptr!=NULL)
	{	nptr->data=d;
		nptr->next=NULL;
	}
	return nptr;
}

status_code Push(stack_type *sptr,int d)
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

status_code Pop(stack_type *sptr,int *d)
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

int remove1(stack_type *stck,int count,stack_type *stck2)
{	status_code sc,sc1;
	int i=0,data;
	for(i=0;i<count;i++)
	{	sc=Pop(stck,&data);
		sc=Push(stck2,data);
	}
	sc=Pop(stck2,&data);
	printf("Element is %d \n",data);
	count--;
	for(i=0;i<count;i++)
	{	sc=Pop(stck2,&data);
		sc=Push(stck,data);
	}
	return count;
}
	
	

void main()
{	int choice,i,count=0,x;
	stack_type stck,stck2;
	status_code sc;
	Initialize(&stck);
	printf("1.add\n2.pop\n0.exit\nEnter choice : ");
	scanf("%d",&choice);
	while(choice!=0)
	{
		switch(choice)
		{
			case 1: printf("ENTER THE ELEMENT : ");
					count++;
					scanf("%d",&x);
					sc=Push(&stck,x);
					break;
			case 2: if(count==0)
					{	
						printf("EMPTY QUEUE\n");
					}
					else
					{
						count=remove1(&stck,count,&stck2);
					}
					break;
			default:break;
		}
		printf("1.add\n2.pop\n0.exit\nEnter choice : ");
		scanf("%d",&choice);
	}
}
					
				   



