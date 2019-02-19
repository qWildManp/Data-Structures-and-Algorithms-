#include <stdio.h>
long int factR(long n){//the factorial function
    if(n == 1) {//the base case
        return 1;
    }
    else if(n > 1){//the recursion
        return n*factR(n-1);
    }
}
int main() {
    long num;
    printf("Please input a positive number to calculate its factorial :\n");
    scanf("%ld",&num);//read a number from console
    while(num < 0){//check the input is a positive number
        printf("Positive number required");
        printf("Please input a positive number to calculate its factorial :\n");
        scanf("%ld",&num);
    }
    printf("The answer is %ld",factR(num));//output the result
    return 0;
}
