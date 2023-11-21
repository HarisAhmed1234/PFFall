#include <stdio.h>

// Define the Employee structure
struct Employee {
    char name[50];
    float salary;
    float hours_worked;
};

// Function to calculate the final salary based on hours worked
float calculate_salary(float base_salary, float hours_worked) {
    if (hours_worked < 8) {
        return base_salary;  // No increase if hours worked are less than 8
    } else if (hours_worked >= 8 && hours_worked < 10) {
        return base_salary + 50;
    } else if (hours_worked >= 10 && hours_worked < 12) {
        return base_salary + 100;
    } else {
        return base_salary + 150;
    }
}

int main() {
    // Declare an array to store 10 employees
    struct Employee employees[10];

    // Get input from the user for each employee
    int i;
	for ( i = 0; i < 10; i++) {
        printf("Enter employee name: ");
        scanf("%s", employees[i].name);

        printf("Enter employee salary: ");
        scanf("%f", &employees[i].salary);

        printf("Enter hours of work per day: ");
        scanf("%f", &employees[i].hours_worked);
    }

    // Calculate and print the final salaries for each employee
    printf("\nFinal Salaries:\n");
    ;
	for ( i = 0; i < 10; i++) {
        float final_salary = calculate_salary(employees[i].salary, employees[i].hours_worked);
        printf("%s: $%.2f\n", employees[i].name, final_salary);
    }

    return 0;
}
