#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int begin,int mid,int end){
    int i,j,k;
    int n1 = mid-begin+1;
    int n2 = end-mid;
    int ar1[n1],ar2[n2];
    // copying data in to temp arrays
    for(i=0;i<n1;i++)
        ar1[i] = arr[begin+i];
    for(j=0;j<n2;j++)
        ar2[j] = arr[mid+j];
    //
    i=0;
    j=0;
    k=0;
    while(i<n1 && j<n2){
        if(ar1[i]<=ar2[j])
            arr[k++]=ar1[i++];
        else
            arr[k++]=ar2[j++];
    }
    // copying remaining data from ar1 to arr, if any remaining
    while(i<n1){
        arr[k++]=ar1[i++];
    }
    // copy remaining data from ar2 to arr, if any remaining
    while(j<n2){
        arr[k++]=ar2[j++];
    }
}

// merge sort function..
void merge_sort(int arr[],int begin,int end){
    if(begin<end){
        int mid = begin+(end-1)/2;
        merge_sort(arr,begin,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,begin,mid,end);
    }
}

// main function..
int main(){
    int n,i;
    printf("enter n: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter values..");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,n-1);
    for(i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    return 0;
}