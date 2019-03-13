#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node_tag
{
        int data;
        struct node_tag *next;
        struct node_tag *prev;
}node_type;

//Traverse,InsertAtStart and DeleteAtStart-----------------------------------(without status code)

node_type* make_node(int d)
{
	node_type *nptr;
	nptr=(node_type*)malloc(sizeof(node_type));
	nptr->data=d;
	nptr->prev=NULL;
	nptr->next=NULL;
	return nptr;
}

node_type* insertAtStart(node_type* lptr,int data)
{
        node_type* nptr;
        nptr=make_node(data);
        nptr->next=lptr;
        if(lptr!=NULL)
        {
        	lptr->prev=nptr;
        }
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



node_type* reverse(node_type* head,node_type* middle,node_type* tail)
{
	if(head!=NULL)
	{
		middle->next=tail;
		middle->prev=head;
		middle=reverse(head->next,head,middle);
	}
	else
	{
		middle->next=tail;
		middle->prev=head;
		return middle;
	}
	return middle;
}
 
int main()
{
	node_type *lptr1,*lptr2,*nptr;
	int n,m,count=0,flag;
	printf("Enter no of nodes\n");
	scanf("%d",&n);
	lptr1=createlist(n);
	printf("Enter no of nodes\n");
	scanf("%d",&m);
	lptr2=createlist(m);
	while(lptr1!=NULL)
	{
		nptr=lptr2;
		flag=0;
		while(nptr!=NULL && flag==0)
		{
			if(lptr1->data==nptr->data)
			{
				count++;
				nptr->data=-1;
				flag=1;
			}
			nptr=nptr->next;
		}
		lptr1=lptr1->next;
	}
	printf("count of common nodes is %d",count);
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
