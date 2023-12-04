#include<stdio.h>
#include<stdlib.h>

struct node{
    char val;
    struct node* next;
}*head=NULL;

void push(char x)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = x;
    newNode->next = NULL;
    if(head==NULL)
        head=newNode;
    else{
        newNode->next = head;
        head = newNode;
    }
}

void pop()
{
    if(head==NULL)
        printf("Empty");
    else{
        struct node* temp;
        temp = head;
        head = head->next;
        free(temp);
    }
}

char peek()
{
    return head->val;
}

void display()
{
    if(head==NULL)
        printf("empty ");
    else{
        struct node* temp;
        temp = head;
        while(temp!=NULL)
        {
            printf("%c\n", temp->val);
            temp = temp->next;
        }
    }
}

int main(){
    int n;    int flag = 0;
    printf("enter length: ");
    scanf("%d",&n);
    char string[n];
    printf("enter string\n");
    scanf("%s", string);
    if(n%2!=0)
        flag++;
    else{
        for(int i=0; i<n; i++){
            if(string[i]=='{' || string[i]=='(' || string[i]=='[')
                push(string[i]);
            else{
                if(string[i]==')' && head!=NULL){
                    if(peek()!='('){
                        flag++;
                        break;
                    }
                }
                if(string[i]==']' && head!=NULL){
                    if(peek()!='['){
                        flag++;
                        break;
                    }
                }
                if(string[i]=='}' && head!=NULL){
                    if(peek()!='{'){
                        flag++;
                        break;
                    }
                }
            }
        }
    }
    if(flag==0 && head==NULL)
        printf("%s have all the brackets correct.",string);
    else
        printf("%s dont have all the brackets correct.",string);
    return 0;
}