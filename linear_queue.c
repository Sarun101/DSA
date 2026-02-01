#include<stdio.h>
#include<stdlib.h>
#define max 10
int front = -1,rear = -1;
int queue[max];

void Display(){
    int i;
    if(front==-1){
        printf("The queue is empty");
        return;
    }
    for(i = front;i<=rear;i++){
        printf("| %d |" ,queue[i]);
    }

}

void Enqueue(){
    if(front==-1)
    front = 0;
    if(rear==max-1){
        printf("The Queue is full!\n");
        return;
    }

    rear++;
    printf("Enter the input data: ");
    scanf("%d",&queue[rear]);

    Display();
}

void Dequeue(){
    if(front == -1){
        printf("The queue is empty\n");
        return;
    } 

    else if(front==rear){
        printf("| %d | is deleted\n",queue[front]);
        front=-1;
        rear=-1;
        Display();
        return;
    }
    printf("| %d | is deleted\n",queue[front]);
    front++;
    Display();
}

void Count(){
    int i;
    int count=0;
    for(i=front;i<=rear;i++){
        count++;
    }
    printf("There are %d Elements in The Queue!\n",count);
    printf("QUEUE:\n");
    Display();
}

int main(){
    int n;
    while(1){
        printf("\n\n\n---------->MENU<----------\n\n");
        printf("\t1. Enqueue\n");
        printf("\t2. Dequeue\n");
        printf("\t3. Display\n");
        printf("\t4. Count\n");   
        printf("\t5. Exit\n");
        printf("\n---------->OPTS<----------\n");

        printf("Enter the choice: ");
        scanf("%d",&n);
        switch(n){
            case 1: Enqueue();break;
            case 2: Dequeue();break;
            case 3: printf("The Queue data: \n");Display();break;
            case 4: Count();break;
            case 5: printf("Exit.........\n");exit(0);

            default: printf("Invalid!");
        
        }}
    }