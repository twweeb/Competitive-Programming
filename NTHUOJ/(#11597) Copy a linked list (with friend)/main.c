#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include"function.h"

static Node* create(void);
static void my_free(Node *lst);

int main(void)
{
	Node *head=create();
	Node *copy_head=copy(head);
	if(copy_head==head)
		printf("cheating\n");
	else
	{
		print(copy_head);
		if(!equal(head,copy_head))
			printf("not equal\n");
		my_free(copy_head);
	}
	my_free(head);
}

Node* create(void)
{
	unsigned long N;
	scanf("%lu",&N);
	Node *head=malloc(sizeof(Node));
	Node *temp=head;
    unsigned long i;
	for(i=N;i>0;i--)
	{
		temp->next=malloc(sizeof(Node));
		temp=temp->next;
		temp->fri=NULL;
	}
	temp->next=NULL;
	temp=head->next;
	free(head);
	head=temp;
    long fri;
	for(i=N;i>0;i--)
	{
        scanf("%ld",&fri);
		if(fri!=-1)
		{
			Node *my_fri=head;
			for(int i=0;i!=fri;++i)
				my_fri=my_fri->next;
			temp->fri=my_fri;
		}
		else
			temp->fri=NULL;
		temp=temp->next;
	}
	return head;
}

bool equal(const Node *lhs,const Node *rhs)
{
	while(true)
	{
		if((lhs==NULL)&&(rhs==NULL))
			return true;
		if((lhs==NULL)||(rhs==NULL))
			return false;
		if(lhs->id!=rhs->id)
			return false;
		if((lhs->fri!=NULL)&&(rhs->fri!=NULL))
		{
			if(lhs->fri->id!=rhs->fri->id)
				return false;
		}
		else
			if((lhs->fri!=NULL)||(rhs->fri!=NULL))
				return false;		
		lhs=lhs->next;
		rhs=rhs->next;
	}
	return true;
}

void my_free(Node *lst)
{
	while(lst!=NULL)
	{
		Node *temp=lst->next;
		free(lst);
		lst=temp;
	}
}

void print(const Node *lst)
{
	const Node *const head=lst;
	while(lst!=NULL)
	{
		if(lst->fri!=NULL)
		{
			const Node *const end=lst->fri;
			unsigned long count=0;
			for(const Node *temp=head;temp!=end;temp=temp->next)
				++count;
			printf("%lu",count);
		}
		printf("\n");
		lst=lst->next;
	}
}
