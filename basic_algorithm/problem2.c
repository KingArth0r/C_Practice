#include <stdio.h>

int algo(int a) {
    if (a > 51) return 3 * (a - 51);
    else if (a < 0) return (51 + a);
    else return 51 - a;
}

int main() {
    int input, result;

    printf("Input a number: ");
    scanf("%d", &input);
    result = algo(input);
    printf("\nResult: %d\n", result);

    return 0;
}