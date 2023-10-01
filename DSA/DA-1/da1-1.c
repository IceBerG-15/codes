//array elements are pushed to stack if they are composite numbers and enqueued in queue if they are prime numbers.
#include <stdio.h>
#include <stdlib.h>

int stack[10];
int queue[10];
int top=-1;
int front = -1;
int rear = -1;

void push(int x);
void enqueue(int x);
void stack_display();
void queue_display();

int main()
{   
    int size;
    printf("enter size of array: ");
    scanf("%d", &size);
    int array[size],k;
    for(int i = 0; i < size; i++)
    {
        printf("enter array element: ");
        scanf("%d", &array[i]);
    }
    for(int i = 0; i < size; i++)
    {   k=0;
        if (array[i]==1)
            continue;
        else
        {
            for(int j=2;j<array[i];j++)
            {
                if(array[i]%j==0)
                    k++;
            }
            if(k==0)
                enqueue(array[i]);
            else
                push(array[i]);
        }
    }
    stack_display();
    queue_display();
    return 0;
}

void push(int x)
{
    stack[++top] = x;
}

void enqueue(int x)
{
    if(front==-1)
        front++;
    queue[++rear]=x;
}

void stack_display()
{   
    printf("\n STACK:");
    for(int i=top; i>-1; i--)
        printf("\t %d ", stack[i]);
}

void queue_display()
{
    printf("\n QUEUE:");
    for(int i=front; i<=rear; i++)
        printf("\t %d ", queue[i]);
}