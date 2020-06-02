/*******************************************************************************
* FileName:         MySort.cpp
* Author:           尚林杰
* Student Number:   3019244115
* Date:             2019/05/27 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #16
*******************************************************************************/

#include "MySort.h"

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void MySort::bubbleSort(int* arr, int len){
    int i = 0;
    bool flag = true;
    
    
    while (i < len && flag) {
        flag = false;
        for (int j = len - 1; j > i; j--) {
            if (arr[j - 1] > arr[j]) {
                // swap(arr[j - 1], arr[j]);
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                flag = true;
            }//if
        }//for
        i++;
    }//while
    return;

    
    // while (i < len && flag) {
    //     flag = false;
    //     for (int j = i + 1; j < len; j++) {
    //         if (arr[j - 1] > arr[j]) {
    //             int temp = arr[j - 1];
    //             arr[j - 1] = arr[j];
    //             arr[j] = temp;
    //             flag = true;
    //         }
    //     }
    //     i++;
    // }
    
}



void MySort::quickSort(int* arr, int len){
    Qsort(arr, 0, len - 1);
}

void MySort::Qsort(int* arr, int low, int high) {
    /* 递归 */
    if (low < high) {
        /* pivotloc 为函数中low 和 high 重合的地址 */
        int pivotloc = partition(arr, low, high);

        /* 分别对左右进行 */
        Qsort(arr, low, pivotloc - 1);
        Qsort(arr, pivotloc + 1, high);
    }
}

int MySort::partition(int* arr, int low, int high) {
    /* 记录基准，最后填回arr[low] */
    int pivotkey = arr[low];

    while (low < high) {
        while (low < high && arr[high] >= pivotkey) {
            high--;
        }
        arr[low] = arr[high];   /* 移到左侧 */

        while (low < high && arr[low] <= pivotkey) {
            low++;
        }
        arr[high] = arr[low];   /* 移到右侧 */
    }
    /* low 和 high 重合 */
    arr[low] = pivotkey;
    return low;
}

void MySort::heapSort(int* arr, int len){
    for (int i = len / 2 - 1; i >= 0; i--)
        heapAdjust(arr, i, len);
    
    for (int i = len - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapAdjust(arr, 0, i);
    }
}

void MySort::heapAdjust(int* arr, int s, int size) {
    int temp = arr[s];
    
    for (int i = 2 * s + 1; i < size; i = 2 * i + 1) {
        if (i < size - 1 && arr[i] < arr[i + 1])
            i++;
        if (temp >= arr[i])
            break;
        arr[s] = arr[i];
        s = i;
    }
    arr[s] = temp;
}