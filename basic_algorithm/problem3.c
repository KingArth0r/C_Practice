#include <stdio.h>

int algorithm(int a, int b) {
    return (a > 30 || b > 30 || a + b > 30);
}

int main() {
    int input1, input2, result;
    printf("Input 2 numbers: \n");
    scanf("%d", &input1);
    scanf("%d", &input2);
    result = algorithm(input1, input2);
    printf("The result is %d\n", result);

    return 0;
}