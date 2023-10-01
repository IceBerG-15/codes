//queue using array
#include <stdio.h>
#include <stdlib.h>

int front=-1;       //front-end of queue
int rear=-1;        //rear-end of queue
int queue[20];      //queue array
//functions initialization
void enqueue();     
void dequeue();
void display();
//main function
int main()
{
    int ch;     
    while(ch<4){
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
//enqueue function to insert element into queue
void enqueue(){
    int input;
    printf("\n Enter input: ");
    scanf("%d", &input);
    if(front==-1 && rear==-1)   //checking if queue is empty
        front++;            //if empty then front is incremented
    rear++;     //rear is incremented then adding element in that position
    queue[rear]=input;
    printf("\n ---- enqueue is done successfully ----");
}
//dequeue function to remove element from queue
void dequeue(){
    if(front==-1 && rear==-1)  //checking if queue is empty
        printf("\n !!! queue is empty !!!!");
    else            
        printf("\n %d ",queue[front]);  //displaying queue element that is getting removed
        front++;        //incrementing front to point it to next element
    printf("\n---- dequeue is done successfully -----");
}
//display function to display elements
void display(){
    if(front>rear)   //checking if queue is empty
        printf("\n !!! stack is empty !!!");
    else{           //if not then printing the elements
        printf("\n");
        for(int i=front; i<=rear;i++)
            printf(" %d ", queue[i]); 
    }
}