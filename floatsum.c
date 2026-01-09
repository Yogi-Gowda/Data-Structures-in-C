#include <stdio.h>
//declaration
float add(float a, float b);

//definition
float add(float a, float b) {
    float sum = a + b;
    return sum;
}
//calling function
float main() {
    float a = 99, b = 9, result;
    result = add(a, b);
    printf("The sum is: %f", result);
    return 0;
}
