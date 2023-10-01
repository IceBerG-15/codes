//stack implementation using array---

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5          //stack size declare....

int top=-1;             //top of stack
int stack[SIZE];        //stack declare
void push();
void pop();
void display();

int main(){
    int ch;
    while(ch!=4){
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

//push method...used to push an element into the stack..
void push(){
    if(top==SIZE-1)
        printf("\n!!!! stack overflow !!!!!\n");
    else{
        int el;
        printf("\nenter number u want to push: ");
        scanf("%d",&el);
        top++;
        stack[top] = el;
        printf("\npush done successfully\n");
    }
}

//pop method...used to pop an element from the stack..
void pop(){
    if(top==-1)
        printf("\n!!!! stack underflow !!!!\n");
    else{
        printf("\n%d poped from stack",stack[top]);
        top--;
        printf("\npop successfully\n");
    }
}

//display method...used to display the stack..
void display(){
    if(top==-1)
        printf("\n!!!! stack empty !!!!\n");
    else{
        printf("\n");
        for (int i = 0; i <=top; i++)
            printf("  %d  ", stack[i]);
    printf("\n");
    }
}