#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//data structures are a way of storing and organazing data 
//so that the data can be used efficiently

//List as abstract data type
/*
-store a given num of elem of a given type
-write-modify element at a position
-read element at a position

?are we talking about arrays?

let's define our list better:
-empty list has size 0
-insert
-remove
-count
-read/modify element at a position
-specify data type

with arrays, we'd need to shift elements whenever we remove or insert at an index.
time consuming
we'd also need to allocate a really large mem block so that we don't run out of mem
//and if we do run out, we'd need to copy the whole array into a bigger mem block etc etc
 access would be O(1)
 insert would be O(n)
 remove woule be O(n)
 add would be O(n) if array happens to be full (O(n) because of copying into bigger mem block)


*/

struct Node { 
    int data; 
    struct Node* next; 
}; 

struct Node* create(){

    struct Node* head = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 0;
    head->next = NULL;

    return head;

}

void append(struct Node* head, struct Node* newNode){
    
    while(head->next != NULL) head = head->next;
    
    head->next = newNode;
     
}
/*
null <- cur    next -> nextnext
null <- cur <- next <- nextnext
*/
struct Node* reverse(struct Node* head){

    struct Node* cur = head;
    struct Node* prev = NULL;
    struct Node* next;

    while(next != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

void print(struct Node* head){
    
    while(head != NULL){
        printf("data: %d\n", head->data);
        head = head->next;
    }
}

void delete(struct Node* head){
    struct Node* tmp;
    int count = 0;
    while(head != NULL){
        tmp = head;
        head = head->next;
        free(tmp);

        count++;
    }
    printf("%d\n", count);
}

int main(){

    struct Node *head = create();

    for(int i = 1; i < 11; i++){

        struct Node *newNode = NULL;
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i*5;
        newNode->next = NULL;

        append(head, newNode);
    }

    print(head);
    head = reverse(head);
    print(head);

    delete(head);

    
    
    

}
