#include <stdio.h>
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
    unsigned int no;
    char name[20];
    char surname[20];
    char address[50];
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

void push() {

}

void pop() {

}

void insert() {

}

void show() {

}

int main() {
    //I'll store all queue starting addresses in this array
    LList* queues[MAXP] = {memory(),memory(),memory(),memory(),memory(),memory(),memory()};//starting addresses
    /*
     * LList* queues[MAXP];
     * for(int i = 0,i<MAXP,++i) {
     *      queues[i] = memory();
     * }
    */
    const char MENU[][MAXM] = {"--MENU--","Add(Push)","Remove(Pop)","Insert","Show","Quit"};//unchangeable
    while(1) {
        for (int i = 0; i < sizeof(MENU) / MAXM; ++i) {
            if (i == 0) printf("%s\n", MENU[i]);
            else printf("%d-) %s\n", i, MENU[i]);
        }
        printf("Selection: ");
        int selection;
        scanf("%d",&selection);
        fflush(stdin);
        if(selection == 1){
            push();
        }
        else if(selection == 2){
            pop();
        }
        else if(selection == 3){
            insert();
        }
        else if(selection == 4){
            show();
        }
        else if(selection == 5){
            printf("User Quited");
            break;
        }
    }
    return 0;
}
