#include <stdio.h>
#define NUM_DAYS_IN_YEAR 365
#define NUM_DAYS_IN_WEEK 7

int main() {
    int totalDays = 1329;
    int years = totalDays/NUM_DAYS_IN_YEAR;
    int weeks = (totalDays - years*NUM_DAYS_IN_YEAR)/NUM_DAYS_IN_WEEK;
    int days = (totalDays - years*NUM_DAYS_IN_YEAR - weeks*NUM_DAYS_IN_WEEK);
    
    printf("Years: %d\nWeeks: %d\nDays: %d\n", years, weeks, days);

    return 0;
}