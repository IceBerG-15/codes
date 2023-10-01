#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rname[20];
struct Node {
    char name[50];
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

struct Node* createNode(char* name) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    strcpy(temp->name, name);
    temp->next = NULL;
    return temp;
}

void enqueue(struct Queue* queue, char* name) {
    struct Node* newNode = createNode(name);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        (queue->rear)->next = newNode;
        queue->rear = newNode;
    }
}

char* dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }
    struct Node* temp = queue->front;
    queue->front = (queue->front)->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    strcpy(rname,temp->name);
    free(temp);
    return rname;
}

int main() {
    int n;
    printf("Enter the number of children: ");
    scanf("%d", &n);
    struct Queue* queue = createQueue();
    for (int i = 0; i < n; i++) {
        char name[50];
        printf("\nEnter the name of child %d: ", i + 1);
        scanf("%s", &name);
        enqueue(queue, name);
    }
    int count = 1;
    while (queue->front != queue->rear) {
        char* removedName = dequeue(queue);
        printf("Child %s says %d\n", removedName, count);
        if (count == 7) {
            printf("Child %s is removed from the game.\n", removedName);
            count = 1;
        } else {
            enqueue(queue, removedName);
            count++;
        }
    }
    printf("The winner is: %s\n", queue->front->name);
    free(queue);
    return 0;
}
