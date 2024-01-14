#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    float radius = 6.0;
    float perimeter = 2*radius*PI;
    float area = PI*radius*radius;
    
    printf("Perimeter of the Circle = %0.6f inches\n", perimeter);
    printf("Area of the Circle = %0.6f square inches\n", area);

    return 0;
}