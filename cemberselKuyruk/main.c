#include <stdio.h>
#include <stdlib.h>
#define K 10

struct Kuyruk{
    int queue[K];
    int on,arka;
};

struct Kuyruk kuyruk;

void push(int deger){
    if(kuyruk.on == kuyruk.arka+1){
        printf("Kuyruk Dolu\n");
        return;
    }
    kuyruk.queue[kuyruk.arka] = deger;
    kuyruk.arka++;
    if(kuyruk.arka == K) kuyruk.arka = 0;

}

int pop(){
    if(kuyruk.on == kuyruk.arka){
        printf("Kuyruk Bos\n");
        return INT_MAX;
    }
    int temp = kuyruk.queue[kuyruk.on];
    kuyruk.on++;
    if(kuyruk.on == K) kuyruk.on = 0;
    return temp;
}

void show(){
    if(kuyruk.on == kuyruk.arka){
        printf("Kuyruk Bos\n");
        return;
    }
    int i = kuyruk.on;
    while(1){
        if(i==kuyruk.arka) break;
        printf("%d-) %d\n",i,kuyruk.queue[i]);
        i++;
        if(i == K) i = 0;
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
    push(++a);
    push(++a);
    show();
    printf("%d popped\n", pop());
    printf("%d popped\n", pop());
    printf("%d popped\n", pop());
    show();
    printf("****************\n");
    push(++a);
    push(++a);
    push(++a);
    push(++a);
    push(++a);
    push(++a);
    show();
    printf("%d popped\n", pop());
    printf("%d popped\n", pop());
    printf("%d popped\n", pop());
    printf("%d popped\n", pop());
    printf("%d popped\n", pop());
    printf("%d popped\n", pop());
    printf("%d popped\n", pop());
    printf("%d popped\n", pop());
    printf("%d popped\n", pop());
    printf("%d popped\n", pop());
    printf("%d popped\n", pop());
    printf("******************\n");
    show();
    return 0;
}
