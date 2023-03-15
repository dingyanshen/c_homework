#include <stdio.h>
#include <stdlib.h>
struct node
{
	char data;
	int count;
	struct node *next;
};
struct node *insert(struct node *head, char ch)
{
	struct node *p1,*p2,*p;
	int flag;
	/*****************************************/
	p=(struct node *)malloc(sizeof(struct node));
	/*****************************************/
	p->data=ch;	p->count=1;
	if(head==NULL)
	{
	    /*****************************************/
		head=p;
	    /*****************************************/
		p->next=NULL; 
		flag=0;
	}
	else
	{
		p1=head;
		while(p1->data>ch && p1->next!=NULL)
		{
			p2=p1; 
			p1=p1->next;
		}
		if(p1->data==ch)
		{	
			/*****************************************/
			p1->count++;
			/*****************************************/
	    	flag=1;  	
		}
		else if(p1->data<ch)
		{
			if(head==p1)
				head=p;
			else
				p2->next=p;  
				p->next=p1;
				flag=0;
		}
		else
		{	
			p1->next=p;	
			p->next=NULL; 
			flag=0;		
		}
	}
	/*****************************************/
	if(flag)
	   free(p);
	/*****************************************/
	 return head;
}
int main(void)
{	char ch;
	struct node *head=NULL,*p;
	while((ch=getchar())!='\n')
		head=insert(head,ch);
	p=head;
	while(p!=NULL)
	{
		printf("%c:%d\n",p->data,p->count);
		p=p->next;
	}
}