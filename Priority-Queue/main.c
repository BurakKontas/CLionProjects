#include <stdio.h>
#include <stdlib.h>

//some type of const usage
#define MAXP 7//max priority
#define MAXM 12//menu max

//Priority queue data structure with linked lists
//every priority level has their own queue
//when showing we should keep max priority level
//showing function works like:
//  start from the highest priority's node and print them in order
//  if the highest priority level queue is empty increase "int highest_level" variable (--highest_level)
//TODO: functions: push,pop,show,edit(edits data's priority level)
//Bank queue machine simulator

//LList = Linked list

struct UserData{
    int priority;
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

int maxIndexes[MAXP];
LList* firstQueues[MAXP];//beginnings
LList* lastQueues[MAXP];//endings

int enterPrio(){
    int prio;
    while(1) {
        printf("\bPriority: ");
        scanf("%d", &prio);
        fflush(stdin);
        if(prio > MAXP || prio < 1) {
            printf("\bLimit for priority is between 1-%d\n",MAXP);
            continue;
        }
        break;
    }
    return prio;
}

int enterNo(){
    int no;
    printf("\bNo: ");
    scanf("%d",&no);
    return no;
}
//I seperated enterPriority and enterNo from push for insert. I'll use these functions again in insert
void push() {
    LList* tempNode = memory();
    UData tempData;
    tempData.priority = enterPrio();
    tempData.no = enterNo();
    int prio = tempData.priority-1;
    tempNode->next = NULL;
    if(firstQueues[prio]->next == NULL) {
        firstQueues[prio]->next = tempNode;
        firstQueues[prio]->data = tempData;
        lastQueues[prio] = tempNode;
    } else {
        lastQueues[prio]->next = tempNode;
        lastQueues[prio]->data = tempData;
        lastQueues[prio] = tempNode;
    }
    maxIndexes[prio]++;
}

LList* find(int prio,int index){
    LList* node = firstQueues[prio];
    if(index > maxIndexes[prio]) {
        printf("Out of range (MAX: %d)",maxIndexes[prio]);
        return NULL;
    }
    if(index == 1 || index == 2) return node;
    for(int i = 0;i<index-1;++i){//we want previous
        node = node->next;
    }
    return node;
}

void show(int prio) {
    LList* temp;
    temp = firstQueues[prio];
    int n = 0;
    if(temp->next != NULL) {
        printf("\b****************\n");
    }
    while(temp->next != NULL) {
        printf("\b%d-)------\n",++n);
        printf("Priority: %d\n",temp->data.priority);
        printf("No: %d\n",temp->data.no);
        temp = temp->next;
    }
}


void pop() {
    int n = 0, prio = enterPrio() - 1;
    if(maxIndexes[prio] == 0) {
        printf("\bYour queue is empty\n");
        return;
    }
    show(prio);
    printf("****************\n");
    int index;
    printf("\bWhich index you want to pop: ");
    scanf("%d", &index);
    LList *node = find(prio, index);//returns us index-1th node
    if (node == NULL) return;//find function returns null if index doesnt exists
    //algorithm = https://ibb.co/JzJsML7 (CTRL+RMB)
    if (index == 1) {//if first selected
        firstQueues[prio] = node->next;
        free(node);
    } else {
        LList* temp = node->next;
        node->next = node->next->next;
        free(temp);
    }
    maxIndexes[prio]--;
}

void insert() {
    int prio = enterPrio() -1;
    if(maxIndexes[prio] == 0) {
        printf("Your Queue is Empty Use Add(Push)");
        return;
    }
    show(prio);
    printf("Which index do you want to insert: ");
    int index;
    scanf("%d",&index);
    LList* node = find(prio,index);
    LList* temp = memory();
    if(node == NULL) return;//find function returns null if index doesnt exists
    UData data;
    data.priority = prio+1;
    data.no = enterNo();
    temp->data = data;
    if(index == 1) {
        temp->next = firstQueues[prio];
        firstQueues[prio] = temp;
    } else {
        temp->next = node->next;
        node->next = temp;
    }
    maxIndexes[prio]++;
}

void begin(){//I could write it in main but nvm this way looks more prettier
    for(int i = 0;i<MAXP;++i) {
        firstQueues[i] = memory();
        firstQueues[i]->next = NULL;
        maxIndexes[i] = 0;
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
        }
        else if(selected == 2){
            pop();
        }
        else if(selected == 3){
            insert();
        }
        else if(selected == 4){
            for(int i = MAXP-1;i>-1;--i){
                show(i);
            }
            printf("****************\n");
        }
        else if(selected == 5){
            printf("\bUser Quited");
            break;
        }
    }
    return 0;
}
