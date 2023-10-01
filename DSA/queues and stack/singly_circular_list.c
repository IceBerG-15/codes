#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head=NULL,*ptr,*temp;

void push();
void pop();
void display();
void insert_at_begin(int x);
void insert_at_end(int x);
void insert_after_node(int x);

int main()
{
    int ch;
    while(ch!=4)
    {
        printf("\nMENU: ");
        printf("\n1-push \n2-pop \n3-display \n4-exit");
        printf("\nenter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nEXITTED SUCCESSFULLY....");
                break;
            default:
                printf("\nENTER CORRECT CHOICE...\n");
                break;
        }
    }
    return 0;
}

void push()
{
    int x;
    int ch;
    printf("\n1-push at begin \n2-push at end \n3-push after given node \nenter choice:");
    scanf("%d",&ch);
    printf("\nenter data-> ");
    scanf("%d",&x);
    switch(ch)
    {
        case 1:insert_at_begin(x);break;
        case 2:insert_at_end(x);break;
        case 3:insert_after_node(x);break;
    }
}
void insert_at_begin(int x)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=x;
    if(head==NULL)
    {
        head=newNode;
        newNode->next=head;  
    }
    else
    {
        newNode->next=head;
        ptr=head;
        while(ptr->next!=head)
            ptr=ptr->next;
        ptr->next=newNode;
        head=newNode;
    }
}
void insert_at_end(int x)
{
    if(head==NULL)
        insert_at_begin(x);
    else
    {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data=x;
        newNode->next=head;
        ptr=head;
        while(ptr->next!=head)
            ptr=ptr->next;
        ptr->next=newNode;
    }
}
void insert_after_node(int x)
{
    if(head==NULL)
        insert_at_begin(x);
    else
    {
        int after_data;
        printf("\nenter node data after which you want to push: ");
        scanf("%d",&after_data);
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data=x;
        ptr=head;
        while(ptr->data!=after_data)
            ptr=ptr->next;
        newNode->next=ptr->next;
        ptr->next=newNode;
    }
}
void pop()
{
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
        int x;
        printf("\nenter node data which u want to delete: ");
        scanf("%d",&x);
        if(head->data==x)
        {
            ptr=head;
            while(ptr->next!=head)
                ptr=ptr->next;
            temp=head;
            ptr->next=head->next;
            head=head->next;
            free(temp);
        }
        else
        {
            ptr=head;
            while(ptr->next->data!=x)
                ptr=ptr->next;
            temp=ptr->next;
            ptr->next=temp->next;
            free(temp);
        }
    }
}

void display()
{
    if(head==NULL)
        printf("\nlist empty");
    else
    {
        ptr=head;
        printf("\nLIST: ");
        while(ptr->next!=head)
        {
            printf("\t%d",ptr->data);
            ptr=ptr->next;
        }
        printf("\t%d",ptr->data);
    }
}