#include <stdio.h>
//declaration
int add(int a, int b);

//definition
int add(int a, int b) {
    int sum = a + b;
    return sum;
}
//calling function
int main() {
    int a = 99, b = 9, result;
    result = add(a, b);
    printf("The sum is: %d", result);
    return 0;
}
