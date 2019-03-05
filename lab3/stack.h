typedef struct Stack{
    double* values;
    int top;
    int maxTop;
};
bool CreateStack(Stack *stack, int size);
bool IsEmpty(Stack* stack);
bool IsFull(Stack* stack);
bool Top(Stack* stack, double* x);
bool Push(Stack* stack, double x);
bool Pop(Stack* stack, double* x);
void DisplayStack(Stack* stack);
void DestroyStack(Stack* stack);
