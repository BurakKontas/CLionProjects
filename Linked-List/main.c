#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Num 12


struct Data{
    char name[20];
    char surname[20];
    int no;
    char address[50];
};

typedef struct Data dat;

struct Node{
    struct Node* next;
    struct Node* prev;
    dat data;
};

typedef struct Node node;

node* first;
node* last;

node* memory(){
    return (node*)malloc(sizeof(node));
}

node* create(node* N){
    N = memory();
    N->next = NULL;
    N->prev = NULL;
    return N;
}

void addNode(dat data){
    node* N = memory();
    node* temp;
    temp = (first->next == NULL) ? first : last;
    temp->next = N;
    temp->data = data;
    temp->prev = (temp == first) ? NULL : temp;
    N->next = NULL;
    N->prev = temp;
    last = N;
}

void removeNode(int index) {

}

void insertNode(dat data,int index) {

}

void showNode(){

}

int main() {
    first = create(first);
    last = create(last);//might be unnecessary but doesnt have any loss
    char menu[][Num] = {"--MENU--","Add(Push)","Remove(Pop)","Insert","Show","Quit"};
    while(1){
        for(int i = 0;i<sizeof(menu)/Num;i++) {
            if(i == 0) printf("%7s\n",menu[i]);
            else printf("%d-) %s\n",i,menu[i]);
        }
        int selection;
        printf("Enter a Number: ");
        scanf("%d",&selection);
        if(selection == 1) {
            printf("Name: ");
            gets();
        } else if(selection == 2) {
            removeNode();
        } else if(selection == 3) {
            insertNode();
        } else if(selection == 4) {
            showNode();
        } else if(selection == 5) {
            printf("User Quited");
            break;
        }
    }
    return 0;
}
