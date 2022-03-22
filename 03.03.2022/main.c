#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <conio.h>

int N = 5;
int adet = 0;
uint16_t* D;

void dosya_oku(void){
    FILE* fp;
    int D_uz,i;
    fp = fopen("dosya_ismi","rb");
    if(fp == NULL) printf("Dosya Acilamadi");
    else {
        fseek(fp,0L,SEEK_END);
        D_uz = ftell(fp);
        adet = D_uz / (sizeof(uint16_t));
        N = adet*2;
        printf("%d adet kayit var\n",adet);
        D = (uint16_t*)calloc(N,sizeof(uint16_t));
        for(i=0;i<adet;i++) {
            fscanf(fp,"%d",&D[i]);
        }
        fclose(fp);
    }
}
void ekle(void) {

}
void menu(void){
    char secim;
    system("cls");
    printf("[Dizi] MENU\n");
    printf("\t0-Dosyadan oku\n");
    printf("\t1-Kayit Ekle\n");
    printf("\t2-Kayit Ara\n");
    printf("\t3-Kayit Listele\n");
    printf("\t4-Kayit Güncelle\n");
    printf("\t5-Kayit Fizikel Sil\n");
    printf("\t6-Kayit Mantıkssal Sil\n");
    printf("\t7-Kaydet VE Cik\n");
    printf("Secim (0/1/2/3/4/5/6/7): ");
    do{
        secim = _getch();
    } while(!(secim > 47 && secim < 56));
    printf("\n");
    switch (secim) {
        case 48: dosya_oku(); break;
        case 49: ekle(); break;
        case 50: ara(); break;
        case 51: liste(); break;
        case 52: guncelle(); break;
        case 53: sil_f(); break;
        case 54: sil_m(); break;
        case 55: dosya_yaz();
            printf("\nIyi Gunler\n");
            exit(-1);
            break;

    }
}

int main() {
    uint16_t* D = (uint16_t*) calloc(N,sizeof(uint16_t));
    do {
        menu();
    } while(1);
    return 0;
}
