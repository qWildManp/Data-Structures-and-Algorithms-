#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "Problem3.h"
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
void reverse(char* str){
    char temp;
    size_t len = strlen(str);
    for(int i = 0; i < len/2 ;i++){
        temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}
char* Uncompress(char* str){
    if(str == NULL){//if the string is null return null
        return NULL;
    }
    char temp[10000];
    memset(temp,'\0', sizeof(temp));
    Stack stack;
    CreateStack(&stack,10000);
    for(int i = 0 ; i < strlen(str);i++){//loop to scan the hole string
        int j = 0;
        if(str[i] == ')'){//if the str[i] meets the ')' ,start uncompress
            while(stack.string[stack.top] != '('){//if stack top not equal to '(' pop the top out and store into the temp string
                temp[j++] = Pop(&stack);
            }
            Pop(&stack);//pop pout the '('
            reverse(temp);//reverse the temp string because the output is reversed
            int k = 0;
            int num = 0;
            while(stack.string[stack.top] >= '0' && stack.string[stack.top] <= '9'){//get the number
                int str_number = (int)Pop(&stack)-48;
                num = (int)(num + str_number * pow(10, k));
                k++;
            }
            for(int n = 0;n < num;n++){//add num times of the temp string into the stack
                for(int m = 0; m < strlen(temp);m++){
                    Push(&stack,temp[m]);
                }
            }
            memset(temp,'\0', sizeof(temp));//reset the temp string
        }
        else{//if not meet the ')',push str[i] into the stack
            Push(&stack,str[i]);
        }

    }
    memset(str,'\0', sizeof(temp));//reset the temp string
    for(int m = 0;stack.top != -1; m++){//update the uncompressed string to the original string
        temp[m] = Pop(&stack);
    }
    reverse(temp);
    return temp;
}

int main(){
    char str1[10000] =  {"5(ab)"};
    char str2[10000] =  {"5(ab2(cd))"};
    char str3[10000] = {"2(bc)3(ac)"};
    char str4[10000] = {"abcdse"};
    char str5[10000] = {""};
    char *nullstring;
    printf("String1 Uncompress successful!: %s\n",Uncompress(str1));
    printf("String2 Uncompress successful!: %s\n",Uncompress(str2));
    printf("String3 Uncompress successful!: %s\n",Uncompress(str3));
    printf("String4 Uncompress successful!: %s\n",Uncompress(str4));
    printf("String5 Uncompress successful!: %s\n",Uncompress(str5));
    printf("nullstring Uncompress successful!: %s\n",Uncompress(nullstring));
    return 0;
}
