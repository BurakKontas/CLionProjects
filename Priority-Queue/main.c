#include <stdio.h>
#include <stdlib.h>

//some type of const usage
#define MAXP 7//max priority
#define MAXM 12//menu max

//Priority queue data structure with linked lists
//every priority level has their own queue
//when showing we should keep max priority level
//showing function works like:
//  start from the highest priority's list and print them in order
//  if the highest priority level queue is empty increase "int highest_level" variable (--highest_level)
//TODO: functions: push,pop,show,edit(edits data's priority level)
//Bank queue machine simulator

//LList = Linked List

struct UserData{
    unsigned char priority;//smaller than integer
    int no;
    /*
    char name[20];
    char surname[20];
    char address[50];
    */
};

typedef struct UserData UData;

struct LinkedList{
    struct LinkedList* next;//its oneway linkedlist bcuz we are making a queue
    UData data;
};

typedef struct LinkedList LList;

LList* memory(){
    return (LList*)malloc(sizeof(LList));
}

LList* firstQueues[MAXP];//beginnings
LList* lastQueues[MAXP];//endings

void push() {
    LList* tempNode = memory();
    UData tempData;
    while(1) {
        printf("\bPriority: ");
        scanf("%d", &tempData.priority);
        fflush(stdin);
        if(tempData.priority > MAXP || tempData.priority < 1) {
            printf("\bLimit for priority is between 1-%d\n",MAXP);
            continue;
        }
        break;
    }
    printf("\bNo: ");
    scanf("%d",tempData.no);
    int prio = tempData.priority;
    if(firstQueues[prio]->next == NULL) {
        firstQueues[prio]->next = tempNode;
        firstQueues[prio]->data = tempData;
        tempNode->next = NULL;
        lastQueues[prio] = tempNode;
    } else {
        lastQueues[prio]->next = tempNode;
        lastQueues[prio]->data = tempData;
    }
}

void pop() {

}

void insert() {

}

void show() {

}

void begin(){//I could write it in main but nvm this way looks more prettier
    for(int i = 0;i<MAXP;++i) {
        firstQueues[i] = memory();
        firstQueues[i]->next = NULL;
    }
}

int menu(){
    const char MENU[][MAXM] = {"--MENU--","Add(Push)","Remove(Pop)","Insert","Show","Quit"};//unchangeable
    for (int i = 0; i < sizeof(MENU) / MAXM; ++i) {
        if (i == 0) printf("\b%s\n", MENU[i]);
        else printf("%d-) %s\n", i, MENU[i]);
    }
    return (sizeof(MENU)/MAXM-1);
}

int selection(int limit){//with this way i can use selection more than one
    int selected;
    while(1) {
        printf("Selection: ");
        scanf("%d", &selected);
        fflush(stdin);
        if(selected > limit || selected < 1) {
            printf("\bLimit is between 1-%d\n",limit);
            continue;
        }
        break;
    }
    return selected;
}

int main() {
    //I'll store all queue starting addresses in this array
    begin();
    while(1) {
        int menuSize = menu();
        int selected = selection(menuSize);
        if(selected == 1){
            push();
            printf("Test");
        }
        else if(selected == 2){
            pop();
        }
        else if(selected == 3){
            insert();
        }
        else if(selected == 4){
            show();
        }
        else if(selected == 5){
            printf("\bUser Quited");
            break;
        }
    }
    return 0;
}
