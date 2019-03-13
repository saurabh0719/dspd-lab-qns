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


Node_type* swapNodes(Node_type *head_ref, int x, int y) 
{ 
   // Nothing to do if x and y are same 
   
  
   // Search for x (keep track of prevX and CurrX 
   Node_type *prevX = NULL, *currX = head_ref; 
   while (currX && currX->data != x) 
   { 
       prevX = currX; 
       currX = currX->next; 
   } 
  
   // Search for y (keep track of prevY and CurrY 
   Node_type *prevY = NULL, *currY = head_ref; 
   while (currY && currY->data != y) 
   { 
       prevY = currY; 
       currY = currY->next; 
   } 
  
   // If either x or y is not present, nothing to do 
  
  
   // If x is not head of linked list 
   if (prevX != NULL) 
       prevX->next = currY; 
   else // Else make y as new head 
       head_ref = currY;   
  
   // If y is not head of linked list 
   if (prevY != NULL) 
       prevY->next = currX; 
   else  // Else make x as new head 
       head_ref = currX; 
  
   // Swap next pointers 
   Node_type *temp = currY->next; 
   currY->next = currX->next; 
   currX->next  = temp; 
   return head_ref;
} 









Node_type* bubbleSort(Node_type *start) 
{ 
    int swapped, i; 
    Node_type *ptr1; 
    Node_type *lptr = NULL; 
   
    
    
   
    do
    { 
        swapped = 0; 
        ptr1 = start; 
   
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data > ptr1->next->data) 
            {  
                start=swapNodes(start,ptr1->data, ptr1->next->data); 
                swapped = 1; 
            } 
            else
            {
            ptr1 = ptr1->next;
            } 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
    return start;
} 

void main()
{
	Node_type *list_ptr;
	list_ptr=NULL;
	int num;
	printf("ENTER THE NO OF NODES : ");
	scanf("%d",&num);
	list_ptr=createlist(num);
	list_ptr=bubbleSort(list_ptr);
	traverselist(list_ptr);
}












