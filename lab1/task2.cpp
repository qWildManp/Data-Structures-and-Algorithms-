#include <stdio.h>
#include<string.h>
void reverseR(int len,char *str){//reverse function
    char temp;
    if(len == 0 || len == 1){//base case

    }
    else if(len > 1){//recursion
        temp = *str;
        *str = str[len-1];
        str[len-1] = temp;
        reverseR((len-2), str+1);
    }
}
int main() {
    char str[50];
    printf("Please input a string to reverse (length should be less than 50):\n");
        scanf("%s",&str);//get a string
    int len = strlen(str);
    reverseR(len,str);
    printf(str);
    return 0 ;
}
