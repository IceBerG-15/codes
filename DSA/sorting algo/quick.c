#include<stdio.h>
#include<stdlib.h>

int partitions(int arr[],int start,int end){
    int pivot = arr[end];
    int i = start-1;
    int temp;
    for(int j=start; i<=end; i++){
        if(arr[j]<pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;
    return i+1;
}

void quick_sort(int arr[],int start,int end){
    if(start<end){
        int p = partitions(arr,start,end);
        quick_sort(arr,start,p-1);
        quick_sort(arr,p+1,end);
    }
}

int main(){
    int arr[] = {10,7,8,9,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}