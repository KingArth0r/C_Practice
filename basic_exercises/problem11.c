#include <stdio.h>

int main () {

    // To make answer match website, change all types to double
    float itemWeight1;
    int numItem1;
    float itemWeight2;
    int numItem2;

    printf("Weight of item 1: ");
    scanf("%f", &itemWeight1);
    printf("\nNumber of item 1: ");
    scanf("%d", &numItem1);
    printf("\nWeight of item 2: ");
    scanf("%f", &itemWeight2);
    printf("\nNumber of item 2: ");
    scanf("%d", &numItem2);

    float average = (numItem1 * itemWeight1 + numItem2 * itemWeight2) / ((float) (numItem1 + numItem2));

    printf("\nAverage value = %f\n", average);

    return 0;
}
