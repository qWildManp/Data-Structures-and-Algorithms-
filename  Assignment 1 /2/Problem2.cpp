#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Problem2.h"
bool CreateStack(Stack *stack, int size){
    if (size <= 0)// if the size of stack cannot not greater than zero
        return false;
    stack->string = (char*)malloc(sizeof(char)*size);//create a memory space to store the data
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
bool Push(Stack* stack, char x){
    if(IsFull(stack))
        return false;
    stack->string[++stack->top] = x;//store a value in the stack
    return true;
}
char Pop(Stack* stack){
    if(IsEmpty(stack)){}
    else{
        return stack->string[stack->top--];
    };
}
bool ValidBrackets(char* str){
    if(str == NULL){//if the string doesn't exist, not valid
        return false;
    }
    else if(strlen(str) == 0){//if the string is empty,valid
        return true;
    }
    else{Stack stack;
        size_t len = strlen(str);
        CreateStack(&stack,len);
        for(int i = 0; i<strlen(str);i++){//loop to scan the string
            if(str[i] == '('||str[i] == '['||str[i] == '{'||str[i] == '<'){//if the current character is the opening brackets,start push
                Push(&stack,str[i]);
            }
            else if(str[i] == ')'||str[i] == ']'||str[i] == '}'||str[i] == '>'){//if the current character is the closing brackets
                if(IsEmpty(&stack)){//if the stack is empty , not valid
                    return false;
                }
                char temp = Pop(&stack);
                if((str[i]==')'&&temp!='(')||(str[i]==']'&&temp!='[')||(str[i]=='}'&&temp!='{')||(str[i]=='>'&&temp!='<')){//if the brackets are not match each other, not valid
                return false;
                }
            }
        }
        return IsEmpty(&stack);//scan all the string if stake is empty the string is valid else the string isn't valid
    }


}
int main(){
    char str1[10000]={"{()()[]}"};
    char str2[10000] = {"[[[[[}}}}"};
    char str3[10000] = {"{<}>"};
    char str4[10000] = {"{{{{{{{{"};
    char str5[10000] = {""};
    char *nullstr;
    printf("test of string 1:");
    if(ValidBrackets(str1)){//str2 is not empty
        printf("true\n");
    }
    else{
        printf("false\n");
    }
    printf("test of string 2:");
    if(ValidBrackets(str2)){//str2 is not empty
        printf("true\n");
    }
    else{
        printf("false\n");
    }
    printf("test of string 3:");
    if(ValidBrackets(str3)){//str3 is not empty
        printf("true\n");
    }
    else{
        printf("false\n");
    }

    printf("test of string 4:");
    if(ValidBrackets(str4)){//str4 is not empty
        printf("true\n");
    }
    else{
        printf("false\n");
    }
    printf("test of empty string:");
    if(ValidBrackets(str5)){//str4 is a empty string
        printf("true\n");
    }
    else{
        printf("false\n");
    }
    printf("test of nullstring:");
    if(ValidBrackets(nullstr)){//test of a null string
        printf("true\n");
    }
    else{
        printf("false\n");
    }
}