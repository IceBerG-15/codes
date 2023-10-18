// decimal to binary using singly linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*ptr,*newNode;

void insert(struct node* *head, int x) // we are doing insertion at begin..
{
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=NULL;
    if(*head==NULL) 
    {
        newNode->next=NULL;
        *head=newNode;
    }
    else
    {
        newNode->next=*head;
        *head=newNode;
    }
}
void display(struct node* *head)
{
    ptr=*head;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    int dec,mod;
    struct node* head=NULL;
    printf("enter which u want to convert- ");
    scanf("%d",&dec);
    while(dec!=0)
    {
        mod=dec%2;
        insert(&head,mod);
        dec/=2;
    }
    display(&head);
    return 0;
}