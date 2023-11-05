#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int array[]={22,67,55,48,60,72,38,87,76};
int size=9;

int main()
{
    int i,j,k;
    k=0;
    int levels = floor(log2(size));
    // printf("%d",levels);
    for(i=0;i<=levels;i++) 
    {
        printf("level-%d\t",i);
        for(j=0;j<pow(2,i);j++)
        {
            if(k==size)
                break;
            printf("\t%d",array[k++]);
        }
        printf("\n");
    }
    return 0;
}