#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char mesaj[255];
    printf("Mesaji Giriniz (Max 255): ");
    gets(mesaj);
    int temp = -1;
    char alfabe[] = "ABCDEFGHIJKLMNOPRSTUVYZ ";
    printf("Mesaj: ");
    for(int i=0;i< strlen(mesaj);i++){
        if(i == 0 && temp == -1){
            temp = mesaj[i]-48;
            continue;
        } else if(i == 1 && temp == -1) {
            temp = mesaj[i]-48;
            continue;
        } else if(i == 2 && temp == -1) {
            temp = mesaj[i]-48;
            continue;
        } else {
            if(temp != -1) {
                printf("%c",alfabe[temp*10+i]);
            } else {
                printf("%c",alfabe[i]);
            }
        }
        temp = -1;
    }
    return 0;
}
