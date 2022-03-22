#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct dugum {
    int ogrencino;
    char isim[20];
    struct dugum* sonraki;
};
struct dugum* baslangic = NULL;
struct dugum* ilk = NULL;
//Dugumun baslangıc degeri NULL olsun.

//void listele() fonksiyonu tanımlayın. Pointer NULL
//olana kadar bağlı listede dolaşıp öğrenci no ve ismini yazdırın.

//void basekle(ogrno,ad) fonksiyonu tanımlayın.
//fonksiyon ad ve ogrencino degiskenleri alıp en başa yeni bir düğüm eklesin

struct dugum* ara(int no){
    struct dugum* p = ilk;
    while(p != NULL) {
        if(p->ogrencino == no) {
            printf("%d - %d", p->ogrencino,no);
            break;
        }
        p = p->sonraki;
    }
    return p;
}

void listele() {
    struct dugum* p = baslangic;
    while(p!=NULL){
        printf("%d - %s\n",p->ogrencino,p->isim);
        p = p->sonraki;
    }
}

void basekle(int no, const char ad[]){
    struct dugum* yeni = (struct dugum*) malloc(sizeof(struct dugum));
    int control = 0;
    if(baslangic == NULL) control = 1;
    yeni->ogrencino=no;
    strcpy(yeni->isim,ad);
    yeni->sonraki=baslangic;
    baslangic=yeni;
    if(control == 1) ilk = baslangic;
}

int main() {
    basekle(1,"Arda");
    basekle(2,"Burak");
    basekle(3,"Kontas");
    listele();
    printf("%d - %s", ilk->ogrencino,ilk->isim);
    struct dugum* D = ara(2);
    printf("\n%d- %s", D->ogrencino,D->isim);
    return 0;
}
