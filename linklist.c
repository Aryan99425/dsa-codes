#include<stdio.h>
#define NULL 0
typedef struct nodetype
{
	int info;
	struct nodetype *link;
}node;
int main()
{
node* created();
void traverse(node*);
void instsort(node**,int);
node *head,*ptr;
int item;
head=create();
printf("ARYAN THAKUR\n");
printf("Linked list before insertion\n");
traverse(head);
printf("\nEnter info to be inserted into new node:");
scanf("%d",&item);
instsort(&head,item);
printf("Linked list after insertion\n");
traverse(head);
printf("\n-----End of program-----\n");
ptr=head;
while(ptr!=NULL)
{
ptr=ptr->link;
free(head);
head=ptr;
}
return 0;
}
node* create()
{
	node *ptr,*head=NULL;
	char ch='y';
	int data;
	while(ch=='y' || ch=='y')
	{
		if(head==NULL)
		{
			head=(node*)malloc(sizeof(node));
			ptr=head;
		}
		else
		{
			ptr->link=(node*)malloc(sizeof(node));
			ptr=ptr->link;
		}
		printf("Enter info of new node:\t");
		scanf("%d",&data);
		ptr->info=data;
		fflush(stdin);
		printf("Want to continue :(Y or N)=\n");
		scanf("%c",&ch);
	}
	ptr->link=NULL;
	return (head);
}
void traverse(node *head)
{
	node* ptr=head;
	while(ptr!=NULL)
	{
		printf("\nInfo of node is :\t%d",ptr->info);
		ptr=ptr->link;
	}
	return;
}
void instsort(node** head,int item)
{
	node *new,*ptr,*prevptr;
	new=(node*)malloc(sizeof(node));
	new->info=item;
	new->link=NULL;
	if(*head==NULL)
	{
		*head=new;
		return;
	}
	ptr=*head;
	prevptr=NULL;
	while((ptr!=NULL) && (item>ptr->info))
	{
		prevptr=ptr;
		ptr=ptr->link;
	}
	if(prevptr==NULL)
	{
		new->link=*head;
		*head=new;
	}
	else
	{
		new->link=ptr;
		prevptr->link=new;
	}
}
