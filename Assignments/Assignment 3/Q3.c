#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 30
#define FILE_PERSONAL "Personal.txt"
#define FILE_DEPARTMENT "Department.txt"
#define FILE_COMBINE "Combine.txt"

char *get_record(char *id, FILE *fp) {
    if (fp == NULL) return NULL;

    char buffer[BUFFER_SIZE], delim[2] = ",";
    char *record = (char *)malloc(sizeof(char) * BUFFER_SIZE);

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;

        char *record_id = strtok(buffer, delim);

        if (!strcmp(id, record_id)) {
            strcpy(record, strtok(NULL, delim));
            return record;
        }
    }

    return NULL;
}

bool check_record(char *id, FILE *fp) {
    if (fp == NULL) return false;

    char buffer[BUFFER_SIZE], delim[2] = ",";

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;

        char *record_id = strtok(buffer, delim);
        if (!strcmp(record_id, id)) return true;
    }

    return false;
}

int main() {
    char id[BUFFER_SIZE], merge[BUFFER_SIZE * 2];

    printf("Enter ID to merge: ");
    fgets(id, BUFFER_SIZE, stdin);
    id[strcspn(id, "\n")] = 0;

    if (id[0] == '\0') {
        printf("Invalid ID! Please provide a non-empty ID.\n");
        return 0;
    }

    FILE *personal = fopen(FILE_PERSONAL, "r");
    FILE *department = fopen(FILE_DEPARTMENT, "r");
    FILE *combine = fopen(FILE_COMBINE, "r");

    if (personal == NULL || department == NULL || combine == NULL) {
        perror("Error opening files");
        return 1;
    }

    char *name = get_record(id, personal);
    char *salary = get_record(id, department);

    fclose(department);
    fclose(personal);

    if (name == NULL || salary == NULL) {
        printf("Record missing in either both or one file!\n");
        free(name);
        free(salary);
        return 0;
    }

    fclose(combine);

    combine = fopen(FILE_COMBINE, "a");
    if (combine == NULL) {
        perror("Error opening Combine.txt");
        free(name);
        free(salary);
        return 1;
    }

    if (!check_record(id, combine)) {
        sprintf(merge, "%s,%s,%s\n", id, name, salary);
        fputs(merge, combine);

        printf("Record merged and appended successfully!\n");
    } else {
        printf("Record already exists!\n");
    }

    fclose(combine);
    free(name);
    free(salary);

    return 0;
}
