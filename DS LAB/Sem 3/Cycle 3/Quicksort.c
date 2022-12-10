#include <stdio.h>


void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i=low-1;
    for(int j =0;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}


void quickSort(int arr[],int low,int high){
    if(low<high){
        int part=partition(arr,low,high);
        quickSort(arr,part+1,high);
        quickSort(arr,low,part-1);
    }
}


void main(){
    int size,element;
    printf("\nEnter the size of the array : ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        printf("\nEnter the element : ");
        scanf("%d",&element);
        arr[i]=element;
    }

    quickSort(arr,0,size-1);

    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}