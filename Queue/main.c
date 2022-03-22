#include <stdio.h>
#include <stdlib.h>
#define N 10

//to making addable and removable queue list we will use linked lists
//one way link may be enough

struct Node{
    struct Node *next;
    int value;
};

typedef struct Node node;

node* first;
node* last;
int maxIndex = 0;

node* create() {
    node *queue = (node*)calloc(1,sizeof(node));
    queue->next = NULL;
    return queue;
}

node* find(int index) {
    index -= 1;//showqueue indexing from 1 but for starts from 0
    node* queue = first;
    if(index == 1) return first;
    for (int i = 0; i < index - 1; i++) {//we want previous
        queue = queue->next;
    }
    return queue;
}

node* addQueue() {
    int value;
    printf("Enter a number: ");
    scanf("%d",&value);
    node *queue = (node*)calloc(1,sizeof(node));
    queue->next = NULL;
    if(first->next == NULL) {
        first->next = queue;
        first->value = value;
        last = queue;
    } else {
        last->next = queue;
        last->value = value;
        last = queue;
    }
    maxIndex += 1;
}

void showQueue() {
    node* queue = first;
    int i = 0;
    while(queue->next != NULL) {
        if(i == 0) printf("-------------\n");
        printf("%d - %d\n",++i,queue->value);
        queue = queue->next;
    }
    if(i != 0) printf("-------------\n");
    if(i == 0) printf("Queue is Empty\n");
}

void removeQueue(int index){
    if(index > maxIndex) {
        printf("Wrong Index Number\n");
        printf("Which Index: ");
        int index2;
        scanf("%d",&index2);
        removeQueue(index2);
        return;
    }
    node* queue = first;
    if(index == 1) {
        node* temp;
        temp = first->next;
        free(first);
        first = temp;
        showQueue();
        return;
    }
    queue = find(index);
    node* temp;
    temp = queue->next->next;
    free(queue->next);
    queue->next = temp;
    showQueue();
    maxIndex -= 1;
}

void insert(){
    int index;
    showQueue();
    if(maxIndex == 0) {
        addQueue();//we doesnt need to do one more add first func
        return;
    }
    printf("Enter the index after the place you want to add: ");
    scanf("%d", &index);
    if(index > maxIndex) {
        printf("Wrong Index Number\n");
        insert();
        return;
    }
    node* queue = find(index);//returns us index-1
    printf("Enter a number: ");
    int value;
    scanf("%d",&value);
    node *insert = (node*)calloc(1,sizeof(node));
    insert ->value = value;
    insert->next = queue->next;
    queue->next = insert;
    maxIndex += 1;
}
void queueMovement(){
    int value;
    showQueue();
    printf("How Far Do You Want Queue Move: ");
    scanf("%d",&value);
    if(value > maxIndex) {
        printf("Out of Queue Range\n");
        queueMovement();
        return;
    }
    for(int i = 0;i < value;i++){
        removeQueue(1);
        maxIndex -= 1;
    }
}

int main() {
    first = create();
    last = create();
    while(1) {
        char list[][N] = {"--MENU--","Add","Remove","Show","Insert","Move","Quit"};
        for (int i = 0; i < sizeof(list)/N; ++i) {
            if(i == 0) printf("%10s\n",list[i]);
            else printf("%d-) %s\n",i,list[i]);
        }
        int selection;
        printf("Selection:");
        scanf("%d",&selection);
        if(selection == 1) {
            addQueue();
        } else if(selection == 2) {
            showQueue();
            if(maxIndex == 0) continue;//showQueue func printfs queue is empty
            printf("Which Index: ");
            int index;
            scanf("%d",&index);
            removeQueue(index);
        } else if(selection == 3) {
            showQueue();
        } else if(selection == 4) {
           insert();
        } else if(selection == 5) {
            queueMovement();
        } else if(selection == 6) {
            printf("User Exited");
            break;
        } else {
            continue; //not necessary
        }
    }
    return 0;
}
