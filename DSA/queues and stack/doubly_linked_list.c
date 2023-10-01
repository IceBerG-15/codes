#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev,*next;
}*head=NULL,*ptr,*temp;

void insertion_at_front();
void insertion_at_end();
void insertion_at_mid();
void deletion();
int getData();
struct node* findlast();
struct node* findprev(int x);
void display();

int main()
{
    int ch=1;
    while(ch<5)
    {
        printf("\nMENU: ");
        printf("\n1-insertion at front \n2-insertion at end \n3-insertion at mid \n4-deletion \n5-exit");
        printf("\nenter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insertion_at_front();
            break;
        case 2:
            insertion_at_end();
            break;
        case 3:
            insertion_at_mid();
            break;
        case 4:
            deletion();
            break;
        case 5:
            printf("\nEXITTED SUCCESSFULLY....");
            break;
        deafult:
            printf("\nEnter correct choice.");
            break;
        }
    }
}

int getData()
{
    int x;
    printf("\nenter data: ");
    scanf("%d",&x);
    return x;
}
struct node* findlast()
{
    ptr=head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    return ptr;
}
struct node* findprev(int x)
{
    ptr=head;
    while(ptr->next!=NULL && ptr->next->data!=x)
        ptr=ptr->next;
    return ptr;
}
void display()
{
    if(head==NULL)
        printf("NULL\n");
    else
    {
        ptr=head;
        printf("NULL");
        while(ptr!=NULL)
        {
            printf("<-%d->",ptr->data);
            ptr=ptr->next;
        }
        printf("NULL\n");

    }

}
void insertion_at_front()
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=getData();
    newNode->prev=NULL;
    newNode->next=head;
    if(head!=NULL)
        head->prev=newNode;
    head=newNode;
    display();
}
void insertion_at_end()
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=getData();
    newNode->next=NULL;
    if(head==NULL)
    {
        newNode->prev=NULL;
        head=newNode;
    }
    else
    {
        ptr=findlast();
        newNode->prev=ptr;
        ptr->next=newNode;
    }
    display();
}
void insertion_at_mid()
{
    int pos;
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=getData();
    printf("\n enter element before which u want to insert: ");
    scanf("%d",&pos);
    ptr=findprev(pos);
    newNode->prev=ptr;
    newNode->next=ptr->next;
    ptr->next->prev=newNode;
    ptr->next=newNode;
    display();
}
void deletion()
{
    int x;
    printf("\nenter element you want to delete:");
    scanf("%d",&x);
    if(head->data==x)
    {
        temp=head;
        head=NULL;
        free(temp);
    }
    else
    {
        ptr=findprev(x);
        temp=ptr->next;
        temp->next->prev=ptr;
        ptr->next=temp->next;
        free(temp);
    }
    display();
}

