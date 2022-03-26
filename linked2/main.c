#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* prev;
    int value;
};

typedef struct Node node;

node* top;

node* memory(){
    return (node*)malloc(sizeof(node));
}

void begin(){
    top = NULL;
}

void push(int value){
    node* new = memory();
    if(top == NULL){
        top = new;
        top->value = value;
        top->prev = NULL;
    } else {
        new->prev = top;
        new->value = value;
        top = new;
    }
}

void show(){
    node* temp = top;
    if(temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    char a = 0;
    while(1){
        printf("%d\n",temp->value);
        temp = temp->prev;
        if(a == 1) break;
        if(temp->prev == NULL) a++;
    }
}

int pop(){
    node* temp = top;
    if(temp == NULL) {
        printf("Stack is empty\n");
        return INT_MAX;
    }
    int value = temp->value;
    top = top->prev;
    free(temp);
    return value;
}

int main(){
    char a = 0;
    begin();
    push(++a);
    push(++a);
    push(++a);
    push(++a);
    push(++a);
    show();
    printf("****************\n");
    printf("%d popped\n",pop());
    printf("%d popped\n",pop());
    printf("%d popped\n",pop());
    printf("%d popped\n",pop());
    printf("%d popped\n",pop());
    printf("%d popped\n",pop());
    printf("****************\n");
    show();
    push(++a);
    push(++a);
    push(++a);
    push(++a);
    show();
    return 0;
}