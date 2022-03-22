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

dat dataCreator(){
    dat data;
    printf("No: ");
    scanf("%d",&data.no);
    fflush(stdin);
    printf("Name: ");
    gets(data.name);
    printf("Surname: ");
    gets(data.surname);
    printf("Address: ");
    gets(data.address);
    return data;
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
    node* main = memory();
    main->data = data;
    if(index == 1) {
        first->prev = main;
        main->next = first;
        main->prev = NULL;
        first = main;
    } else {
        node *temp = find(index);
        main->next = temp->next;
        temp->next->prev = main;
        temp->next = main;
        main->prev = temp;
    }
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
    node* one = first;
    node* two = first->next;
    node* temp = memory();
    if(mode == 1) {//no
        while(two->next != NULL) {
            if (one->data.no > two->data.no) {
                temp->data = one->data;
                one->data = two->data;
                two->data = temp->data;
                one = one->next;
                two = two->next;
                //or you can exchange next and prev's to change datas
            }
        }
    } else if(mode == 2) {//name

    } else if(mode == 3) {//surname

    } else if(mode == 4) {//address

    } else {
        printf("Wrong Mode Number\n");
    }
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
            dat data = dataCreator();
            addNode(data);
        } else if(selection == 2) {
            int value;
            showNode();
            printf("Which Index Do You Want To Remove: ");
            scanf("%d",&value);
            removeNode(value);
        } else if(selection == 3) {
            int index;
            showNode();
            printf("Enter the index after the place you want to add: ");
            scanf("%d",&index);
            dat data = dataCreator();
            insertNode(data,index);
        } else if(selection == 4) {
            showNode();
        } else if(selection == 5) {
            int mode;
            printf("1-) No (Number)\n");
            printf("2-) Name (Lenght)\n");
            printf("3-) Surname (Lenght)\n");
            printf("4-) Address (Lenght)\n");
            printf("Which Mode Do You Want: ");
            scanf("%d",&mode);
            sortedView(mode);//bubble sort
        } else if(selection == 6) {
            printf("User Quited");
            break;
        }
    }
    return 0;
}
