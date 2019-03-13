#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Poly_tag
{	int coeff;
	int exp;
	struct Poly_tag *next;
}Poly_type;

Poly_type* MakeTerm(int c,int e)
{	
	Poly_type *ptr;
	ptr=(Poly_type*)malloc(sizeof(Poly_type));
	ptr->coeff=c;
	ptr->exp=e;
	ptr->next=NULL;
	return ptr;
}

Poly_type* InsertTerm(int c,int e,Poly_type *tail)
{
	tail->next=MakeTerm(c,e);
	if(tail->next==NULL)
	{
		printf("ERROR");
	}
	return tail->next;
}



Poly_type* ReadPolynomial(int x)
{	int coeff;
	int exp,last_exp,done=0;
	Poly_type *result,*tail,*ptr;
	last_exp=100;
	x--;
	tail=result=MakeTerm(0,0);
	while(!done)
	{
		scanf("%d",&coeff);
		exp=x;
		if((exp>=last_exp)||(exp<0))
			done=1;
		else
		{
			tail=InsertTerm(coeff,exp,tail);
			last_exp=exp;
			if(exp==0)
				done=1;
		}
		x--;
	}
	tail->next=NULL;
	ptr=result;
	result=result->next;
	free(ptr);
	return result;
}

Poly_type* InsertPoly(Poly_type *result,Poly_type *nptr)
{
	Poly_type *ptr,*prev;
	if(result==NULL)
	{
		result=nptr;
	}
	else
	{	prev=ptr=result;
		while((ptr!=NULL)&&(ptr->exp>nptr->exp))
		{
			prev=ptr;
			ptr=ptr->next;
		}
		if(prev==ptr)
		{
			nptr->next=result;
			result=nptr;
		}
		else if(ptr==NULL)
		{
			prev->next=nptr;
			nptr->next=NULL;
		}
		else if(ptr->exp==nptr->exp)
		{
			ptr->coeff=ptr->coeff+nptr->coeff;
			free(nptr);
			if(ptr->coeff==0)
			{	prev->next=ptr->next;
				free(ptr);
			}
		}
		else
		{	prev->next=nptr;
			nptr->next=ptr;
		}
	}
	return result;
}


Poly_type* MultPoly(Poly_type *poly1,Poly_type *poly2)
{	Poly_type *result=NULL;
	Poly_type *ptr1,*ptr2;
	for(ptr1=poly1;ptr1!=NULL;ptr1=ptr1->next)
	{
		for(ptr2=poly2;ptr2;ptr2=ptr2->next)
		{
			int newcoeff;
			int new_exp;
			Poly_type *new_node;
			newcoeff=(ptr1->coeff)*(ptr2->coeff);
			new_exp=ptr1->exp+ptr2->exp;
			new_node=MakeTerm(newcoeff,new_exp);
			result=InsertPoly(result,new_node);
		}
	}
	return result;
}

void traverse(Poly_type *result)
{
	Poly_type *nptr=result;
	long double sum=0;
	while(nptr!=NULL)
	{
		sum=(nptr->coeff)*(pow(10,nptr->exp))+sum;
		nptr=nptr->next;
	}
	printf("%Lf\n",sum);
}
		
		
void main()
{
	int x,y;
	printf("ENTER THE NO OF DIGITS IN NUM1 : ");
	scanf("%d",&x);
	printf("ENTER THE NO OF DIGITs IN NUM2 : ");
	scanf("%d",&y);
	printf("ENTER NUM1 : ");
	Poly_type *p1=ReadPolynomial(x);
	printf("ENTER NUM2 : ");
	Poly_type *p2=ReadPolynomial(y);
	Poly_type *result=MultPoly(p1,p2);
	traverse(result);
}	
	
	

