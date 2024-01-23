#include <stdio.h>

int sumOrTripleSum(int a,int b) {
    if (a == b) return 3 * (a + b);
    else return a + b;
}

int main() {
    int a,b, result;
    printf("Input two values: \n");
    scanf("%d", &a);
    scanf("%d", &b);

    result = sumOrTripleSum(a,b);

    printf("Result: %d\n", result);
    return 0;

}