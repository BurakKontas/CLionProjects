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

int maxIndex = 0;

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

int indexControl(int index){
    if(index > maxIndex) {
        printf("Out of Range\n");
        return -1;
    }
}

node* find(int index){
    if(indexControl(index) == -1) return NULL;//maxIndex control
    --index;
    node* nod = first;
    if(index == 1) return first;
    for (int i = 0; i < index - 1; i++) {//we want previous
        nod = nod->next;
    }
    return nod;
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
    maxIndex++;
}

void removeNode(int index) {
    if(indexControl(index) == -1) return;
    --index;//indexing starts from 1
    node *temp = find(index);
    if(temp == first){
        first->next->prev = NULL;
        temp = first;
        first = first->next;
    } else {
        temp->next = temp->next->next;
        temp->next->next->prev = temp;
    }
    free(temp);
    maxIndex--;
}

void insertNode(dat data,int index) {
    if(indexControl(index) == -1) return;
    node* temp = find(index);
    maxIndex++;
}

void showNode(){
    node* temp = first;
    int i=0;
    while(temp->next != NULL) {
        printf("--------------------\n");
        printf("%d-)\nNo: %d\nName: %s\nSurname: %s\nAddress: %s\n",++i,temp->data.no,temp->data.name,temp->data.surname,temp->data.address);
        temp = temp->next;
    }
}

void sortedView(int mode){

}

int main() {
    first = create(first);
    last = create(last);//might be unnecessary but doesnt have any loss
    char menu[][Num] = {"--MENU--","Add(Push)","Remove(Pop)","Insert","Show","Sorted View","Quit"};
    while(1){
        for(int i = 0;i<sizeof(menu)/Num;i++) {
            if(i == 0) printf("%7s\n",menu[i]);
            else printf("%d-) %s\n",i,menu[i]);
        }
        int selection;
        printf("Enter a Number: ");
        scanf("%d",&selection);
        if(selection == 1) {
            dat data;
            printf("No: ");
            scanf("%s",&data.no);
            fflush(stdin);
            printf("Name: ");
            gets(data.name);
            printf("Surname: ");
            gets(data.surname);
            printf("Address: ");
            gets(data.address);
            addNode(data);
        } else if(selection == 2) {
            int value;
            showNode();
            printf("Which Index Do You Want To Remove: ");
            scanf("%d",&value);
            removeNode(value);
        } else if(selection == 3) {
            //insertNode();
        } else if(selection == 4) {
            showNode();
        } else if(selection == 5) {
            //sortedView();//bubble sort
        } else if(selection == 6) {
            printf("User Quited");
            break;
        }
    }
    return 0;
}
