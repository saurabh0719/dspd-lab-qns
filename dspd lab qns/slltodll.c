#include<stdio.h>
#include<stdlib.h>

typedef struct node_tag
{
        int data;
        struct node_tag *next;
        struct node_tag *prev;
}node_type;

//Traverse,InsertAtStart and DeleteAtStart-----------------------------------(without status code)

node_type* insertAtStart(node_type* lptr,int data)
{
        node_type* nptr;
        nptr=(node_type*)malloc(sizeof(node_type));
        nptr->data=data;
        nptr->next=lptr;
        lptr=nptr;
        return lptr;
}

node_type* createlist(int num)
{
        int i,d;
        node_type *lptr;
        lptr=NULL;
        for(i=0;i<num;i++)
        {
		scanf(" %d",&d);
                lptr=insertAtStart(lptr,d);
        }
        return lptr;
}

int main()
{
	node_type *lptr,*nptr;
	int n;
	printf("Enter no of nodes u want\n");
	scanf("%d",&n);
	lptr=createlist(n);
	nptr=lptr;
	lptr->prev=NULL;
	lptr=lptr->next;
	while(lptr!=NULL)
	{
		lptr->prev=nptr;
		nptr=lptr;
		lptr=lptr->next;
	}
	while(nptr->prev!=NULL)
	{
		printf("%d",nptr->data);
		nptr=nptr->prev;
	}
	printf("%d",nptr->data);
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
