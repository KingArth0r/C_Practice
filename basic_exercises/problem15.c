#include <stdio.h>
#include <math.h> // when compiling include -lm at end to link the library

int main() {
    double x1, x2, y1, y2, distance;

    printf("Input x1: ");
    scanf("%lf", &x1);
    printf("\nInput y1: ");
    scanf("%lf", &y1);
    printf("\nInput x2: ");
    scanf("%lf", &x2);
    printf("\nInput y2: ");
    scanf("%lf", &y2);

    distance = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

    printf("Distance between the points: %lf\n", sqrt(distance));

    return 0;
}