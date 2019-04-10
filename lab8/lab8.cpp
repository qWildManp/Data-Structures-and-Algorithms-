#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Pivot(int *A,int left,int right){// function to choose a pivot in order to make the pivot not a too big or too small number
    int center = (left+right)/2;
    int temp;
    if(A[left] > A[center]){
        temp = A[left];
        A[left] =A[center];
        A[center] = temp;
    }
    if(A[center] > A[right]){
        temp = A[right];
        A[right] = A[center];
        A[center] = temp;
    }
    if(A[left] > A[center]){
        temp = A[left];
        A[left] =A[center];
        A[center] = temp;
    }

    temp = A[center];
    A[center] = A[right-1];
    A[right-1] = temp;
}
int Partition(int *A,int left,int right){
    Pivot(A,left,right);
    int i = left;
    int j = right - 2;
    int pivot = A[right-1];
    int temp;
    while(true){
        while(A[i] < pivot){//if the current value is smaller than pivot move to the next one
            i++;
        }

        while(A[j] > pivot){//if the current value is greater than the pivot move to the next one
            j--;
        }
        if(i < j){//if left smaller than right means two pointer doesn't scan half of the array
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
        else
            break;
    }
    //exchange the pivot with the first one that is greater than pivot
    temp = A[i];
    A[i] = A[right - 1];
    A[right - 1] = temp;
    return i;
}
void QuickSort(int *A, int left, int right){
    if(left >= right)
        return;
    int q = Partition(A,left,right);
    QuickSort(A,left,q-1);//sort the left part
    QuickSort(A,q+1,right);//sort the right part
}
bool isFull(int maxsize,int size){//check if the array is full
    return size>(maxsize-1)? true:false;
}
bool isEmpty(int size){//check if the array is empty
    if (size==NULL){
        return true;
    }
    else{
        return false;
    }
}
bool Insert(int *A,int size,int x,int maxsize){//insert a number into heap
    if(isFull(maxsize,size)){//if the heap is full do nothing
        return false;
    }
    else{
        int hole = size;//dig a hole
        while (hole > 0 && x > A[(hole-1)/2]){//while insert number is bigger than root swap the hole
            A[hole] = A[(hole-1)/2];
            hole = (hole-1)/2;
        }
        A[hole] = x;
        return true;
    }
}
bool DeleteMax(int *A,int size){//delete the max number from the heap
    if(isEmpty(size)){//if the tree is empty
        return false;
    }
    else{
        int max = A[0];
        int hole = 0;
        int x = A[size-1];
        while((2*hole)+1 <= (size-2)){//if the root has children
            int sid = (A[(2*hole)+1] > A[(2*hole)+2])?(2*hole)+1:(2*hole)+2;//select the bigger child
            if (x >= A[sid]){//if x is bigger than child do nothing
                break;
            }
            //swap the hole
            A[hole] = A[sid];
            hole = sid;
        }
        A[hole] = x;//put x into its correct position
        A[size-1] = max;//let max value store in the last of the array

    }
}
void HeapSort(int *A,int size){
    for(int i = 0;i < size;i++){//build a tree
        Insert(A,i,A[i],size);
    }
    for(int j = size-1;j>0;j--){//sort
         DeleteMax(A,j+1);
    }
}
int main(){
    int* A1 = (int*)malloc(sizeof(int)*100000);
    int* A2 = (int*)malloc(sizeof(int)*100000);
    printf("origin array:\n");
    for(int i =0; i< 100000; i++){
        A1[i] = rand()%11;
        A2[i] = A1[i];
        printf(" %d",A1[i]);
    }
    printf("\n quick sort :\n");
    int start = clock();
    QuickSort(A1,0,99999);
    int end  = clock();
    for(int i =0; i< 100000; i++){
        printf(" %d",A1[i]);
    }
    printf("\ntime is : %d ms",((end-start)*1000/ CLOCKS_PER_SEC)%1000);
    printf("\nheap sort: \n");
    start = clock();
    HeapSort(A2,100000);
    end = clock();
    for(int i =0; i< 100000; i++){
        printf(" %d",A2[i]);
    }
    printf("\ntime is : %d ms",((end-start)*1000/ CLOCKS_PER_SEC)%1000);
}
