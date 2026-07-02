#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};

void addPatient();
void viewPatients();
void searchPatient();
void updatePatient();
void deletePatient();

int main() {
    int choice;

    while (1) {
        printf("\n====== HOSPITAL PATIENT RECORD SYSTEM ======\n");
        printf("1. Add Patient\n");
        printf("2. View All Patients\n");
        printf("3. Search Patient\n");
        printf("4. Update Patient\n");
        printf("5. Delete Patient\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;

            case 2:
                viewPatients();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                updatePatient();
                break;

            case 5:
                deletePatient();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void addPatient() {
    FILE *fp = fopen("patients.dat", "ab");
    struct Patient p;

    printf("Enter Patient ID: ");
    scanf("%d", &p.id);

    printf("Enter Name: ");
    getchar();
    fgets(p.name, 50, stdin);
    p.name[strcspn(p.name, "\n")] = '\0';

    printf("Enter Age: ");
    scanf("%d", &p.age);

    printf("Enter Disease: ");
    getchar();
    fgets(p.disease, 50, stdin);
    p.disease[strcspn(p.disease, "\n")] = '\0';

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);

    printf("Patient added successfully!\n");
}

void viewPatients() {
    FILE *fp = fopen("patients.dat", "rb");
    struct Patient p;

    if (!fp) {
        printf("No records found.\n");
        return;
    }

    printf("\n---- PATIENT LIST ----\n");

    while (fread(&p, sizeof(p), 1, fp)) {
        printf("ID: %d\n", p.id);
        printf("Name: %s\n", p.name);
        printf("Age: %d\n", p.age);
        printf("Disease: %s\n\n", p.disease);
    }

    fclose(fp);
}

void searchPatient() {
    FILE *fp = fopen("patients.dat", "rb");
    struct Patient p;
    int id, found = 0;

    if (!fp) {
        printf("No records found.\n");
        return;
    }

    printf("Enter Patient ID to search: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            printf("\nPatient Found!\n");
            printf("ID: %d\n", p.id);
            printf("Name: %s\n", p.name);
            printf("Age: %d\n", p.age);
            printf("Disease: %s\n", p.disease);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No patient found with ID %d\n", id);

    fclose(fp);
}

void updatePatient() {
    FILE *fp = fopen("patients.dat", "rb+");
    struct Patient p;
    int id, found = 0;

    if (!fp) {
        printf("No records found.\n");
        return;
    }

    printf("Enter Patient ID to update: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            printf("Enter new Name: ");
            getchar();
            fgets(p.name, 50, stdin);
            p.name[strcspn(p.name, "\n")] = '\0';

            printf("Enter new Age: ");
            scanf("%d", &p.age);

            printf("Enter new Disease: ");
            getchar();
            fgets(p.disease, 50, stdin);
            p.disease[strcspn(p.disease, "\n")] = '\0';

            fseek(fp, -sizeof(p), SEEK_CUR);
            fwrite(&p, sizeof(p), 1, fp);

            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Patient record not found!\n");

    fclose(fp);
}

void deletePatient() {
    FILE *fp = fopen("patients.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Patient p;
    int id, found = 0;

    if (!fp) {
        printf("No records found.\n");
        return;
    }

    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            found = 1;
            continue;
        }

        fwrite(&p, sizeof(p), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("patients.dat");
    rename("temp.dat", "patients.dat");

    if (found)
        printf("Patient record deleted successfully!\n");
    else
        printf("Patient not found!\n");
}