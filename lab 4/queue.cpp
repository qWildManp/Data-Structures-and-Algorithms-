#include<stdio.h>
#include "queue.h"
#include<stdlib.h>
bool CreateQueue(Queue *queue,int size){
    if(size <= 0)
        return false;
    queue->values = (double*)malloc(sizeof(double)*size);
    queue->front = 0;//queue dont have any elements so the front is zero
    queue->rear = -1;//and its rear doesn't exist -- set to -1
    queue->counter = 0;//the counter is zero
    queue->maxSize = size;//the maxSize of the queue is the size value
    return true;
}
bool IsEmpty(Queue* queue){//check if the queue is empty
    if(queue->counter == 0)
        return true;
    return false;
}
bool IsFull(Queue* queue){//check if the queue is full
    if(queue->counter == queue->maxSize)
        return true;
    return false;
}
bool Enqueue(Queue* queue, double x){//add a element at the rear
    if(IsFull(queue))
        return false;
    else{
        queue->rear = (queue->rear+1) % queue->maxSize;//circular increase the rear
        queue->values[queue->rear]= x;
        queue->counter++;
        return true;
    }
}
bool Dequeue(Queue* queue, double* x){//pop the element at the front
    if(IsEmpty(queue)){
        return false;
    }
    else{
        *x = queue->values[queue->front];
        queue->front++;
        queue->counter--;
        return true;
    }
}
void DisplayQueue(Queue* queue){//display the queue
    int count = queue->counter;
    int j = queue->front;
    for(int i = 0;i < count; i++){//loop to print out each element in queue
        if(i == 0){
            printf("front-->       %10lf\n",queue->values[j]);
        }
        else if(i == count-1){// if the i reach the end of the queue
            printf("               %10lf          <--rear\n",queue->values[j]);
            break;
        }
        else{
            printf("               %10lf\n",queue->values[j]);
        }
        j = (j+1) % queue->maxSize; //sequence increase the index
    }
}
void DestroyQueue(Queue* queue){
    free(queue->values);
}
int main(void) {
    Queue queue;
    double value;
    CreateQueue(&queue, 5);
    puts("Enqueue 5 items.");
    for (int x = 0; x < 5; x++)
        Enqueue(&queue, x);
    puts( "Now attempting to enqueue again...");
    Enqueue(&queue, 5);
    DisplayQueue(&queue);
    Dequeue(&queue, &value);
    printf("Retrieved element = %g\n", value);
    DisplayQueue(&queue);
    Enqueue(&queue, 7);
    DisplayQueue(&queue);
    DestroyQueue(&queue);
}