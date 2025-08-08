#include<stdio.h>
# define max 3

void main()
{
	int f=-1,r=-1;
	int val,choice;
	int q[max];
	
	while(1)
	{
		printf("\n1.insert\n2.remove\n3.display\n4.exit\nEnter choice :");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter value :");
				scanf("%d",&val);
				insert(&f,&r,q,val);
				break;
				
			case 2:
				removeq(&f,&r,q);
				break;
				
			case 3:
				display(&f,&r,q);
				break;
				
			case 4:
				exit(0);
				
			default:
				printf("Invalid input");
				break;
		}
	}
}
void insert(int *f,int *r,int q[max],int nval)
{
	if(*r==max-1)
	{
		printf("queue is full..");
	}
	else if((*f)==-1 && (*r)==-1)
	{
		*f=*r=0;
		q[*r]=nval;
		printf("value entered in queue :%d\n",q[*r]);
	}
	else
	{
		(*r)=(*r)+1;
		q[*r]=nval;
		printf("Value entered :%d\n",q[*r]);
	}
}
void removeq(int *f,int *r,int q[max])
{
	if((*f)==-1 && (*r)==-1)
	{
		printf("queue is empty");
	}
	else
	{
		if((*f) == (*r))
		{
			printf("removed element :%d",q[*f]);
			(*f)=(*r)=-1;
		}
		else
		{
			printf("rmoved element :%d",q[*f]);
			(*f)++;
		}
	}
}
void display(int *f,int *r,int q[max])
{
	int i;
	if((*f)==-1 && (*r)==-1)
	{
		printf("queue is empty.");
	}
	else
	{
		for(i=*f; i<=*r; i++)
		{
			printf("%d",q[i]);
		}
	}
}
