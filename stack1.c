#include <stdio.h>
#include <stdlib.h>

int main() {
    int capacity;
    printf("Enter capacity of stack: ");
    scanf("%d", &capacity);

    int *arr = (int*) malloc(capacity * sizeof(int));  // Allocate space for stack
    int top = -1;  // Stack is initially empty

    int choice, value;

    while (1) {
        printf("\nChoose operation:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {  // Push
            if (top == capacity - 1) 
            {
                printf("Stack Overflow! Cannot push more elements\n");
            } 
            else 
            {
                printf("Enter value to push: ");
                scanf("%d", &value);
                top++;
                arr[top] = value;
                printf("%d pushed to stack\n", value);
            }
        }
        else if (choice == 2) {  // Pop
            if (top == -1) {
                printf("Stack Underflow! Stack is empty\n");
            } else {
                value = arr[top];
                top--;
                printf("Popped value: %d\n", value);
            }
        }
        else if (choice == 3) {  // Peek
            if (top == -1) {
                printf("Stack is empty! Nothing to peek\n");
            } else {
                printf("Top element: %d\n", arr[top]);
            }
        }
        else if (choice == 4) {  // Exit
            free(arr);  // Free memory
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
