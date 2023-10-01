// queue using stack..
#include <stdio.h>
#include <stdlib.h>

int stack1[20];
int top1=-1;

void push(int x,int top, int stack[]);
void pop(int top, int stack[]);
void display(int top, int stack[]);
void enqueue();
void dequeue();

int main()
{
    int ch;
    while(ch<4)
    {
        printf("\n MENU:");
        printf("\n 1-enqueue\n 2-dequeue\n 3-display \n 4-exit");
        printf("\n enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
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
                printf("\n exitted successfully\n");
                break;
        default:
            printf("\n enter correct choice");
            break;
        }
    }
    return 0;
}

void push(int x,int top, int stack[])
{
    if(top==sizeof(stack))
        printf("stack overflow");
    else
        stack[++top]=x;
}

void pop(int top,int stack[])
{
    printf("%d",stack[top--]);
}

void display(int top, int stack[])
{
    for(int i=0;i<top;i++)
        printf("%d",stack[i]);
}

void enqueue()
{
    int x;
    printf("\n enter data:");
    scanf("%d",&x);
    push(x,top1,stack1);
}

void dequeue()
{
    if(top1==-1)
        printf("\n queue empty");
    else if(top1==0)
        pop();
    else
    {
        int top2=-1;
        int stack2[20];
        

    }   
}