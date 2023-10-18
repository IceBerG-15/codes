// polynomial differentiation
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coefficient;
    int power;
    struct node* next;
}*ptr,*temp;

void display(struct node* *head)
{
    ptr=*head;
    while(ptr!=NULL)
    {
        printf("(%dx^%d)",ptr->coefficient,ptr->power);
        if(ptr->next!=NULL)
            printf("+");
        ptr=ptr->next;
    }
    printf("\n");
}
void insert(struct node* *head)
{
    int c,p;
    printf("enter coefficient: ");
    scanf("%d",&c);
    printf("enter power: ");
    scanf("%d",&p);
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->coefficient=c;
    newNode->power=p;
    newNode->next=NULL;
    if(*head==NULL)
        *head=newNode;
    else
    {
        ptr=*head;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newNode;
    }
}
void differention(struct node* *head)
{   
    ptr=*head;
    while(ptr!=NULL)
    {
        if(ptr->power==0)
            ptr->coefficient=0;
        else
        {
            ptr->coefficient*=ptr->power;
            ptr->power-=1;
        }
        ptr=ptr->next;
    }
}

int main()
{
    int size,c,p;
    int i,j;
    struct node* head=NULL;
    printf("\nenter number of terms: ");
    scanf("%d",&size);
    for(j=0;j<size;j++)
    {
        insert(&head);
    }
    printf("equation-1: ");
    display(&head);
    differention(&head);
    printf("result: ");
    display(&head);   
    return 0;
}