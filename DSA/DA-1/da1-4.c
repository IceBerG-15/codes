//doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev,*next;
}*head=NULL,*ptr;

void insert();
void middle();
void display();
int counter();

int main()
{
    int ch;
    while(ch<4)
    {
        printf("\nMENU: ");
        printf("\n1-insert \n2-middle \n3-display\n4-exit");
        printf("\n enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert(); break;
            case 2: middle(); break;
            case 3: display(); break;
            case 4: printf("EXITTED.."); break;
            default: printf("\n enter valid option.."); break;
        }
    }
    return 0;
}

void insert()
{
    int data;
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    printf("\nenter data: ");
    scanf("%d",&data);
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL) 
    {
        newNode->prev=NULL;
        head=newNode;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL) 
            ptr=ptr->next;
        newNode->prev=ptr;
        ptr->next=newNode;
    }
}
// function is used to find the middle node and dispay the element data.
void middle()
{
    int count=counter(); // counter function will give the list size.
    int mid;
    if(count%2==0)
        mid=count/2+1;
    else
        mid=(count+1)/2;
    ptr=head;
    for(int i=1;i<mid;i++)
        ptr=ptr->next;
    printf("\nThe middle node is %d",ptr->data);
}
// this function is used to display the elements of the list.
void display()
{
    if(head==NULL)
        printf("\nList empty");
    else
    {
        printf("\nLIST");
        ptr=head;
        while(ptr!=NULL)
        {
            printf("\t%d",ptr->data);
            ptr=ptr->next;
        }
    }
    
}
// this function is used to calculate the size of list.
int counter()
{
    int k=0;
    ptr=head;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        k++;
    }
    return k;
}
