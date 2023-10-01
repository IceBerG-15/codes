#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int a[],int n);

int main()
{
    int n;
    printf("\n enter size: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
    {
        printf("\n enter element: ");
        scanf("%d",&a[i]);
    }
    bubble_sort(a,n);
}

void bubble_sort(int a[],int n)
{
    int temp;
    int s;
    for(int i=0;i<n;i++)
    {   
        s=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                s=1;
            }
        }
        if(s==0)
            break;
        printf("\nelement after %d pass.",i+1);
        for(int k=0;k<n;k++)
            printf("%d ",a[k]);
        
    }
}