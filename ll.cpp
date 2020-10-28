#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void Insert_node(struct node**head,int data)
{
    struct node * tmp;    
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
         return;
    }
        tmp=*head;
    
    while(tmp->next!=NULL)
           tmp=tmp->next;      
    if(tmp->next==NULL)
    {
        tmp->next=newnode;
        return;
    }
                
}
void Delete_node(struct node **head,int value)
{
    struct node *tmp=*head;
    struct node *tmp2=*head;
    while(tmp->data!=value)
    {        tmp2=tmp;
    tmp=tmp->next;}           
    if(tmp->data==value)
    {
        tmp2->next=tmp->next;
        free(tmp);
    }
}
/*int Number_of_nodes(struct node **head)
{
    int count=0;
    struct node * tmp=*head;
    while(tmp!=NULL)
    {
       count=count++;
        tmp=tmp->next;
    }
    return count;
}*/
void Find_duplicate(struct node **head)
{   	
    struct node *tmp=*head;
    //struct node *tmp2=*head;
    int count=0;
    while(tmp!=NULL)
    {   struct node *tmp2=*head;
        while(tmp2!=NULL)
        {
            if(tmp->data==tmp2->next->data)
            {
                count=count++;
                printf("Duplicate value::%d",tmp->data);
            }
           else
                tmp2=tmp2->next;
            
        } 
     tmp=tmp->next;
    }
    printf("Total duplicates%d",count);
}
struct node *Reverse_list(struct node **head)
{   struct node *ptr=*head;
	struct node *tmp=NULL;
	struct node *tmp2=NULL;
	while(ptr!=NULL)
	{
		tmp2=ptr->next;
		ptr->next=tmp;
		tmp=ptr;
		ptr=tmp2;
	}
	*head=tmp;
	
}
void Display(struct node**head)
{
    struct node * tmp=*head;
    while(tmp!=NULL)
    {
        printf("->%d",tmp->data);
        tmp=tmp->next;
    }
}
int main()
{
	struct node *head=NULL;
    Insert_node(&head,20);
    Insert_node(&head,30);
	Insert_node(&head,60);
    Insert_node(&head,80);
   //Display(&head);
    printf("\n");
    //Delete_node(&head,80);
    //Display(&head);
    //printf("\n");
    Insert_node(&head,100);
    Insert_node(&head,90);
    Display(&head);
    //Number_of_nodes(&head);
    //Find_duplicate(&head);
    Reverse_list(&head);
    printf("\n");
    Display(&head);
    
    return 0;
}
