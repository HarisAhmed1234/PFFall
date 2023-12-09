#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char name[20];
    char role[10];
    int communication;
    int teamwork;
    int creativity;
} Employee;

char *departmentNames[4] = {"HR", "Finance", "Marketing", "Logistics"};
char *commonNames[20] = {"John", "Emma", "Michael", "Olivia", "James", "Sophia", "Robert", "Emily", "William", "Ava", "David", "Isabella", "Richard", "Amelia", "Joseph", "Grace", "Daniel", "Lily", "Charles", "Chloe"};
char *roles[5] = {"Director", "Executive", "Manager", "Employee", "Trainee"};

// Function to create and initialize a department
void createDepartment(Employee *department, int size) {
    bool nameUsed[20] = {false};

    for (int i = 0; i < size; i++) {
        // Select a random name that hasn't been used
        int index;
        do {
            index = rand() % 20;
        } while (nameUsed[index]);

        // Initialize employee details
        strcpy(department[i].name, commonNames[index]);
        strcpy(department[i].role, roles[i]);
        department[i].communication = rand() % 100 + 1;
        department[i].teamwork = rand() % 100 + 1;
        department[i].creativity = rand() % 100 + 1;

        nameUsed[index] = true;
    }
}

// Function to print employees of a department
void printEmployees(Employee *department, int size) {
    printf("%7s|%9s|%15s|%11s|%12s|\n",
           "Name", "Role", "Communication", "Teamwork", "Creativity");

    for (int i = 0; i < size; i++) {
        printf("%-17s|%-11s|%10d|%8d|%8d|\n",
               department[i].name, department[i].role,
               department[i].communication, department[i].teamwork, department[i].creativity);
    }
}

// Function to find the department with the highest total stats
int findBestDepartment(Employee **departments, int size) {
    int maxStats = -1, bestDepartment = 0;

    for (int i = 0; i < size; i++) {
        int totalStats = 0;

        for (int j = 0; j < 5; j++) {
            totalStats += departments[i][j].communication + departments[i][j].teamwork + departments[i][j].creativity;
        }

        if (totalStats > maxStats) {
            maxStats = totalStats;
            bestDepartment = i;
        }
    }

    return bestDepartment;
}

int main() {
    srand((unsigned int)time(NULL));

    Employee *departments[4];
    for (int i = 0; i < 4; i++) {
        departments[i] = (Employee *)malloc(sizeof(Employee) * 5);
        createDepartment(departments[i], 5);
    }

    int bestDepartmentIndex = findBestDepartment(departments, 4);

    for (int i = 0; i < 4; i++) {
        if (i == bestDepartmentIndex)
            continue;
        printf("\nEmployees of department: %s\n", departmentNames[i]);
        printEmployees(departments[i], 5);
    }

    printf("\nBest department award goes to: %s\n", departmentNames[bestDepartmentIndex]);
    printEmployees(departments[bestDepartmentIndex], 5);

    // Free allocated memory
    for (int i = 0; i < 4; i++) {
        free(departments[i]);
    }

    return 0;
}
