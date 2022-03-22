#include <stdio.h>
#define N 8 //array list is easily changeable

int main() {
    int max[3] = {0,0,0};//profit daynum1 daynum2
    int array[N] = {1,3,17,15,13,2,18,11};
    for(int i = 0;i<N;i++) {
        for(int j =N-1/*N = 8 loop have to start from 7th index */;j>i;j--) {
            if(array[j] > array[i] && max[0] < array[j]-array[i]) {
                max[0] = array[j] - array[i];
                max[1] = i+1;//array starts from 0 that means 5th day will printed like 4th
                max[2] = j+1;
            }
        }
    }
    for(int i = 0;i<3;i++) printf("%d ",max[i]);
    return 0;
}
