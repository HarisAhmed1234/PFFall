#include <stdio.h>
#include <string.h>

// Structure to hold worker data
struct Employee {
    int id;
    char first[20];
    char last[20];
    int salary;
    char joinDate[20];
    char dept[20];
};

void displayMaxSalaryEmployees(struct Employee employees[], int size) {
    char departments[10][20];
    int maxSalaries[10] = {0};
    int maxSalaryIndexes[10] = {-1};  

    for (int i = 0; i < 10; i++) {
        strcpy(departments[i], "");
    }

    // Find maximum salary and index for each department
    for (int i = 0; i < size; i++) {
        int deptIndex = -1;

        for (int j = 0; j < 10; j++) {
            if (strcmp(employees[i].dept, departments[j]) == 0) {
                deptIndex = j;
                break;
            } else if (strcmp(departments[j], "") == 0) {
                strcpy(departments[j], employees[i].dept);
                deptIndex = j;
                break;
            }
        }

        if (deptIndex != -1) {
            // Update max salary and index if the current salary is higher
            if (employees[i].salary > maxSalaries[deptIndex]) {
                maxSalaries[deptIndex] = employees[i].salary;
                maxSalaryIndexes[deptIndex] = i;
            }
        }
    }

    // Display details of employees with maximum salary for each department
    printf("\nDetails of Employees with Maximum Salary for Each Department:\n");
    for (int i = 0; i < 10; i++) {
        if (strcmp(departments[i], "") != 0 && maxSalaryIndexes[i] != -1) {
            printf("Department: %s\n", departments[i]);
            printf("Employee ID: %d\n", employees[maxSalaryIndexes[i]].id);
            printf("Name: %s %s\n", employees[maxSalaryIndexes[i]].first, employees[maxSalaryIndexes[i]].last);
            printf("Salary: %d\n", maxSalaries[i]);
            printf("Joining Date: %s\n", employees[maxSalaryIndexes[i]].joinDate);
            printf("-------------\n");
        }
    }
}

// Function to calculate and display total salaries (each department)
void fetchTotalSalariesByDepartment(struct Employee employees[], int size) {
    char departments[10][20];
    int totalSalaries[10] = {0};

    for (int i = 0; i < 10; i++) {
        strcpy(departments[i], "");
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 10; j++) {
            if (strcmp(employees[i].dept, departments[j]) == 0) {
                totalSalaries[j] += employees[i].salary;
                break;
            } else if (strcmp(departments[j], "") == 0) {
                strcpy(departments[j], employees[i].dept);
                totalSalaries[j] += employees[i].salary;
                break;
            }
        }
    }

    // Display departments along with total salaries
    printf("\nDepartments and Total Salaries:\n");
    for (int i = 0; i < 10; i++) {
        if (strcmp(departments[i], "") != 0) {
            printf("%s - %d\n", departments[i], totalSalaries[i]);
        }
    }
}

int main() {
    printf("Haris Ahmed\n23k-6005\n\n");

    struct Employee employees[] = {
        {1, "Monika", "Arora", 100000, "2014-02-20 09:00:00", "HR"},
        {2, "Niharika", "Verma", 80000, "2014-06-11 09:00:00", "Admin"},
        {3, "Vishal", "Singhal", 300000, "2014-02-20 09:00:00", "HR"},
        {4, "Amitabh", "Singh", 500000, "2014-02-20 09:00:00", "Admin"},
        {5, "Vivek", "Bhati", 500000, "2014-06-11 09:00:00", "Admin"},
        {6, "Vipul", "Diwan", 200000, "2014-06-11 09:00:00", "Account"},
        {7, "Satish", "Kumar", 75000, "2014-01-20 09:00:00", "Account"},
        {8, "Geetika", "Chauhan", 90000, "2014-04-11 09:00:00", "Admin"},
    };

    int size = sizeof(employees) / sizeof(employees[0]);

    displayMaxSalaryEmployees(employees, size);

    fetchTotalSalariesByDepartment(employees, size);

    return 0;
}
