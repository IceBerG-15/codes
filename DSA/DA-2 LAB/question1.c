#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coefficient;
    int power;
    struct node* next;
}*ptr1,*ptr2,*ptr;

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
void substraction(struct node* *head1,struct node* *head2)
{   
    ptr1=*head1;
    while(ptr1!=NULL)
    {
        ptr2=*head2;
        while(ptr2!=NULL)
        {
            if(ptr1->power==ptr2->power)
                ptr1->coefficient-=ptr2->coefficient;
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
}

int main()
{
    int size,c,p;
    int i,j;
    struct node* head,*head1=NULL,*head2=NULL;
    for(i=0;i<2;i++)
    {
        printf("\nenter number of terms: ");
        scanf("%d",&size);
        for(j=0;j<size;j++)
        {
            if(i==0)
                insert(&head1);
            else   
                insert(&head2);
        }
    }
    printf("equation-1: ");
    display(&head1);
    printf("equation-2: ");
    display(&head2);
    substraction(&head1,&head2);
    printf("result: ");
    display(&head1);   
    return 0;
}