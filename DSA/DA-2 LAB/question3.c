#include <stdio.h>
#include <stdlib.h>

int int_array[20];
char char_array[20];
//bubble sort funtion for character array. sorting in ascending order
void bubble_sort(char array[],int n)
{
    int temp;
    int s;
    for(int i=0;i<n;i++)
    {   
        s=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                s=1;
            }
        }
        if(s==0)
            break;
    }
}
//bubble sort funtion for integer array. sorting in decending order
void bubble(int array[],int n)
{
    int temp;
    int s;
    for(int i=0;i<n;i++)
    {   
        s=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(array[j]<array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                s=1;
            }
        }
        if(s==0)
            break;
    }
}

int main()
{
    int n,i;
    int int_count=0; // counter for counting integer in input string
    int char_count=0; // counter for counting character in input string
    printf("\nenter size of input array: ");
    scanf("%d",&n);
    char* input = (char*)malloc(n*sizeof(char));
    for(i=0;i<n;i++)
    {
        printf("\nenter array inputs: ");
        scanf(" %c",&input[i]);
    }
    for(i=0;i<n;i++)
    {
        if(input[i]>='a' && input[i]<='z')
        {
            char_array[char_count++] = input[i];
            input[i]='_';
        }
        else
        {
            int_array[int_count++] = input[i]-'0';
            input[i]='*';
        }
    }
    bubble(int_array,int_count);
    bubble_sort(char_array,char_count);
    char_count=0;
    int_count=0;
    for(i=0;i<n;i++)
    {
        if(input[i]=='*')
            printf(" %d",int_array[int_count++]);
        else
            printf(" %c",char_array[char_count++]);
    }
    return 0;
}