#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
bool CreateStack(Stack *stack, int size){
    if (size <= 0)// if the size of stack cannot not greater than zero
        return false;
    stack->values = (double*)malloc(sizeof(double)*size);//create a memory space to store the data
    stack->top = -1;//the stack start with 0 and now is empty so let top be -1
    stack->maxTop = size - 1;
    return true;
}
bool IsEmpty(Stack* stack){//check if the stack is empty
    if(stack->top == -1)
        return true;
    return false;
}
bool IsFull(Stack* stack){//check if the stack is full
    if(stack->top == stack->maxTop)
        return true;
    return false;
}
bool Top(Stack* stack, double* x){//return the top element of the stack
    if(IsEmpty(stack))
        return false;
    *x = stack->values[stack->top];
    return true;
}
bool Push(Stack* stack, double x){
    if(IsFull(stack))
        return false;
    stack->values[++stack->top] = x;//store a value in the stack
    return true;
}
bool Pop(Stack* stack, double* x){
    if(IsEmpty(stack))
        return false;
    *x = stack->values[stack->top--];
    return true;
}
void DisplayStack(Stack* stack){//display the stack
    if(IsEmpty(stack)){//if the stack is empty
        printf("\ntop->   |-------------------------|\n");
    }
    else{
        for(int i = stack->top;i >= 0;i--){//output the each value in the stack
            if(i == stack->top){
                printf("top->   |       %10lf        |\n",stack->values[i]);
            }
            else{printf( "        |       %10lf        |\n",stack->values[i]);}
    }
        printf("        |-------------------------|\n");
    }
}
void DestroyStack(Stack* stack){//destroy the whole stack
    free(stack->values);
}
int main(void) {
    Stack stack
    ;
    double val
    ;
    CreateStack(&stack, 5);
    Push(&stack, 5);
    Push(&stack, 6.5);
    Push(&stack,-3);
    Push(&stack,-8);
    DisplayStack(&stack);
    if(Top(&stack, &val))
        printf("Top: %g", val);
    Pop(&stack, &val);
    if(Top(&stack, &val))
        printf("Top: %g", val);
    while(!IsEmpty(&stack))
        Pop(&stack, &val);
    DisplayStack(&stack);
    DestroyStack(&stack);
}