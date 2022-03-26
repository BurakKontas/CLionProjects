#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* next;
    struct Node* prev;
    int value;
};

typedef struct Node node;

int maxIndex;
node* first;
node* last;

node* memory(){
    return (node*)malloc(sizeof(node));
}

void baslangic(){
    first = memory();
    first->next = NULL;
    first->prev = NULL;
}

void ekle(int value){
    node* temp = memory();
    temp->next = NULL;
    if(first->next == NULL) {
        first->next = temp;
        first->value = value;
        temp->prev = first;
    } else {
        last->next = temp;
        last->value = value;
        temp->prev = last;
    }
    last = temp;
    maxIndex++;
}

void goster(int mod){
    if(mod) {
        node* temp = first;
        while (temp->next != NULL) {
            printf("%d\n", temp->value);
            temp = temp->next;
        }
    } else {
        node* temp = last->prev;
        do {
            printf("%d\n",temp->value);
            temp = temp->prev;
        }
        while(temp->prev != NULL || temp == first);
    }
}

void cikar(int indis){
    if(indis > maxIndex || indis < 0) {
        printf("Out of range\n");
        return;
    }
    node* temp = first;
    node* temp2;
    for(int i = 0;i<indis-1;i++) {
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    maxIndex--;
}

int main(){
    baslangic();
    ekle(10);//0
    ekle(20);//1
    ekle(30);//2
    ekle(40);//3
    goster(1);
    printf("************\n");
    goster(0);
    return 0;
}