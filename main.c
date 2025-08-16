#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    float marks;
    struct Student* next;
};

struct Student* head = NULL;

struct Student* createStudent(int id, char name[], int age, float marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->marks = marks;
    newStudent->next = NULL;
    return newStudent;
}

void addStudent(int id, char name[], int age, float marks) {
    struct Student* newStudent = createStudent(id, name, age, marks);
    if (head == NULL) {
        head = newStudent;
        return;
    }
    struct Student* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newStudent;
}

void displayStudents() {
    if (head == NULL) {
        printf("No student records found.\n");
        return;
    }
    struct Student* temp = head;
    printf("\n--- Student Records ---\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Age: %d | Marks: %.2f\n", temp->id, temp->name, temp->age, temp->marks);
        temp = temp->next;
    }
}

void searchStudent(int id) {
    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Student Found: ID: %d | Name: %s | Age: %d | Marks: %.2f\n",
                   temp->id, temp->name, temp->age, temp->marks);
            return;
        }
        temp = temp->next;
    }
    printf("Student with ID %d not found.\n", id);
}

void deleteStudent(int id) {
    struct Student* temp = head;
    struct Student* prev = NULL;

    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Student with ID %d deleted successfully.\n", id);
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Student with ID %d deleted successfully.\n", id);
}

int main() {
    int choice, id, age;
    char name[50];
    float marks;

    while (1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Delete Student by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter ID: ");
            scanf("%d", &id);
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Age: ");
            scanf("%d", &age);
            printf("Enter Marks: ");
            scanf("%f", &marks);
            addStudent(id, name, age, marks);
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            printf("Enter ID to search: ");
            scanf("%d", &id);
            searchStudent(id);
            break;
        case 4:
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            deleteStudent(id);
            break;
        case 5:
            printf("Exiting... Thank you!\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
