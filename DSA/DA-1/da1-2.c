#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack* next;
} Stack;

Stack* createNode(int data) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Stack** top, int data) {
    Stack* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(Stack** top) {
    if (*top == NULL) {
        fprintf(stderr, "Stack underflow\n");
        exit(1);
    }
    Stack* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

void enqueue(Stack** queue, int data) {
    push(queue, data);
}

int dequeue(Stack** inputStack, Stack** outputStack) {
    if (*outputStack == NULL) {
        while (*inputStack != NULL) {
            push(outputStack, pop(inputStack));
        }
    }
    return pop(outputStack);
}

void displayQueue(Stack* inputStack, Stack* outputStack) {
    printf("Queue contents: ");
    while (inputStack != NULL) {
        push(&outputStack, pop(&inputStack));
    }
    while (outputStack != NULL) {
        printf("%d", pop(&outputStack));
        
        if (outputStack != NULL) {
            printf(", ");
        }
    }
    
    printf("\n");
}


int main() {
    Stack* inputStack = NULL;
    Stack* outputStack = NULL;
    
    int n = 0, i = 0, data;
    while(n !=3){
        printf("-------MENU--------\n1. Enqueue\n2.Display\n3.Exit\n--------------");
        printf("\nEnter your choice:");
        scanf("%d", &n);
        if(n == 1){
            printf("Enter the number you want to add in Queue : \t");
            scanf("%d", &data);
            enqueue(&inputStack,data);
        }
        if(n == 2){
            displayQueue(inputStack, outputStack);
        }
    }

    displayQueue(inputStack, outputStack);

    return 0;
}
