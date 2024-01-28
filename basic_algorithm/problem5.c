#include <stdio.h>

int main() {
    int input, result;
    printf("Enter a number: \n");
    scanf("%d", &input);
    result = (input % 3 == 0) || (input % 7 == 0);
    printf("Result: %d\n", result);
    return 0;
}