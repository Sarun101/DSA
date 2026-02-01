#include<stdio.h>
#include<stdlib.h>

//The required global constants
#define MAX 10
int TOP = -1;
int stack[MAX];

//Display function//
void Display(){
    int i;
    if(TOP==-1){
        printf("\nThe STack is empty!\n");
        return;
    }
    for(i=0;i<=TOP;i++){
        printf(" | %d |\t", stack[i]);
    }
}

//Push function//
void Push(){
    if(TOP== MAX-1){
        printf("The Stsck is full");
        return;
    }
    TOP++;
    printf("Enter the data to enter: ");
    scanf("%d",&stack[TOP]);

    Display();
}

//Pop function

void Pop(){
    if(TOP==-1){
        printf("The stack is empty!");
    }
    printf("The element popped is %d\n\n",stack[TOP]);
    --TOP;
    Display();
}

//Count function

void Count(){
    int c=0;
    int i;
    for (i = 0;i<=TOP;i++){
        c++;
    }
    printf("There are %d elements in the stack!\n\n",c);

    Display();
}

int main(){
    int choice;
    while(1){

    printf("\n\n--------->MENU<---------\n\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Display\n");
    printf("4.Count\n");
    printf("5.Exit\n");

    printf("Enter the choice:");
    scanf("%d", &choice);

    switch(choice){

        case 1: Push();break;
        case 2: Pop();break;
        case 3: Display();break;
        case 4: Count();break;
        case 5: printf("Exiting...\n");exit(0);
        default: printf("Invalid Choice!");
    }
}
}