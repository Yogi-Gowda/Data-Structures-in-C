#include <stdio.h>

int main() {
    char c;
    int i;
    float f;
    double d;

    char *cp = NULL;
    int *ip = NULL;
    float *fp = NULL;
    double *dp = NULL;

    printf("Size of char: %lu bytes\n", sizeof(c));
    printf("Size of int: %lu bytes\n", sizeof(i));
    printf("Size of float: %lu bytes\n", sizeof(f));
    printf("Size of double: %lu bytes\n", sizeof(d));

    printf("\nSize of char pointer: %lu bytes\n", sizeof(cp));
    printf("Size of int pointer: %lu bytes\n", sizeof(ip));
    printf("Size of float pointer: %lu bytes\n", sizeof(fp));
    printf("Size of double pointer: %lu bytes\n", sizeof(dp));

    return 0;
}
