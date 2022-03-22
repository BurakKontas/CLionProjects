#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int ust;
    unsigned kapasite;
    int* dizi;
};

struct Stack* stackOlustur(unsigned kapasite) {
    struct Stack* stack =(struct Stack*)malloc(sizeof(struct Stack));
    stack->kapasite = kapasite;
    stack->ust = -1;
    stack->dizi=(int*) calloc(kapasite,sizeof(int));
    return stack;
}

void push(struct Stack* stack,int eleman){
    if(stack->ust == stack->kapasite-1) {
        printf("Dizi Dolu\n");
        return;
    }
    stack->dizi[++stack->ust]=eleman;
    printf("%d Stack'e eklendi\n",eleman);
}

int pop(struct Stack* stack){
    if(stack->ust == -1) {
        printf("Dizi Bos\n");
        return -1;
    }
    int temp = stack->dizi[stack->ust];
    stack->dizi[stack->ust] = '\0';
    stack->ust--;
    //return stack->dizi[stack->ust--] de olabilir elemanı \0 yapmayız çöp veri olur ve push edilirken çöp verinin üstüne yazılır
    return temp;
}

void listele(struct Stack* stack){
    if(stack->ust == -1) {
        printf("Dizi Bos\n");
        return;
    }
    for (int i = stack->ust; i >= 0; --i) {
        printf("%d %3d\n",i,stack->dizi[i]);
    }
}

int main() {
    struct Stack* stack = stackOlustur(4);
    int n = 0;
    listele(stack);
    push(stack,n+=10);
    listele(stack);
    push(stack,n+=10);
    listele(stack);
    push(stack,n+=10);
    listele(stack);
    push(stack,n+=10);
    listele(stack);
    push(stack,n+=10);
    printf("%d Pop Edildi\n",pop(stack));
    listele(stack);
    printf("%d Pop Edildi\n",pop(stack));
    listele(stack);
    printf("%d Pop Edildi\n",pop(stack));
    listele(stack);
    printf("%d Pop Edildi\n",pop(stack));
    listele(stack);
    pop(stack);
    return 0;
}
