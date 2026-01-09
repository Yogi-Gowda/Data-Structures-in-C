#include <stdio.h>

//declaration
int sumofN(int);

//definition
int sumofN(int a)
{
    int sum = 0;
    for(int i=1;i<=a;i++){
        sum = sum + i;
    }
    return sum;
}

//declaration
int main(){
    int n,result;
    printf("Enter the positive number :");
    scanf("%d",&n);
    result = sumofN(n);
    printf("Sum of %d consective numbers are %d",n,result);
    return 0;
}
