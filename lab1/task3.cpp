#include <stdio.h>
int GCD(int x,int y){
    if(x > y) {//if x>y
        if (y == 0) {//base case
            return x;
        } else if (y > 0) {//recursion
            return GCD(y, x % y);
        }
    }
    else{//if y>x
        if (x == 0) {//base case
            return y;
        } else if (x > 0) {//recursion
            return GCD(y % x , x);
        }
    }
}
int main() {
    int numx;
    int numy;
    printf("please input the first number :\n");
    scanf("%d",&numx);
    printf("pleasr input the second number :\n");
    scanf("%d",&numy);
    printf("The result is %d", GCD(numx,numy));
    return 0;
}