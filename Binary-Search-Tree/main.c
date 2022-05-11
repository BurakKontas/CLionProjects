#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * TODO:
 *  Binary search tree kullanarak
 *  Dosyadaki metinde verilen kelimelerin kaç kere geçtiğini (frekans) buluyoruz
 *  Bulunan sonuç yine farklı bir dosyaya kaydedilecek
 */

struct Node {
    char word[100];
    int freq;
    struct Node* left;
    struct Node* right;
};

void ara_ekle(struct Node** root,int sadece_ara,const char* word) {
    if(*root == NULL) {
        if(sadece_ara == 1){
            printf("%s Bulunamadi\n",word);
        } else {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            strcpy(newNode->word,word);
            newNode->freq = 1;
            newNode->right = NULL;
            newNode->left = NULL;
            *root = newNode;
        }
    } else if(strcmp(word,(*root)->word) < 0) {
        ara_ekle(&(*root)->left,sadece_ara,word);
    } else if(strcmp(word,(*root)->word) > 0) {
        ara_ekle(&(*root)->right,sadece_ara,word);
    } else {
        if(sadece_ara == 1) {
            printf("%s bulundu, frekansi %d\n",word,(*root)->freq);
        } else {
            (*root)->freq++;
        }
    }
}

void printTree(struct Node* root,FILE* f) {
    if(root == NULL) {
        return;
    }
    printf("%s %d\n",root->word,root->freq);
    if(f != NULL) {
        //dosyaya yaz
        fprintf(f,"%s %d\n",root->word,root->freq);
    } else {
        //ekrana yaz
        printf("%s %d\n",root->word,root->freq);
    }
    printTree(root->left,f);
    printTree(root->right,f);
}

int main() {
    struct Node* rootilk = NULL;
    char kelime[100];
    FILE* fp;
    fp = fopen("C:/Users/konta/CLionProjects/Binary-Search-Tree/file.txt","r");
    while(!(feof(fp))) {
        fscanf(fp,"%s",kelime);
        printf("%s kelimesi okundu\n",kelime);
        ara_ekle(&rootilk,0,kelime);
    }
    fclose(fp);
    printf("\nAgac yazdiriliyor\n");
    printTree(rootilk,NULL);
    printf("\nArama Yapiliyor\n");
    const char* aranacak = "Lorem";
    ara_ekle(&rootilk,1,aranacak);
    printf("\nFrekanslar dosyaya yazdiriliyor\n");
    FILE* fpw;
    fpw = fopen("frekans.txt","wb");
    printTree(rootilk,fpw);
    return 0;
}
