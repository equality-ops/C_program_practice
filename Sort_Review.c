#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 10

void InsertSort(int a[], int n);
void BubbleSort(int a[], int n);
void ChooseSort(int a[], int n);
void MergeSort(int a[], int temp[], int left, int mid, int right);
void Merge(int a[], int temp[], int left, int right);
int Partition(int a[], int low, int high);
void QuickSort(int a[], int low, int high);
int main(){
    int a[N];
    int temp[N]; // 用于归并排序的辅助存储空间
    srand(time(NULL)); // 设置随机数种子
    printf("Before sort: ");
    for(int i = 0;i < N;i++){
        a[i] = rand() % 10;
        printf("%d ", a[i]);
    }
    //InsertSort(a, N); // 插入排序
    //BubbleSort(a, N); // 冒泡排序
    //ChooseSort(a, N); // 选择排序
    //Merge(a, temp, 0, N - 1); // 归并排序
    QuickSort(a, 0, N - 1); // 快速排序
    printf("\nAfter sort: ");
    for(int i = 0;i < N;i++){
        printf("%d ", a[i]);
    }
    return 0;
}

void InsertSort(int a[], int n){
    int i = 0;
    int j = 0;
    int sign = 0;
    for(i = 1;i < n;i++){
        sign = a[i];
        for(j = i - 1;a[j] > sign && j >= 0;j--){
            a[j + 1] = a[j]; 
        }
        a[j + 1] = sign;
    }
}

void BubbleSort(int a[], int n){
    int i = 0;
    int j = 0;
    for(i = 0;i < n - 1;i++){
        int flag = 1;
        for(j = 1;j < n - i;j++){
            if(a[j] < a[j - 1]){
                flag = 0;
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
        if(flag){
            break;
        }
    }
}

void ChooseSort(int a[], int n){
    int i = 0;
    int j = 0;
    int k = 0;
    for(i = 0;i < n - 1;i++){
        k = i;
        for(j = i + 1;j < n;j++){
            if(a[k] > a[j]){
                k = j;
            }
        }
        if(k != i){
            int temp = a[k];
            a[k] = a[i];
            a[i] = temp;
        }
    }
}

void MergeSort(int a[], int temp[], int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left;
    while(i <= mid && j <= right){
        if(a[i] < a[j]){
            temp[k] = a[i++];
        }else{
            temp[k] = a[j++];
        }
        k++;
    }
    while(i <= mid){
        temp[k++] = a[i++]; 
    }
    while(j <= right){
        temp[k++] = a[j++];
    }

    for(i = left;i <= right;i++){
        a[i] = temp[i];
    }
}

void Merge(int a[], int temp[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        Merge(a, temp, left, mid);
        Merge(a, temp, mid+1, right);
        MergeSort(a, temp, left, mid, right);
    }
}

int Partition(int a[], int low, int high){
    int pivot = a[low];
    while(low < high){
        while(low < high && a[high] >= pivot){
            high--;
        }
        a[low] = a[high];
        while(low < high && a[low] <= pivot){
            low++;
        }
        a[high] = a[low];
    }
    a[low] = pivot;

    return low;
}


void QuickSort(int a[], int low, int high){
    if(low < high){
        int pi = Partition(a, low, high);

        QuickSort(a, low, pi);
        QuickSort(a, pi + 1, high);
    }
}