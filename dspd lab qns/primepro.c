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

int isPrime(node_type* lptr)
{
	int i,flag=0;
	for(i=2;i<=sqrt(lptr->data) && flag==0;i++)
	{
		if(lptr->data%i==0)
		{
			flag=1;
		}
	}
	return flag;
}

int main()
{
	node_type *lptr,*nptr;
	int n,ans,product=1;
	printf("Enter no of nodes\n");
	scanf("%d",&n);
	lptr=createlist(n);
	while(lptr!=NULL)
	{
		ans=isPrime(lptr);
		if(ans==0)
		{
			product=product*(lptr->data);
		}
		lptr=lptr->next;
	}
	printf("\n%d\n",product);
	return 0;
}






















