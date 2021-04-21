#include <stdio.h>
#include <stdlib.h>

void add_patient(void);
void print(void);
#define SIZE 100
typedef struct node
{
	char name[SIZE];
	char gender;
	int age;
    int id;
	struct node *nx;
}node;
node *head=NULL;

void main (void)
{
	add_patient();	
	add_patient();


}

void add_patient(void)
{
	
	node *newptr=(node*)malloc(sizeof(node));
	
	//name
	printf("name : "); 
	scanf("%[^\n]s",&newptr->age);
	printf("My name is %s\n",newptr->name); 
    //age
	printf("age : ");
	scanf("%d",&newptr->age);
    printf("My age is %d\n",newptr->age);
	//gender
	printf("gnder:");
	scanf("%s",&newptr->gender);
	printf("My gender is %c\n",newptr->gender);
	//id
	printf("id : ");
	scanf("%d",&newptr->id);
	printf("My id is %d\n",newptr->id);
	newptr->nx=NULL;
	if(head==NULL)
	    head=newptr;
	
	else
	{
		node *currentptr=head;
		while(currentptr->nx != NULL)
		{
			currentptr = currentptr->nx;
		}
		currentptr->nx =newptr;
    }

}
void print(void)
{
	node *newptr=head;
	newptr = head -> nx ; 
	printf("My name is %s\n",newptr->name); 
    printf("My age is %d\n",newptr->age);
	printf("My gender is %c\n",newptr->gender);
	printf("My id is %d\n",newptr->id);
}



   