#include <stdio.h>
#include <string.h>

int FindMax(int a, int b);
int FindMin(int a, int b);
int FindAimedNum(int a, int b, int (*f)(int x, int y));

int main(){
    int a, b;
    int result = 0;
    char request[5];
    scanf("%d%d", &a, &b);
    scanf("%s", request);
    if(!strcmp(request, "Max")){
        result = FindAimedNum(a, b, FindMax);
    }else if(!strcmp(request, "Min")){
        result = FindAimedNum(a, b, FindMin);
    }else{
        result = -1;
    }
    if(result == -1){
        printf("Request is not valid!");
    }else{
        printf("%s is %d", request, result);
    }
    return 0;
}

int FindMax(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int FindMin(int a,int b){
    if(a > b){
        return b;
    }else{
        return a;
    }
}

int FindAimedNum(int a, int b, int (*f)(int x, int y)){
    return f(a, b);
}