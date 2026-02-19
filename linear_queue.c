#include<stdio.h>
#include<stdlib.h>

#define max 10

int front = -1, rear = -1;
int queue[max];

void Display(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void Enqueue(){
    if(rear == max - 1){
        printf("Queue Overflow\n");
        return;
    }

    if(front == -1)
        front = 0;

    rear++;
    printf("Enter value: ");
    scanf("%d", &queue[rear]);

    Display();
}

void Dequeue(){
    if(front == -1){
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front++;
    }

    Display();
}

void Count(){
    if(front == -1){
        printf("Total elements: 0\n");
        return;
    }

    int total = rear - front + 1;
    printf("Total elements: %d\n", total);
    Display();
}

int main(){
    int choice;

    while(1){
        printf("\n1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Count\n");
        printf("5.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: Enqueue(); break;
            case 2: Dequeue(); break;
            case 3: Display(); break;
            case 4: Count(); break;
            case 5: printf("Exiting\n"); exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
