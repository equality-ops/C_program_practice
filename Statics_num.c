#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define N 50

int DigitBit(char str[]);
void DigitCount(char a[]);

int main() {
    char str[N];
    int sum = 0;
    printf("Input a number:");
    scanf("%s", str);
    sum = DigitBit(str);
    printf("%d bits\n", sum);
    DigitCount(str);
    return 0;
}

int DigitBit(char str[]) {
    char* p = NULL;
    int sum = 0;
    for (p = str; *p; p++) {
        if (*p >= '0' && *p <= '9') {
            sum++;
        }
    }
    return sum;
}

void DigitCount(char a[]) {
    int digit[10] = { 0 };
    char* p = a;
    int i = 0;
    int index = 0;
    for (i = 0; p[i] != '\0'; i++) {
        if (p[i] >= '0' && p[i] <= '9') {
            index = p[i] - '0';
            digit[index]++;
        }
    }
    for (i = 0; i < 10; i++) {
        printf("%d: %d\n", i, digit[i]);
    }
}