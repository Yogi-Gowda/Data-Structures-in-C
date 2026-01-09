#include <stdio.h>

//declaration
float sumofN(float);

//definition
float sumofN(float a)
{
    float sum = 0;
    for(float i=1;i<=a;i++){
        sum = sum + i;
    }
    return sum;
}

//declaration
float main(){
    float n,result;
    printf("Enter the positive number :");
    scanf("%f",&n);
    result = sumofN(n);
    printf("Sum of %f consective numbers are %f",n,result);
    return 0;
}
