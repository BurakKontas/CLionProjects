#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXP 7//max priority

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
    char priority;//smaller than integer
    int no;
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

void create(){

}

LList* memory(){
    return (LList*)malloc(sizeof(LList));
}

int main() {
    //I'll store all queue starting addresses in this array
    int *queues = (int*)malloc(MAXP*sizeof(int));

    return 0;
}
