#include <stdio.h>

void findPairs(int arr[], int n, int targetSum) {
    int found = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == targetSum) {
                printf("(%d,%d) ", arr[i], arr[j]);
                found = 1;
            }
        }
    }
    
    if(!found) {
        printf("No pairs found");
    }
}

int main() {
    int arr[] = {2, 4, 3, 5, 7, 8, 9};
    int n = 7;
    int target = 10;
    
    printf("Pairs with sum %d: ", target);
    findPairs(arr, n, target);
    
    return 0;
}