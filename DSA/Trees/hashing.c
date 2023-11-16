#include <stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 19

int h[TABLE_SIZE];
// intializing every index value to -1
void intial()
{
    int i;
    for(i=0;i<TABLE_SIZE;i++)
        h[i]=-1;
}
// counting the number of free cells in the table
void count()
{
    int i,c=0;
    for(i=0;i<TABLE_SIZE;i++)
    {
        if(h[i]==-1)
            c++;
    }
    printf("\nNumber of free cells: %d",c);
}
// insertion in the table
void insert()
{
    int key,index,i,flag=0,hkey;
    printf("\nenter a value to insert into hash table\n");
    scanf("%d",&key);
    hkey=key%TABLE_SIZE;
    for(i=0;i<TABLE_SIZE;i++)
    {
        index=(hkey+i)%TABLE_SIZE;
        if(h[index] == -1)
        {
            h[index]=key;
            break;
        }
    }
    if(i == TABLE_SIZE)
        printf("\nelement cannot be inserted\n");
}
// searching the table
void search()
{
    int key,index,i,flag=0,hkey;
    printf("\nenter search element\n");
    scanf("%d",&key);
    hkey=key%TABLE_SIZE;
    for(i=0;i<TABLE_SIZE; i++)
    {
        index=(hkey+i)%TABLE_SIZE;
        if(h[index]==key)
        {
            printf("value is found at index %d",index);
            break;
        }
    }
    if(i == TABLE_SIZE)
        printf("\n value is not found\n");
}
// displaying the table
void display()
{
    int i;
    printf("\nelements in the hash table are \n");
    for(i=0;i< TABLE_SIZE; i++)
        printf("\nat index %d \t value =  %d",i,h[i]);
    count();
}
// main function
int main()
{
    intial();
    int opt=1;
    while(opt!=4)
    {
        printf("\nMENU \n1. Insert\t 2. Display \t3. Search \t4.Exit ");
        printf("\nenter your choice: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:exit(0);break;
            default:printf("enter valid option.");break;
        }
    }
}