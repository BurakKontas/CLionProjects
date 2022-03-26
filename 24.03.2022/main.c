#include <stdio.h>
#include <stdlib.h>

struct Kuyruk{
    int on,arka,boyut;
    unsigned kapasite;
    int* dizi;
};

typedef struct Kuyruk q;

q* kuyrukOlustur(unsigned);
int doluMu(q*);
void enqueue(q*,int);
int dequeue(q*);

int main() {
    //TODO:
    // enqueue dequeue etc.
    return 0;
}

int doluMu(q* kuyruk){
    return (kuyruk->boyut == kuyruk->kapasite);
}

q* kuyrukOlustur(unsigned kapasite){
    q* kuyruk = (q*)malloc(sizeof(q));
    kuyruk->kapasite = kapasite;
    kuyruk->on = kuyruk->boyut = 0;
    kuyruk->arka = kapasite-1;
    kuyruk->dizi = (int*) calloc(kuyruk->kapasite,sizeof(int));
    return kuyruk;
}

void enqueue(q* kuyruk,int eleman) {
    if(doluMu(kuyruk)) {
        printf("Kuyruk Dolu\n");
        return;
    }
    kuyruk->arka = (kuyruk->arka +1) % kuyruk->kapasite;
    kuyruk->dizi[kuyruk->arka] = eleman;
    kuyruk->boyut++;
    printf("---> %d kuyruga eklendi\n",eleman);
}

int dequeue(q* kuyruk){
    if(!doluMu(kuyruk)) {
        printf("Kuyruk Bos\n");
        return INT_MIN;
    }
    int item = kuyruk->dizi[kuyruk->on];
    kuyruk->dizi[kuyruk->on]=0;
    kuyruk->boyut--;
    printf("<--- %d kuyruktan cikarildi",item);
    return item;
}