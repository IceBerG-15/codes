// stack using linked list.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*top=NULL,*ptr;

void push();
void pop();
void display();

int main()
{   
    int ch;
    while(ch!=4)
    {
        printf("\nMENU");
        printf("\n 1-push an element\n 2-pop an element\n 3-display\n 4-exit");
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
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
            printf("\n!!!! exited successfully !!!");
            break;
        default:
            printf("\n!!!! Enter valid choice !!! ");
            break;
        }
    }
    return 0;
}

void push()
{
    int x;
    printf("enter data which u want to insert: ");
    scanf("%d",&x);
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=top;
    top=newNode;
}
void pop()
{
    if(top==NULL)
        printf("stack underflow");
    else
    {   
        ptr=top;
        printf("%d is popped from stack.",top->data);
        top=top->next;
        free(ptr);
    }
}
void display()
{
    if(top==NULL)
        printf("stack is empty");
    else
    {
        printf("stack:");
        ptr=top;
        while(ptr!=NULL)
        {
            printf("\n%d ",ptr->data);
            ptr=ptr->next;
        }
    }
    
}