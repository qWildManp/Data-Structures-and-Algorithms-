
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
void InsertionSort(int* A,int n){
    int j = 0;
    for(int i = 1; i < n;i++){
       int key = A[i];
       j = i - 1;//index of previous key
       while(j >= 0 && A[j] > key){//if previous key greater than key swamp it
           A[j+1] =  A[j];
           j--;
       }
       A[j+1] = key;
    }
}

void Merge(int* A,int left,int center,int right){//function to merge sort 2 substring
    int i = left;//left part pointer
    int j = center+1;//right part pointer
    int k = left;
    int temp[1000000];//temp string to store the sorted array
    while(i <= center && j <= right){//if one of the side is greater then copy it to  the temp and move its pointer
        if(A[i] < A[j]){
            temp[k++] = A[i++];
        }
        else{
            temp[k++] = A[j++];
        }
    }
    while(i <= center){//copy the rest of number into temp if left side have
        temp[k++] = A[i++];
    }
    while(j <= right){//copy the rest of number into temp if left side have
        temp[k++] = A[j++];
    }
    for(int n = left;n <= right;n++){//copy b to a
        A[n] = temp[n];
    }
}
void MergeSort(int* A, int left, int right){
    if(left >= right){
        return;
    }
    int center = (left+right)/2;
    MergeSort(A,left,center);
    MergeSort(A,center+1,right);
    Merge(A,left,center,right);
}

int main(){
   int *A1 = (int *)malloc(sizeof(int)*100000);
   int *A2 = (int *)malloc(sizeof(int)*100000);
   printf("Now is insertion sort:\n");
   for(int i = 0 ;i<100000;i++){
       A1[i] = rand()%11;
       printf("%d ",A1[i]);
   }
   for(int i = 0;i<100000;i++){
       A2[i] = A1[i];
   }
   printf("\n\n\n");
   long start_s = clock();
   InsertionSort(A1,100000);
    long start_e = clock();
    for(int i = 0 ;i<100000;i++){
        printf(" %d",A1[i]);
    }
    printf("\n Run Time is %ld ms",start_e-start_s);
    printf("\nNow is merge sort:\n");
    for(int i = 0 ;i<100000;i++){
        printf(" %d",A2[i]);
    }
    printf("\n\n\n");
    start_s = clock();
    MergeSort(A2,0,99999);
    start_e = clock();
    for(int i = 0 ; i< 100000 ;i++){
        printf(" %d",A2[i]);
    }
    printf("\n Run Time is %ld ms",start_e-start_s);
}