#include <stdio.h>

int main() {
    int a,b,c;
    int max;
    printf("Input the first integer: ");
    scanf("%d", &a);
    printf("\nInput the second integer: ");
    scanf("%d", &b);
    printf("\nInput the thrid integer: ");
    scanf("%d", &c);
    
    if (a >= b && a >= c ) {
        max = a;
    } else if (b >= a && b >= c) {
        max = b;
    } else if (c >= a && c >= b) {
        max = c;
    } else {
        max = a;
    }

    printf("\nMaximum value of three integers: %d\n", max);
    
    return 0;
}