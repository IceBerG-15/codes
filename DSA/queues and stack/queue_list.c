// queue using linked list.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL,*ptr;

void enqueue();     
void dequeue();
void display();
//main function
int main()
{
    int ch;     
    while(ch<4)
    {
        printf("\nMENU ");
        printf("\n 1-enqueue \n 2-dequeue \n 3-display \n 4-exit");
        printf("\n enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n !!!! exited successfully !!!!");
                break;
            default:
                printf("\n !!! enter valid choice !!! ");
                break;
        }
    }
    return 0;
}

void enqueue()
{
    int x;
    printf("enter data: ");
    scanf("%d", &x);
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=NULL;
    if(front==NULL)
        front=newNode;
    else
        rear->next=newNode;
    rear=newNode;
}

void dequeue()
{
    if(front==NULL)
        printf("queue is empty");
    else
    {
        ptr=front;
        printf("%d is deleted from the queue. ",ptr->data);
        front=front->next;
        free(ptr);
    }
}

void display()
{
    if(front==NULL)
        printf("queue is empty");
    else
    {
        printf("QUEUE:");
        ptr=front;
        while(ptr!=NULL)
        {
            printf("\t%d",ptr->data);
            ptr=ptr->next;
        }
    }
}