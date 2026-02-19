#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int stack[MAX];
int TOP = -1;

void show(){
    if(TOP < 0){
        printf("\nStack Empty\n");
        return;
    }

    printf("\nStack: ");
    for(int i = 0; i <= TOP; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void count(){
    int total = TOP + 1;
    printf("Total elements: %d\n", total);
    show();
}

void push(){
    if(TOP == MAX - 1){
        printf("Stack Overflow\n");
        return;
    }

    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    TOP++;
    stack[TOP] = value;

    show();
}

void pop(){
    if(TOP == -1){
        printf("Stack Underflow\n");
        return;
    }

    printf("Popped: %d\n", stack[TOP]);
    TOP--;

    show();
}

int main(){
    int option;

    while(1){
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Count\n");
        printf("5.Exit\n");
        printf("Choice: ");
        scanf("%d", &option);

        switch(option){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: show(); break;
            case 4: count(); break;
            case 5: printf("Exiting\n"); exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
