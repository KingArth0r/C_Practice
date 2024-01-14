#include <stdio.h>

int main() {
    /*
    Basically the bigger type is what the output type specifier is
    Type sizes: https://www.ibm.com/docs/en/ibm-mq/7.5?topic=platforms-standard-data-types
    Format Specifiers: https://www.geeksforgeeks.org/format-specifiers-in-c/#:~:text=specifiers%20in%20C-,Format%20Specifier,-Description
    */

    int a = 125, b = 12345;
    long ax = 1234567890;
    short s = 4043;
    float x = 2.13459;
    double dx = 1.1415927;
    char c = 'W';
    unsigned long ux = 2541567890;

    printf("a + c = %d\n", a + c); //char promoted to int
    printf("x + c = %0.5f\n", x + c); //char promoted to double
    printf("dx + x = %lf\n", dx + x);
    printf("((int dx) + ax) = %ld\n", ((int)dx + ax));
    printf("a + x = %0.5f\n", a + x);
    printf("s + b = %d\n", s + b);
    printf("ax + b = %ld\n", ax + b);
    printf("s + c = %u\n", s + c);
    printf("ax + c = %ld\n", ax + c);
    printf("ax + ux = %lu\n", ax + ux);

    return 0;
}