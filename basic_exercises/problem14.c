#include <stdio.h>

int main() {
    int distnace;
    float fuelSpent;

    printf("Input total distance in km: ");
    scanf("%d", &distnace);
    printf("\nInput total fuel spent in liters: ");
    scanf("%f", &fuelSpent);
    printf("\nAverage consumption (km/lt) %.2f\n", ((float) distnace)/fuelSpent);

    return 0;
}