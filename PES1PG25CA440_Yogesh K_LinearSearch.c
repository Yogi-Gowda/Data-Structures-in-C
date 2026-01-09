#include <stdio.h>

int main() {
    int n,key;
    int arr[100];  

    printf("enter number of elements: ");
    scanf("%d", &n);

    printf("enter %d elements:", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("enter the element to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("element found at index %d", i + 1);
            break;
        }else if (i == n-1){
            printf("element not found");
        }
    }
    return 0;
printf("element not found");
}
