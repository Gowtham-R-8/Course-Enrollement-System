#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50

// Define the student node
typedef struct Student {
    int id;
    char name[NAME_LENGTH];
    struct Student* next;
} Student;

// Head pointer for the student list
Student* head = NULL;

// Function to add a student
void add_student(int id, const char* name) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    new_student->id = id;
    strcpy(new_student->name, name);
    new_student->next = NULL;

    if (head == NULL) {
        head = new_student;
    } else {
        Student* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_student;
    }

    printf("Student '%s' added.\n", name);
}

// Function to drop a student
void drop_student(int id) {
    Student *temp = head, *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student ID %d not found.\n", id);
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Student ID %d dropped.\n", id);
}

// Function to search for a student
void search_student(int id) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Student Found: %s (ID: %d)\n", temp->name, temp->id);
            return;
        }
        temp = temp->next;
    }
    printf("Student ID %d not found.\n", id);
}

// Function to display students
void display_students() {
    if (head == NULL) {
        printf("No students enrolled.\n");
        return;
    }

    Student* temp = head;
    printf("Students enrolled:\n");
    while (temp != NULL) {
        printf("-> %s (ID: %d)\n", temp->name, temp->id);
        temp = temp->next;
    }
}

// Function to reverse the student list
void reverse_list() {
    Student *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }

    head = prev;
    printf("Student list has been reversed.\n");
}

// Main menu
int main() {
    int choice, id;
    char name[NAME_LENGTH];

    while (1) {
        printf("\n--- Course Enrollment System ---\n");
        printf("1. Add Student\n");
        printf("2. Drop Student\n");
        printf("3. Search Student\n");
        printf("4. Display Students\n");
        printf("5. Reverse Student List\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // to consume newline

        switch (choice) {
            case 1:
                printf("Enter Student ID: ");
                scanf("%d", &id);
                getchar(); // clear newline
                printf("Enter Student Name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // remove newline
                add_student(id, name);
                break;
            case 2:
                printf("Enter Student ID to drop: ");
                scanf("%d", &id);
                drop_student(id);
                break;
            case 3:
                printf("Enter Student ID to search: ");
                scanf("%d", &id);
                search_student(id);
                break;
            case 4:
                display_students();
                break;
            case 5:
                reverse_list();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
