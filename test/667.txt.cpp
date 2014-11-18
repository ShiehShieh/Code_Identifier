#include <iostream>
using namespace std;
struct Node 
{ 
   int i; 
   Node *next; 
}*head;
Node *CreateNode(int i) 
{ 
   Node *node=new Node; 
   node->i=i; 
   node->next=NULL; 
   return node; 
} 
void Make(int n)
{
	head=CreateNode(0);
	Node *p=head;
	for(int i=1;i<=n;i++)
	{
		p->next=CreateNode(i);
		p=p->next;
	}
}
void FreeLink(Node *head)         
{ 
   Node *p=head; 
   while(p) 
   { 
       head=p->next; 
       delete p; 
       p=head; 
   } 
} 
Node *Go(Node *p,int n)
{
	Node *temp=p;
	while(n--)
		temp=temp->next;
	return temp;
}
int main()
{
	int n,k;
	cin>>n>>k;
	Make(n);
	int a,b,c;
	Node *x,*y,*z;
	for(int i=0;i<k;i++)
	{
		cin>>a>>b>>c;
		x=Go(head,a-1);
		y=Go(x->next,b-a);
		Node *temp=x->next;
		x->next=y->next;
		z=Go(head,c);
		y->next=z->next;
		z->next=temp;
	}
	for(int i=1;i<=10;i++)
		cout<<Go(head,i)->i<<endl;
//end
	FreeLink(head);
	return 0;
}
