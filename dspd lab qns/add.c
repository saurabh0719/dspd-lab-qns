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
	{	printf("%d",nptr->data);
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


Node_type* add(Node_type *num1,Node_type *num2)
{	Node_type *sum=NULL,*nptr,*ptr1,*ptr2;
	int carry=0,addn=0;
	//sum=(Node_type*)malloc(sizeof(Node_type));
	//sum->next=NULL;
	//nptr=sum;
	ptr1=num1;
	ptr2=num2;
	while(ptr1!=NULL && ptr2!=NULL)
	{	
		nptr=(Node_type*)malloc(sizeof(Node_type));
		nptr->next=sum;
		sum=nptr;
	
		addn=ptr1->data+ptr2->data+carry;
		nptr->data=addn%10;
		carry=addn/10;
		
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	while(ptr1!=NULL)
	{	
		nptr=(Node_type*)malloc(sizeof(Node_type));
		nptr->next=sum;
		sum=nptr;
		nptr->data=ptr1->data+carry;
		ptr1=ptr1->next;
		carry=0;
	}
	while(ptr2!=NULL)
	{
		nptr=(Node_type*)malloc(sizeof(Node_type));
		nptr->next=sum;
		sum=nptr;
		nptr->data=ptr2->data+carry;
		ptr2=ptr2->next;
		carry=0;
	}
	return sum;
}
		

		

void main()
{
	Node_type *sum,*num1,*num2;
	int x,y;
	printf("NO OF DIGITS IN NUM1 : ");
	scanf("%d",&x);
	printf("NO OF DIGITS IN NUM2 : ");
	scanf("%d",&y);
	printf("ENTER NUM1 : ");
	num1=createlist(x);
	printf("ENTER NUM2 : ");
	num2=createlist(y);
	sum=add(num1,num2);
	traverselist(sum);
	printf("\n");
	
}
	




	
