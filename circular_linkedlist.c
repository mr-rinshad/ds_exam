#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node *temp = head;
    while(temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node *temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Delete a node by value
void deleteNode(int value) {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    // Delete head
    if(head->data == value) {
        if(head->next == head) { // only one node
            free(head);
            head = NULL;
            return;
        }

        struct Node *last = head;
        while(last->next != head)
            last = last->next;

        last->next = head->next;
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    // Delete non-head
    do {
        prev = temp;
        temp = temp->next;

        if(temp->data == value) {
            prev->next = temp->next;
            free(temp);
            return;
        }

    } while(temp != head);

    printf("Value not found.\n");
}

// Display list
void display() {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(back to head)\n");
}

int main() {
    int choice, value;

    while(1) {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
}
