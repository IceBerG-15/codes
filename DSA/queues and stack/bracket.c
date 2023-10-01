// Paranthesis checker using linked list.
#include <stdio.h>
#include <stdlib.h>
// malloc function is stdlib library function.
struct node
{
    char data;
    struct node *next;
}*top=NULL,*ptr;

void push(char x); // push stack operation to push the character in the stack.
void pop(); // pop stack operation to pop the top character of the stack.
// main function
int main()
{
    char exp[20];
    printf("enter expression: ");
    scanf("%s",&exp);
    int i=0,k; 
    // using k as variable which will change its value to 0 when top is null if is triggered, so we dont print invalid expression twice..
    while(i<sizeof(exp))
    {   
        k=1;
        if(exp[i]=='[' || exp[i]=='{' || exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==']' || exp[i]=='}' || exp[i]==')')
            if(top==NULL)
            {
                printf("invalid parenthesis");
                k=0;
                break;
            }
            else
                if(exp[i]=='}' && top->data=='{')
                        pop();
                else if(exp[i]==']' && top->data=='[')
                        pop();
                else if(exp[i]==')' && top->data=='(')
                        pop();
        i++;
    }
    if(top==NULL && i==sizeof(exp))
// here i==sizeof(exp) because when the loop breaks the top is null at that time, so it will invoke this if too, if we dont give this condition.
        printf("valid parenthesis.");
    else if(k==1)
        printf("invalid parenthesis");
    return 0;
}

void push(char x)
{
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = top;
    top=newNode;
}

void pop()
{
    ptr=top;
    top=top->next;
    free(ptr);
}