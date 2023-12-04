#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->val = x;
    newNode->next = NULL;
    if(rear==NULL)
    {
        rear = newNode;
        front = newNode;
    }
    else
        rear->next = newNode;
    // bubble();
}

void dequeue()
{
    if(front==NULL)
        printf("empty front");
    else{
        struct node* temp;
        temp = front;
        front = front->next;
        printf("%d",temp->val);
        free(temp);
    }
}

void bubble()
{
    struct node *a,*b;
    int temp;
    a = front;
    while(a->next!=rear)
    {
        b = a->next;
        while(b!=rear)
        {
            if(a->val>b->val)
            {
                temp = a->val;
                a->val = b->val;
                b->val = temp;
            }
        }
    }
}

void display()
{
    struct node *temp = front;
    while(temp!=rear)
    {
        printf(" %d ",temp->val);
        temp = temp->next;
    }
}

int main()
{
    int ch=0;int x;
    while(ch!=4)
    {
        printf("MENU:\n");
        printf("1-enqueue \n2-dequeue \n3-display \n4-exit \n");
        printf("enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("\nenter value: ");
            scanf("%d",&x);
            enqueue(x);
            break;
        case 2:
            dequeue();break;
        case 3:
            display();break;
        case 4:
            printf("exitted");break;
        default:
            printf("enter correct option.");
            break;
        }
    }
}