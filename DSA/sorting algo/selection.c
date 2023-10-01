#include <stdio.h>
#include <stdlib.h>

void selection_sort(int a[],int n);

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
    selection_sort(a,n);
}

void selection_sort(int a[],int n)
{
    int temp;
    int s;
    int min;
    for(int i=0;i<n-1;i++)
    {   
        s=0;
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
                s=1;
            }
        }
        if(s==0)
            break;
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
        printf("\nelement after %d pass.",i+1);
        for(int k=0;k<n;k++)
            printf("%d ",a[k]);
        
    }
}