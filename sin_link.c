#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    int value;
    struct node *link;
}nd;

nd *head;

nd *createNode(int value){
    nd *ptr = (nd*)malloc(sizeof(nd));
    
    ptr->data = value;
    
    ptr->link = NULL;

    return ptr;
}

void display(){
    nd *temp = head;
    if(temp == NULL){
        printf(" Empty\n");
    }else{
        printf("\nStart->");
        while(temp!=NULL){
            printf("%d->", temp->data);
            temp = temp->link;
        }
        printf("End\n\n");
    }
}

void beginsert(){
    int element;
    printf("Enter the value: ");
    scanf("%d", &element);

    nd* newnode = createNode(element);

    newnode->link = head;
    head = newnode;
    printf("Element inserted successfully\n\n");
}

void lastInsert(){
    int element;
    printf("Enter the value: ");
    scanf("%d", &element);

    nd* newnode = createNode(element);

    nd *temp = head;
    while(temp->link!=NULL){
        temp=temp->link;
    }

    temp->link = newnode;
    newnode->link = NULL;
    printf("Element inserted successfully\n\n");
}

void anyinsert(){
    int pos=0, element, i, counter=1;
    printf("Enter the position to insert = ");
    scanf("%d", &pos);

    nd *temp;
    temp = head;
    while(temp->link != NULL){
       counter = counter + 1;
       temp = temp->link;
    }

    temp = head;
    if(pos > counter || pos <= 0){
        printf("Sorry, position is not valid!\n");
    } else {
        printf("Enter the value: ");
        scanf("%d", &element);
        nd *newNode = createNode(element);

        temp = head;
        for(i = 0; i < pos - 2; i++){
            temp = temp->link;
        }

        newNode->link = temp->link;
        temp->link = newNode;  
        printf("Element inserted successfully\n\n");
    }
}


void begdelete(){
    int element;
    nd *temp;

    if(head == NULL){
        printf("Empty\n");
    } else {
        element = head->data;
        temp = head;
        head = head->link;

        free(temp);
        printf("Element deleted {%d} successfully\n\n", element);
    }
}

void lastdelete(){
    int element, i, counter = 1;
    nd *temp, *prev;
    temp = head;

    if(head == NULL){
        printf("Empty\n");
    } else {
        while(temp->link != NULL){
            counter++;
            temp = temp->link;
        }

        if(counter == 1){
            begdelete();
            return;
        }

        temp = head;
        for(i = 0; i < counter - 2; i++){ 
            temp = temp->link;
        }

        prev = temp->link;
        element = prev->data;
        temp->link = NULL;

        free(prev);
        printf("Element deleted {%d} successfully\n\n", element);
    }
}

void anydelete(){
    int i, pos = 0, counter = 1;
    nd* temp = head;

    printf("Enter the position to delete = ");
    scanf("%d", &pos);

    while(temp->link != NULL){
        counter++;
        temp = temp->link;
    }

    temp = head;
    if(pos > counter || pos <= 0){
        printf("Sorry, position is not valid!\n");
    } else {
        if(pos == 1){
            begdelete();
        } else {
            for(i = 0; i < pos - 2; i++){ 
                temp = temp->link;
            }
            
            nd* ptr = temp->link;        
            temp->link = ptr->link;   

            free(ptr);                  
            printf("Element deleted successfully\n\n");
        }
    }
}

void alldelete(){
    nd *temp = head;
    while(head != NULL){
        lastdelete();
    }
    printf("All Element deleted successfully\n\n");
    printf("\tNow run \033[0;32mrm -rf\033[0m on sys32 dirctory\n\n");
}


//menu driven code
int main(){

    // beginsert();
    // beginsert();
    beginsert();
    lastInsert();

    // lastInsert();
    // lastInsert();
    // // beginsert();
    // anyinsert();
    // anyinsert();
    // lastdelete();
    // anydelete();
    alldelete();

    display();



    return 0;
}
















// void begdelete(){
//     int element;
//     nd *temp;

//     if(head == NULL){
//         printf("Empty\n");
//     } else {
//         element = head->data;
//         temp = head;
//         head = head->link;

//         free(temp);
//         printf("Element deleted {%d} successfully\n\n", element);
//     }
// }










// void lastdelete(){
//     int element, i, counter = 1;
//     nd *temp, *prev;
//     temp = head;

//     if(head == NULL){
//         printf("Empty\n");
//     } else {
//         while(temp->link != NULL){
//             counter++;
//             temp = temp->link;
//         }

//         if(counter == 1){
//             begdelete();
//             return;
//         }

//         temp = head;
//         for(i = 0; i < counter - 2; i++){ 
//             temp = temp->link;
//         }

//         prev = temp->link;
//         element = prev->data;
//         temp->link = NULL;

//         free(prev);
//         printf("Element deleted {%d} successfully\n\n", element);
//     }
// }







// void anydelete(){
//     int i, pos = 0, counter = 1;
//     nd* temp = head;

//     printf("Enter the position to delete = ");
//     scanf("%d", &pos);

//     while(temp->link != NULL){
//         counter++;
//         temp = temp->link;
//     }

//     temp = head;
//     if(pos > counter || pos <= 0){
//         printf("Sorry, position is not valid!\n");
//     } else {
//         if(pos == 1){
//             begdelete();
//         } else {
//             for(i = 0; i < pos - 2; i++){ 
//                 temp = temp->link;
//             }
            
//             nd* ptr = temp->link;        
//             temp->link = ptr->link;   

//             free(ptr);                  
//             printf("Element deleted successfully\n\n");
//         }
//     }
// }









// void alldelete(){
//     nd *temp = head;
//     while(head != NULL){
//         lastdelete();
//     }
//     printf("All Element deleted successfully\n\n");
//     printf("\tNow run \033[0;32mrm -rf\033[0m on sys32 dirctory\n\n");
// }
