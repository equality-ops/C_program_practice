#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node* next;
};

int main(){
    struct node* p = NULL;
    struct node* pr = NULL;
    struct node* head = NULL;
    char ch;
    while((ch = getchar()) != '\n'){
        p = (struct node*)calloc(1, sizeof(struct node));
        if(p == NULL){
            printf("No enough memory to allocate!");
            exit(0);
        }
        if(head == NULL){
            head = p;
            p->data = ch;
            p->next = NULL;
        }else{
            p->data = ch;
            p->next = head;
            head = p;
        }
    }
    p = head;
    while(p != NULL){
        printf("%c", p->data);
        pr = p;
        p = p->next;
        free(pr);
    }
    return 0;
}