#include <stdio.h>

int main() {
    int a;
    int b;

    printf("Input the first integer: ");
    scanf("%d", &a);
    printf("\nInput the second integer: ");
    scanf("%d", &b);
    printf("The product of the above two integers = %d\n", a * b);

    return 0;
}