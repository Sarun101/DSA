#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;
int count = 0;

void display() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("Head -> ");
    do {
        printf("| %d |<->", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("\n");
}

void countnode() {
    printf("Total nodes: %d\n", count);
}

void insert_beginning() {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(head == NULL) {
        newnode->next = newnode->prev = newnode;
        head = newnode;
    } else {
        struct Node *last = head->prev;
        newnode->next = head;
        newnode->prev = last;
        last->next = newnode;
        head->prev = newnode;
        head = newnode;
    }
    count++;
    printf("Inserted %d at beginning\n", newnode->data);
    display();
}

void insert_last() {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(head == NULL) {
        newnode->next = newnode->prev = newnode;
        head = newnode;
    } else {
        struct Node *last = head->prev;
        last->next = newnode;
        newnode->prev = last;
        newnode->next = head;
        head->prev = newnode;
    }
    count++;
    display();
}

void insert_position(int position) {
    if(position < 1 || position > count + 1) {
        printf("Invalid position\n");
        return;
    }

    if(position == 1) {
        insert_beginning();
        return;
    }

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    struct Node *temp = head;
    for(int i = 1; i < position-1; i++)
        temp = temp->next;

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;

    count++;
    display();
}

void delete_beginning() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    if(head->next == head) { 
        head = NULL;
    } else {
        struct Node *last = head->prev;
        head = head->next;
        head->prev = last;
        last->next = head;
    }

    printf("Deleted node: %d\n", temp->data);
    free(temp);
    count--;
    display();
}

void delete_last() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *last = head->prev;

    if(last == head) { 
        head = NULL;
    } else {
        struct Node *second_last = last->prev;
        second_last->next = head;
        head->prev = second_last;
    }

    printf("Deleted node: %d\n", last->data);
    free(last);
    count--;
    display();
}

void delete_position(int position) {
    if(position < 1 || position > count) {
        printf("Invalid position\n");
        return;
    }

    if(position == 1) {
        delete_beginning();
        return;
    }

    struct Node *temp = head;
    for(int i = 1; i < position; i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("Deleted node: %d\n", temp->data);
    free(temp);
    count--;
    display();
}

int main() {
    int choice, subchoice, position;

    while(1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Count\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("1. Beginning  2. Position  3. Last\nChoice: ");
                scanf("%d", &subchoice);
                if(subchoice == 1) insert_beginning();
                else if(subchoice == 2) {
                    printf("Enter position: ");
                    scanf("%d", &position);
                    insert_position(position);
                }
                else if(subchoice == 3) insert_last();
                else printf("Invalid choice\n");
                break;

            case 2:
                printf("1. Beginning  2. Position  3. Last\nChoice: ");
                scanf("%d", &subchoice);
                if(subchoice == 1) delete_beginning();
                else if(subchoice == 2) {
                    printf("Enter position: ");
                    scanf("%d", &position);
                    delete_position(position);
                }
                else if(subchoice == 3) delete_last();
                else printf("Invalid choice\n");
                break;

            case 3: display(); break;
            case 4: countnode(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
