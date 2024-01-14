#include <stdio.h>

int main() {
    int height = 7; //inches
    int width = 5; //inches
    int perimeter = 2*height + 2*width;
    int area = width*height;

    printf("Perimeter of the rectangle = %d inches\n", perimeter);
    printf("Area of the rectangle = %d inches\n", area);

    return 0;

}