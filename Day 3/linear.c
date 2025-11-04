#include <stdio.h>
#define MAX 2

int queue[MAX];
int front = -1, rear = -1;


void insert(int item) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", item);
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = item;
        printf("%d inserted into queue.\n", item);
    }
}


void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}


void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, item;
    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
