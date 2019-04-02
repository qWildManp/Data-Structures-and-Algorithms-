typedef struct Stack{
    char *string;
    int top;
    int maxTop;
};
bool CreateStack(Stack *stack, int size);
bool IsEmpty(Stack* stack);
bool IsFull(Stack* stack);
bool Push(Stack* stack, char x);
char Pop(Stack* stack);
bool ValidBrackets(char* str);