#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Merge(int arr[], int temp[], int front, int nail);
void MergeSort(int arr[], int temp[], int front, int mid, int nail);

int main(){
    int num_count = 0; // 数字个数
    int up_limit = 0;
    int dif = 0; // 序列中最大值与最小值的差
    int result = 0; // 最终结果
    scanf("%d%d", &num_count, &up_limit); // 输入序列长度和m
    if(up_limit <= 0 || num_count <= 0){
        printf("Input is not valid!");
        exit(0);
    }
    int* arr = NULL;
    int* temp = NULL;
    arr = (int*)calloc(num_count, sizeof(int));
    temp = (int*)calloc(num_count, sizeof(int));
    if(arr == NULL || temp == NULL){
        if(arr != NULL){
            free(arr);
        }
        if(temp != NULL){
            free(temp);
        }
        printf("No enough memory to allocate!");
        exit(0);
    }
    for(int i=0;i<num_count;i++){
        scanf("%d", &arr[i]);
    }
    Merge(arr, temp, 0, num_count - 1);
    // // 测试排序是否成功
    // for(int i=0;i<num_count;i++){
    //     printf("%d ", arr[i]);
    // }
    dif = arr[num_count - 1] - arr[0];
    if(dif % up_limit == 0){
        result = dif / up_limit;
    }else{
        result = dif / up_limit + 1;
    }
    printf("%d", result);
    free(arr);
    free(temp);
    return 0;
}

void MergeSort(int arr[], int temp[], int front, int mid, int nail){
    int i = front;
    int j = mid + 1;
    int k = front;
    while(i <= mid && j <= nail){
        if(arr[i] > arr[j]){
            temp[k] = arr[j++];
        }else{
            temp[k] = arr[i++];
        }
        k++;
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= nail){
        temp[k++] = arr[j++];
    }
    for(int l = front;l <= nail;l++){
        arr[l] = temp[l];
    }
}

void Merge(int arr[], int temp[], int front, int nail){
    if(front < nail){
        int mid = front + (nail - front) / 2;

        Merge(arr, temp, front, mid);
        Merge(arr, temp, mid + 1, nail);
        MergeSort(arr, temp, front, mid, nail);
    }
}