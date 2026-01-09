#include <stdio.h>

int main() {
    // assining array size 10
    int numbers[10];
    int sum = 0;
    
    printf("enter 10 numbers:");

    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
        sum = sum + numbers[i];  
    }

    int average = sum / 10;  
    printf("Sum = %d", sum);
    printf("Average = %d", average);

    return 0;
}
