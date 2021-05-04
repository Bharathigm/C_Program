// program for circular queue using linked list.

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *f = NULL;
struct node *r = NULL;
void enqueue(int d) //Insert elements in Queue
{
	struct node* n;
	n = (struct node*)malloc(sizeof(struct node));
	n->data = d;
	n->next = NULL;
	if((r==NULL)&&(f==NULL))
	{
		f = r = n;
		r->next = f;
	}
	else
	{
		r->next = n;
		r = n;
		n->next = f;
	}
} 
void dequeue() // Delete an element from Queue
{
	struct node* curr;
	curr = f;
	if((f==NULL)&&(r==NULL))
		printf("\nQueue is Empty");
	else if(f == r){
		f = r = NULL;
		printf("deleted data =  %d\n",curr->data);
		free(curr);
	}
	else{
		f = f->next;
		r->next = f;
		printf("deleted data =  %d\n",curr->data);
		free(curr);
	}
	
}

void dequeuesearch(int key) // Delete an element from Queue
{
   	struct node* curr = f;
   	struct node* prev =f;

	if((f==NULL)&&(r==NULL))
		printf("\nQueue is Empty");
	else if(f == r){
		f = r = NULL;
		printf("deleted data =  %d\n",curr->data);
		free(curr);
	}
	else
{
    while (curr->data != key)
    {
        if (curr->next == f)
        {
            printf("\nGiven node is not found"
                   " in the list!!!");
            break;
        }
 
        prev = curr;
        curr = curr->next;
    } 
	 
	    if(prev == f && curr == f)
		{
		  	f = f->next;
			r->next = f;
			printf("deleted data =  %d\n",curr->data);
			free(curr);
		}
		else
		{
        prev->next = curr->next;
		printf("deleted data = %d\n",curr->data);
        free(curr);
		}
    }
}

void dequeuelast() // Delete an element from Queue
{
	struct node* curr = f;
   	struct node* prev;
	if((f==NULL)&&(r==NULL))
		printf("\nQueue is Empty");
	else if(f == r){
		f = r = NULL;
		printf("deleted data = %d\n",curr->data);
		free(curr);
	}
	else
{
    while (curr != r)
    {
        prev = curr;
        curr = curr->next;
    }
        prev->next = f;
		r=prev;
		printf("deleted data = %d\n",curr->data);
        free(curr);
    }
}


void print(){ // Print the elements of Queue
	struct node* t;
	t = f;
	if((f==NULL)&&(r==NULL))
		printf("\nQueue is Empty");
	else{
		do
		{
		    printf("\n%d",t->data);
			t = t->next;
		}while(t != f);
	}
}
int main()
{
	int opt,n,i,data,key;
	printf("Enter Your Choice:-");
	do{
       printf("\n\n1 for Insert the Data in Queue\n2 for show the Data in Queue \n3 for Delete the front element from the Queue\n4 for Delete the Search data from the Queue\n5  for Delete the  last data from the Queue\n0 for Exit");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nEnter the number of data");
				scanf("%d",&n);
				printf("\nEnter your data");
				i=0;
				while(i<n){
					scanf("%d",&data);
					enqueue(data);
					i++;
				}
				break;
			case 2:
				print();
				break;
			case 3:
				 dequeue();
				break;
			case 4:
			printf("\nEnter the key to be deleted");
				scanf("%d",&key);
				 dequeuesearch(key);
				break;
			case 5:
				 dequeuelast();
				break;

			case 0: exit(0);
				
			default:
				printf("\nIncorrect Choice");
			
		}
	}while(opt!=0);
return 0;
}
