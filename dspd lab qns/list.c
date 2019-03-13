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


Node_type* DeleteAtStart(Node_type *list_ptr,int *dptr)
{	Node_type *nptr;
	nptr=list_ptr;
	if(list_ptr!=NULL)
	{	list_ptr=list_ptr->next;
		*dptr=nptr->data;
		free(nptr);
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

Node_type* InsertAtEnd(Node_type *list_ptr,int d)
{	Node_type *nptr,*ptr;
	nptr=(Node_type*)malloc(sizeof(Node_type));
	nptr->data=d;
	nptr->next=NULL;
	if(list_ptr==NULL)
	{	list_ptr=nptr;
	}
	else
	{	ptr=list_ptr;
		while(ptr->next!=NULL)
		{	ptr=ptr->next;
		}
		ptr->next=nptr;
	}
	return list_ptr;
}

Node_type* DeleteAtEnd(Node_type *list_ptr,int *dptr)
{	Node_type *prev,*ptr;
	if(list_ptr!=NULL)
	{	if(list_ptr->next==NULL)
		{	*dptr=list_ptr->data;
			free(list_ptr);
			list_ptr=NULL;
		}
		else
		{	ptr=list_ptr;
			while(ptr->next!=NULL)
			{	prev=ptr;
				ptr=ptr->next;
			}
			prev->next=NULL;
			*dptr=ptr->data;
			free(ptr);
		}
	}
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

Node_type* DeleteList(Node_type *list_ptr)
{	int data;
	while(list_ptr!=NULL)
	{	list_ptr=DeleteAtStart(list_ptr,&data);
		printf("%d ",data);
	}
	return list_ptr;
}


void main()
{	Node_type *list_ptr;
	list_ptr=NULL;
	in t num_nodes,data;
	int choice,n;
	char ch='y';
	while((ch=='y')||(ch=='Y'))
	{
	printf("1.CREATE LIST \n2.DELETE LIST\n3.INSERT AT START\n4.DELETE AT START\n5.INSERT AT END\n6.DELETE AT END\n7.TRAVERSE LIST\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
	printf("ENTER THE NO OF NODES : ");
	scanf("%d",&num_nodes);
	list_ptr=createlist(num_nodes);
	traverselist(list_ptr);
	printf("\n");
	break;
	
	case 2:
	list_ptr=DeleteList(list_ptr);
	printf("DELETED");
	break;
	
	case 3:
	printf("ENTER THE NO TO BE INSERTED AT START :");
	scanf("%d",&n);
	list_ptr=InsertAtStart(list_ptr,n);
	traverselist(list_ptr);
	printf("\n");
	break;
	
	case 4:
	list_ptr=DeleteAtStart(list_ptr,&data);
	printf("\n %d deleted ",data);
	printf("\n");
	break;
	
	case 5:
	printf("ENTER THE NO TO BE INSERTED AT END :");
	scanf("%d",&n);
	list_ptr=InsertAtEnd(list_ptr,n);
	traverselist(list_ptr);
	printf("\n");
	break;
	
	case 6:
	list_ptr=DeleteAtEnd(list_ptr,&data);
	printf("\n %d deleted ",data);
	printf("\n");
	break;
	
	case 7:
	traverselist(list_ptr);
	printf("\n");
	break;
	
	default:printf("WRONG CHOICE ENTERED ");
	}
	printf("Do you want to continue y/n : ");
	scanf(" %c",&ch);
	}
	
}
	


















