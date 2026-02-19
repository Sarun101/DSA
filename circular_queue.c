#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int front = -1, rear = -1;
int queue[MAX];

void Display(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    printf("Queue: ");

    while(1){
        printf("%d ", queue[i]);
        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void Enqueue(){
    if(front == (rear + 1) % MAX){
        printf("Queue Overflow\n");
        return;
    }

    if(front == -1)
        front = 0;

    rear = (rear + 1) % MAX;

    printf("Enter value: ");
    scanf("%d", &queue[rear]);

    Display();
}

void Dequeue(){
    if(front == -1){
        printf("Queue Underflow\n");
        return;
    }

    printf("Removed: %d\n", queue[front]);

    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front = (front + 1) % MAX;
    }

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
            case 4:
                if(front == -1)
                    printf("Count: 0\n");
                else if(rear >= front)
                    printf("Count: %d\n", rear - front + 1);
                else
                    printf("Count: %d\n", MAX - front + rear + 1);
                bre
