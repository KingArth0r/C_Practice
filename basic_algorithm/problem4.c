#include <stdio.h>

int algorithm(int a) {
    return ((a >= 90 && a <= 110) || (a >= 190 && a <= 210));
}

int main() {
    int input, result;
    printf("Input a number: \n");
    scanf("%d", &input);
    result = algorithm(input);
    printf("The result is %d\n", result);
    
    return 0;
}