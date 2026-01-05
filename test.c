#include <stdio.h>

int main(){
    int a[][2] = {{1, 2}, {3, 1}};
    int *p = a[0];
    for(int i;i < 4;i++){
        printf("%d ", *(p + i));
    }
    return 0;
}