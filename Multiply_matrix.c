#include<stdio.h>

#define M 3
#define N 4

void MultiplyMatrix(int a[M][N], int b[N][M], int c[M][M]);
void InputMatrixA(int a[M][N]);
void InputMatrixB(int b[N][M]);
void OutputMatrix(int a[M][M]);

int main(){
    int a[M][N], b[N][M], c[M][M];
    InputMatrixA(a);;
    InputMatrixB(b);
    MultiplyMatrix(a, b, c);
    OutputMatrix(c);
    return 0;
}

void MultiplyMatrix(int a[M][N], int b[N][M], int c[M][M]){
    for(int i = 0;i < M;i++){
        for(int j = 0;j < M;j++){
            c[i][j] = 0;
            for(int k = 0;k < N;k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void InputMatrixA(int a[M][N]){
    printf("Input 3*4 matrix a:\n");
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            printf("a[%d,%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void InputMatrixB(int b[N][M]){
    printf("Input 4*3 matrix b:\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("b[%d,%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
}

void OutputMatrix(int a[M][M]){
    printf("Results:\n");
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }
}