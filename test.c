#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct STU{
    char name[9];
    int age;
};

int main(){
    int a = 0;
    switch (1){
        case 1:
            printf("1");
        default:
            printf("2");
        case 2:
            printf("3");
    }
    return 0;
}