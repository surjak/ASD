#include <iostream>
using namespace std;


struct node
{
    int val;
    node *next;
};

node * scal(node *a, node *b)
{node * list;


	if(a==NULL)
	return b;

	 if(b==NULL)
	 return a;
	
	if(a->val<=b->val)
	{
		list=a;
		list->next=scal(a->next,b);
	}
	else
	{
		list=b;
		list->next=scal(a,b->next);
	}
	
	return list;
}

void dziel( node* a, node *&h1, node *&h2)
{
	if(a==NULL || a->next==NULL)
	{
		h1=a;
		h2=NULL;
		return;
	}
	node* slow=a;
	node* fast=a->next;
	while(fast!=NULL)
	{
		fast=fast->next;
		if(fast!=NULL)
		{
			slow=slow->next;
			fast=fast->next;
		}
	}
	h1=a;
	h2=slow->next;
	slow->next=NULL;

}
 void Mergesort(node*& head)
 {if(head==NULL || head->next==NULL)
 return;
	 node *h1;
	 node *h2;
	 dziel(head, h1, h2);
	 Mergesort(h1);
	 Mergesort(h2);
	 head=scal(h1,h2);
 }

int main()
{
	node* a=new node;
	a->val=5;
	node* b=new node;
	b->val=2;
	node* c=new node;
	c->val=1;
	node* d=new node;
d->val=0;
a->next=b;
b->next=c;
c->next=d;
d->next=NULL;


Mergesort(a);
node* wynik=a;
while(wynik!=NULL)
{cout<<wynik->val<<endl;
wynik=wynik->next;
}
}