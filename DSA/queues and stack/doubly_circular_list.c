#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL,*ptr,*temp;

void insert_at_begin();
void insert_at_end();
void insert_after_node();
void del();
void display();

int main()
{
    int ch=1;
    while(ch!=6)
    {
        printf("\nMENU:");
        printf("\n1-insert_at_begin \n2-insert_at_end \n3-insert_after_node \n4-delete \n5-display \n6-exit");
        printf("\nenter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert_at_begin();break;
            case 2:insert_at_end();break;
            case 3:insert_after_node();break;
            case 4:del();break;
            case 5:display();break;
            case 6:printf("\nEXITTED SUCCESSFULLY..");break;
            default:printf("\nENTER CORRECT OPTION");break;
        }
    }
    return 0;
}

void insert_at_begin()
{
    int x;
    printf("enter data: ");
    scanf("%d",&x);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    if(head==NULL)
    {
        head=newNode;
        head->next=newNode;
        head->prev=newNode;
    }
    else
    {
        ptr=head;
        while(ptr->next!=head)
            ptr=ptr->next;
        newNode->next=head;
        head->prev=newNode;
        ptr->next=newNode;
        newNode->prev=ptr;
        head=newNode;
    }
}
void insert_at_end()
{
    int x;
    printf("enter data: ");
    scanf("%d",&x);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    if(head==NULL)
        insert_at_begin();
    else
    {
        ptr=head;
        while(ptr->next!=head)
            ptr=ptr->next;
        newNode->next = head;
        newNode->prev = ptr;
        ptr->next=newNode;
        head->prev=newNode;
    }
}
void insert_after_node()
{
    int x;int pos;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(head==NULL)
        insert_at_begin();
    else if(head->next==head)
        insert_at_end();
    else
    {
        printf("enter data: ");
        scanf("%d",&x);
        printf("\nenter node data after which u want to insert: ");
        scanf("%d",&pos);
        newNode->data = x;
        ptr=head;
        while(ptr->data!=pos)
        {
            ptr=ptr->next;
            temp=ptr->next;
        }  
        newNode->prev=ptr;
        newNode->next=temp;
        temp->prev=newNode;
        ptr->next=newNode;
    }
}
void display()
{
    if(head==NULL)
        printf("\nLIST EMPTY..");
    else
    {
        printf("\nLIST: ");
        ptr=head;
        while(ptr->next!=head)
        {
            printf("\t%d",ptr->data);
            ptr=ptr->next;
        }
        printf("\t%d",ptr->data);
    }
}

void del()
{
    int x;
    if(head==NULL)
        display();
    else if(head->next==head)
    {   
        temp=head;
        head=NULL;
        free(temp);
    }
    else
    {
        printf("\nenter node data which u want to delete: ");
        scanf("%d",&x);
        if(head->data==x)
        {
            ptr=head;
            while(ptr->next!=head)
                ptr=ptr->next;
            temp=head;
            head=head->next;
            head->prev=ptr;
            ptr->next=head;
            free(temp);
        }
        else
        {
            ptr=head;
            while(ptr->next->data!=x)
                ptr=ptr->next;
            temp=ptr->next;
            ptr->next=temp->next;
            temp->next->prev=ptr;
            free(temp);
        }
    }
}
