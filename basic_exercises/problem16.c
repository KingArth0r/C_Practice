#include <stdio.h>

int main() {
    int amount, num100s, num50s, num20s, num10s, num5s, num1s;
    printf("Inpute amount: ");
    scanf("%d", &amount);
    num100s = (int) amount / 100;
    amount -= num100s * 100;
    num50s = (int) amount / 50;
    amount -= num50s * 50;
    num20s = (int) amount / 20;
    amount -= num20s * 20;
    num10s =  (int) amount / 10;
    amount -= 10 * num10s;
    num5s = (int) amount / 5;
    amount -= 5 * num5s;
    num1s = amount;

    printf("\n# of 100s: %d\n", num100s);
    printf("# of 50s: %d\n", num50s);
    printf("# of 20s: %d\n", num20s);
    printf("# of 10s: %d\n", num10s);
    printf("# of 5s: %d\n", num5s);
    printf("# of 1s: %d\n", num1s);

    return 0;
}