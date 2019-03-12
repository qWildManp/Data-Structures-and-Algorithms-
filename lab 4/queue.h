#include<stdio.h>
typedef struct{
    double* values;
    int front;
    int rear;
    int counter;
    int maxSize;
} Queue;
bool CreateQueue(Queue *queue, int size);
bool IsEmpty(Queue* queue);
bool IsFull(Queue* queue);
bool Enqueue(Queue* queue, double x);
bool Dequeue(Queue* queue, double* x);
void DisplayQueue(Queue* queue);
void DestroyQueue(Queue* queue);