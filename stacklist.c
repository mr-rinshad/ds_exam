#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push (Insert at Top)
void push(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop (Delete from Top)
void pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node *temp = top;
    printf("Popped element: %d\n", top->data);
    top = top->next;
    free(temp);
}

// Display Stack
void display() {
    if(top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = top;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;
    while(1) {
        printf("----menu----");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
