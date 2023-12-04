#include<stdio.h>
#include<stdlib.h>
#define SIZE 10 // defining the size of table.
// creating the array.
int array[SIZE];
// intializing the array elements with -1, to say that, that posi is empty.
void nullify(){
    for(int i=0; i<SIZE; i++)
        array[i] = -1;
}
// display function
void display(){
    printf("\ndisplay");
    for(int i=0; i<SIZE; i++)
        printf("\nindex: %d value: %d ",i ,array[i]);
}
// adding element in hash table.
void insert(int x){
    int hkey,index,i;
    hkey = x%SIZE;
    for(i=0; i<SIZE; i++){
        index = (hkey+i)%SIZE;
        if(array[index]==-1){
            array[index] = x;
            break;
        }
    }
    if(i == SIZE)
        printf("%d cannot be inserted.",x);
}
// searching for the value in hash table. 
// using same formula as insert for searching.
void search(int x){
    int hkey,index,i,flag=0;
    hkey = x%SIZE;
    for(i=0;i<SIZE;i++){
        index = (hkey+i)%SIZE;
        if(array[index]==x){
            printf("\nelement found at- %d",index);
            break;
        }
    }
    if(i==SIZE)
        printf("\nelement cannot be found.");
}
// main function
int main(){
    nullify();
    display();
    insert(24);
    insert(16);
    insert(36);
    insert(66);
    insert(86);
    insert(116);
    insert(2);
    insert(45);
    display();
    search(116);
    return 0;
}