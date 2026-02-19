#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_end(){
    struct Node *newNode, *ptr;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory Error\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        display();
        return;
    }

    ptr = head;
    while(ptr->next){
        ptr = ptr->next;
    }

    ptr->next = newNode;
    display();
}

void display(){
    struct Node *current = head;

    if(current == NULL){
        printf("\nList is empty.\n");
        return;
    }

    printf("\nHEAD -> ");
    while(current){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insert_beginning(){
    struct Node *tempNode;

    tempNode = (struct Node*)malloc(sizeof(struct Node));
    if(tempNode == NULL){
        printf("Memory Error\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &tempNode->data);

    tempNode->next = head;
    head = tempNode;

    display();
}

void insert_pos(int pos){
    struct Node *newNode, *move;
    int index = 1;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &newNode->data);

    if(pos == 1){
        newNode->next = head;
        head = newNode;
        display();
        return;
    }

    move = head;
    while(index < pos - 1 && move->next){
        move = move->next;
        index++;
    }

    newNode->next = move->next;
    move->next = newNode;

    display();
}

void delete_last(){
    struct Node *temp, *previous = NULL;

    if(head == NULL){
        printf("Nothing to delete.\n");
        return;
    }

    temp = head;

    while(temp->next){
        previous = temp;
        temp = temp->next;
    }

    printf("Deleted node: %d\n", temp->data);

    if(previous == NULL){
        head = NULL;
    } else {
        previous->next = NULL;
    }

    free(temp);
    display();
}

void delete_beginning(){
    struct Node *temp;

    if(head == NULL){
        printf("Nothing to delete.\n");
        return;
    }

    temp = head;
    printf("Deleted node: %d\n", temp->data);

    head = temp->next;
    free(temp);

    display();
}

void delete_pos(int pos){
    struct Node *current, *before;
    int count = 1;

    if(head == NULL){
        printf("Nothing to delete.\n");
        return;
    }

    if(pos == 1){
        delete_beginning();
        return;
    }

    current = head;
    before = NULL;

    while(count < pos && current){
        before = current;
        current = current->next;
        count++;
    }

    if(current == NULL){
        printf("Position not found.\n");
        return;
    }

    before->next = current->next;
    printf("Deleted node: %d\n", current->data);
    free(current);

    display();
}

void count(){
    int total = 0;
    struct Node *scan = head;

    while(scan){
        total++;
        scan = scan->next;
    }

    printf("\nTotal nodes present: %d\n", total);
}

int main(){
    int choice, option, position;

    while(1){
        printf("\nMENU\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Count\n");
        printf("5. Exit\n");
        printf("\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("\n1. Beginning\n");
                printf("2. Specific Position\n");
                printf("3. End\n");
                printf("Select: ");
                scanf("%d", &option);

                if(option == 1) insert_beginning();
                else if(option == 2){
                    printf("Position: ");
                    scanf("%d", &position);
                    insert_pos(position);
                }
                else if(option == 3) insert_end();
                else printf("Invalid option\n");
                break;

            case 2:
                printf("\n1. Beginning\n");
                printf("2. Specific Position\n");
                printf("3. End\n");
                printf("Select: ");
                scanf("%d", &option);

