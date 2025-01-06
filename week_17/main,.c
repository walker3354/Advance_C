#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { CHT, FET, TWN } Operator;

typedef union {
        struct {
                int areaCode;
                char number[15];
        } home;
        struct {
                Operator operatorName;
                char number[15];
        } cellular;
} PhoneNumber;

typedef struct Node {
        char name[10];
        int isCellular;
        PhoneNumber phone;
        struct Node* next;
} Node;

Node* head = NULL;

void addUser() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;

    printf("Enter name (max 10 characters): ");
    scanf("%9s", newNode->name);

    printf("Phone type (0: home phone, 1: cellular phone): ");
    scanf("%d", &newNode->isCellular);

    if (newNode->isCellular == 0) {
        printf("Enter home phone area code: ");
        scanf("%d", &newNode->phone.home.areaCode);
        printf("Enter home phone number: ");
        scanf("%14s", newNode->phone.home.number);
    } else {
        printf("Select cellular operator (0: CHT, 1: FET, 2: TWN): ");
        int operatorChoice;
        scanf("%d", &operatorChoice);
        newNode->phone.cellular.operatorName = (Operator)operatorChoice;
        printf("Enter cellular phone number: ");
        scanf("%14s", newNode->phone.cellular.number);
    }

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printUsers() {
    if (head == NULL) {
        printf("No user data available.\n");
        return;
    }

    Node* temp = head;
    printf("\nSaved user data:\n");
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        if (temp->isCellular == 0) {
            printf("Home phone: (%d) %s\n", temp->phone.home.areaCode,
                   temp->phone.home.number);
        } else {
            printf("Cellular phone: ");
            switch (temp->phone.cellular.operatorName) {
                case CHT:
                    printf("CHT");
                    break;
                case FET:
                    printf("FET");
                    break;
                case TWN:
                    printf("TWN");
                    break;
            }
            printf(" %s\n", temp->phone.cellular.number);
        }
        temp = temp->next;
    }
}

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add user data\n");
        printf("2. Print all user data\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                printUsers();
                break;
            case 3:
                printf("Program exited.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    Node* temp = head;
    while (temp != NULL) {
        Node* toFree = temp;
        temp = temp->next;
        free(toFree);
    }

    return 0;
}
