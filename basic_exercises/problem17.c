#include <stdio.h>

int main() {
    int inputSeconds, numHours, numMinutes, numSeconds;

    printf("Input seconds: ");
    scanf("%d", &inputSeconds);

    numHours = (int) inputSeconds / 3600;
    numMinutes = ((int) inputSeconds / 60) % 60;
    numSeconds = inputSeconds % 60;
    
    printf("\nH:M:S: - %d:%d:%d\n", numHours, numMinutes, numSeconds);

    return 0; 
}