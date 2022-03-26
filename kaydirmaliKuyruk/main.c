#include <stdio.h>
#include <stdlib.h>
#define K 10


struct Kuyruk{
    int kuyruk[K];
    int on;
    int arka;
};

struct Kuyruk kuyruk;

void push(int deger){
    if(kuyruk.arka == K-1) {
        printf("Kuyruk Dolu\n");
        return;
    }
    kuyruk.kuyruk[kuyruk.arka] = deger;
    kuyruk.arka++;
}

int pop(int index){
    if(kuyruk.arka == 0){
        printf("Kuyruk Bos\n");
        return INT_MAX;
    }
    int temp = kuyruk.kuyruk[index];
    for (int i = index; i < kuyruk.arka; ++i) {
        kuyruk.kuyruk[i] = kuyruk.kuyruk[i+1];
    }
    kuyruk.arka--;
    return temp;
}

void show(){
    for (int i = 0; i < kuyruk.arka; ++i) {
        printf("%d-) %d\n",i,kuyruk.kuyruk[i]);
    }
}

int main() {
    int a = 0;
    push(++a);
    push(++a);
    push(++a);
    push(++a);
    push(++a);
    push(++a);
    show();
    printf("*************\n");
    printf("%d popped\n", pop(0));
    printf("%d popped\n", pop(0));
    printf("%d popped\n", pop(0));
    printf("*************\n");
    show();
    return 0;
}
