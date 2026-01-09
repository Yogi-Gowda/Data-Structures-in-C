#include <stdio.h>

int main() {
    int n, key;
    int arr[100];

    printf("enter number of elements: ");
    scanf("%d", &n);

    printf("enter elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("enter the element to search: ");
    scanf("%d", &key);

    int first = 0;
    int last = n - 1;

    while (first <= last) {
        int mid = (first + last) / 2;

        if (arr[mid] == key) {
            printf("element found at index %d", mid + 1);
            return 0; 
        }
        else if (arr[mid] < key) {
            first = mid + 1;
        }
        else {
            last = mid - 1;
        }
    }

    printf("element not found.");
    return 0;
}
