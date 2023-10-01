#include <stdio.h>
#include <stdlib.h>// malloc is the function of this library.
// creating srcuture.
struct node
{
    int data;
    struct node* next;
}*head=NULL,*ptr;// creating pointer for head and ptr.
// initializing all the required functions.
void insert_at_begin();
void insert_at_end();
void insert_after_node();
void display();
struct node* find(int x);
void deletion();
// main-function..
int main()
{
    int data;
    int ch=1;
    while (ch<6)
    {
        printf("\n MENU: ");
        printf("\n 1-insert at front\n 2-insert at back\n 3-insert at middle\n 4-display data\n 5-deletion\n 6-exit");
        printf("\n enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                insert_at_begin();
                break;
            case 2: 
                insert_at_end();
                break;
            case 3: 
                insert_after_node();
                break;
            case 4: 
                display();
                break;
            case 5:
                deletion();
                break;
            case 6: 
                printf("\n exitted successfully...");
                break;
            default: 
                printf("\n enter correct choice... ");
                break;
        }
    }
    return 0;
}
// display function to display all the nodes.
void display()
{
    if(head == NULL)
        printf("empty list");
    else
    {
        printf("\n list: ");
        ptr=head;
        while(ptr!=NULL)
        {
            printf("\t%d",ptr->data);
            ptr=ptr->next;
        }
    }
    
}
// this function finds the node data which we pass as an argument and then return the node address.
struct node* find(int x)
{
    ptr=head;
    while(ptr->next!=NULL && ptr->data!=x)
        ptr=ptr->next;
    return ptr;
}
// this function insert the node at the beginning of the list.
void insert_at_begin()
{
    int data;
    printf("enter data which u want to insert: ");
    scanf("%d",&data);
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=head;
    head=newNode;
}
// this function insert the node at the end of the list.
void insert_at_end()
{
    int data;
    printf("enter data which u want to insert: ");
    scanf("%d",&data);
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    ptr=head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=newNode;
}
// this function asks the user where to put the node and then to the necessary.
void insert_after_node()
{
    int data;
    printf("enter data which u want to insert: ");
    scanf("%d",&data);
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    int x;
    printf("enter data after which u want to insert: ");
    scanf("%d",&x);
    ptr=find(x);// ptr gets the address of the node we searched for.
    newNode->next=ptr->next;// ptr->next contains the address of next node, so we give newNode->next the address of that node.
    ptr->next=newNode;// then ptr->next takes the address of newNode
}
// this function deletes the node whose data user enters and want to delete.
void deletion()
{
    int x;
    printf("enter data after which u want to delete: ");
    scanf("%d",&x);
    ptr=head;
    while(ptr->next!=NULL && ptr->next->data!=x)
        ptr=ptr->next;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=ptr->next;
    printf("%d is deleted from the list.",temp->data);
    ptr->next=temp->next;
    free(temp);
}