#include <stdio.h>

int main() {

    char employeeID[10];
    double totalHoursWorkedInMonth;
    double hourlyWage;

    printf("Input the Employee's ID: ");
    scanf("%s", employeeID);
    printf("\nInput the total hours worked this month: ");
    scanf("%lf", &totalHoursWorkedInMonth);
    printf("\nInput hourly wage: ");
    scanf("%lf", &hourlyWage);
    printf("\nEmployee ID = %s\nSalary = %0.2f\n", employeeID, totalHoursWorkedInMonth * hourlyWage);


    return 0;
}