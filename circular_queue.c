#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int front =-1, rear =-1;
int queue[MAX];

void Display(){
    if (front == -1) {
        printf("The queue is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("| %d |", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}


void Enqueue(){
    if(front == (rear+1)%MAX){
        printf("The Queue is FULL!\n");
        return;
        
    }
    if(front==-1){
        front=0;
    }
    rear = (rear+1)%MAX;
    printf("Enter the data :");
    scanf("%d",&queue[rear]);

    Display();
}

void Dequeue(){
    if(front==-1){
        printf("The Queue is empty!\n");
        return;
    }
    else if(front==rear){
        printf("| %d | is deleted\n",queue[front]);
        front = -1;
        return;
    }
    printf("| %d | is deleted\n",queue[front]);
    front = (front+1)%MAX;

    Display();

}

int main(){
    int choice;
    while(1){

        printf("\n\n---------->MENU<----------\n\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Count\n");
        printf("5.Exit\n");
        printf("\n\n---------->OPTS<----------\n\n");

        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1: Enqueue();break;
            case 2: Dequeue();break;
            case 3: Display();break;
            case 4: printf("Count");break;
            case 5: printf("Exiting.....");exit(0);

            default: printf("Invalid Choice!");
        }
    }
}