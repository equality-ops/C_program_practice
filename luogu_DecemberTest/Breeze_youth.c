#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct input{
    int r; // 排名
    int q; // 强馆总数
    int n; // 最多参赛人数
    int m; // 国赛名额
    char result[5];
};

int main(){
    int T = 0; // 数据组数
    int i = 0;
    scanf("%d", &T);
    struct input* message = NULL;
    message = (struct input*)calloc(T, sizeof(struct input));
    if(message == NULL){
        printf("No enough memory to allocate!");
        exit(0);
    }
    for(i = 0;i < T;i++){
        scanf("%d%d%d%d", &message[i].r, &message[i].q, &message[i].n, &message[i].m);
        if(message[i].n > (message[i].m / 3)){
            if(((message[i].n - message[i].m / 3) * message[i].q + message[i].m) >= message[i].r){
                strcpy(message[i].result, "Yes");
            }else{
                strcpy(message[i].result, "No");
            }
        }else{
            if(message[i].m >= message[i].r){
                strcpy(message[i].result, "Yes");
            }else{
                strcpy(message[i].result, "No");
            }
        }
    }
    for(i = 0;i < T;i++){
        printf("%s\n", message[i].result);
    }
    free(message);
    return 0;
}