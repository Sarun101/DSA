#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* head = NULL;
void display(){
    if (head == NULL){
        printf("----->The list is empty<-----\n");  
        return;
    }
    struct Node *temp;
    temp = head;
    while (temp != NULL){
        printf("[ %d ]--> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert_beginning(){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
    display();
}
void insert_pos(int position){
    int i;
    struct Node *temp,*newnode;
    temp = head;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    if(position==1){
        temp = head;
        newnode->next=head;
        head=newnode;
    }
    for(i = 1;i<position-1;i++){
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    display();
}

void insert_end(){
    struct Node *newnode,*temp;
    temp = head;
    newnode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;

    if(head==NULL){
        head=newnode;
        return;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    display();
}

void delete_beginning(){
    struct Node *node;
    if(head==NULL){
        printf("List is empty!!");
        return;
    }
    node = head;
    printf("---->%d is deleted!<-----\n",node->data);
    head = node->next;
    display();
}

void delete_pos(int position){
    struct Node *node,*temp;
    int i;
    if(head==NULL){
        printf("The list is empty!");
        return;
    }
    temp = node = head;
    for(i = 1;i<position;i++){
        node = node->next;
    }
    for(i = 1; i<position-1;i++){
        temp = temp->next;
    }
    temp->next = node->next;
    display();

}

void delete_last(){
    struct Node *node,*prev;
    node = head;
    while(node->next!=NULL){
        prev = node;
        node = node->next;
    }
    printf("---->%d is deleted!<----\n",node->data);
    
    prev->next = NULL;
    free(node);
    display();
}

void count(){
    int count=0;
    struct Node *temp;
    temp = head;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    printf("\n\n There are %d Nodes Currently and it is: \n",count);

    display();
}

int main(){
    int n;
    int c;
    int position;
    while(1){
        printf("\n\n----------------->!!!MENU!!!<-----------------\n\n");
        printf("\t\t1. Insert\n");
        printf("\t\t2. Delete\n");
        printf("\t\t3. Display\n");
        printf("\t\t4. Count\n");
        printf("\t\t5. Exit\n");
        printf("\n----------------------------------------------\n\n");
        printf("Enter the choice: ");
        scanf("%d", &n);

        switch(n){

        case 1: 
            
            {
            
            printf("\n\n----------------->!!!MENU!!!<-----------------\n\n");
            printf("1.Insert at the beginnning Node\n");
            printf("2.Insert at the Specified Node\n");
            printf("3.Insert at the Last Node\n");
            printf("\n----------------------------------------------\n\n");
            scanf("%d",&c);
            switch(c){
                  case 1: insert_beginning();break;

                  case 2: 
                printf("Enter the position: ");
                scanf("%d",&position);
                insert_pos(position);
                break;

                  case 3: insert_end();break;

                  default: printf("Invalid input");
            }
        }
        break;

        case 2:{
            printf("\n\n----------------->!!!MENU!!!<-----------------\n\n");
             printf("1.Delete The First Node!\n");
             printf("2.Delete The Specified Node!\n");
             printf("3.Delete The Last Node!\n");
             printf("\n----------------------------------------------\n\n");
             printf("Enter the choice: ");
             scanf("%d",&c);
            
            
             switch(c){

                 case 1: delete_beginning();break;

                 case 2: printf("Enter the position: ");
                 scanf("%d",&position);
                 delete_pos(position);break;

                 case 3: delete_last();break;

                 default: printf("Invalid Choice!!");
            }
        }break;
            case 3: display(); break;
            case 4: count(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice\n"); break;
        }
    }
    return 0;
}
