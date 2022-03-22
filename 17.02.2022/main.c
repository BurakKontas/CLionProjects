#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*
int a[10] = {10,20,30,40,50,60,70,80,90,100};
int b;

int main(void) {
    int* p = a;
    printf("%d %d %d %d\n",&a[0],p,p+3,&a[3]);
    (a[3] == *(p+3)) ? printf("Evet\n") : printf("Hayır\n");//if else shortcut
    return 0;
}
*/
/*
int N;
int main() {
    int* a;
    printf("Kac Ogeli: ");
    scanf("%d",&N);
    a = (int*)malloc(N*sizeof(int));
    int* p=a;
    for (int i = 0;i<N;++i) printf("%d %d %d %d\n",&a[i],p,a[i],*p++);
    free(a);
}
*/
#define m 4
#define n 3

int a[n][m] = {{1,2,3,4},{10,20,30,40},{100,200,300,400}};
int main() {
    int* p;
    p = &a[0][0] + m * 1/*1 kısmı kaçıncı dizi olduğunu belirtmek için değiştirilebilir*/ + 2;
    printf("%d    %d\n",a[1][2],*p);
    return 0;
}