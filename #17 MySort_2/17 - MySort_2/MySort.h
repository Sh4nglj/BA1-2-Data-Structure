/*******************************************************************************
* FileName:         MySort.h
* Author:           尚林杰
* Student Number:   3019244115
* Date:             2020/06/03 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #17
*******************************************************************************/

struct SLNode {
    int value;
    SLNode* next;
};

struct SLList {
    int num;
    SLNode* head;
    SLNode* tail;
};

/**
 *  归并排序，要求对arr进行归并排序，数组长度为len
    @name mergeSort(int*, int);
    @param arg1  需要排序对数组
    @param arg2  数组的长度
    @return 
*/
void mergeSort(int* arr, int n);

void mergePass(int* initList, int* mergedList, int len, int n);

void merge(int* initList, int* mergedList, int left, int mid, int right);

/**
 *  基数排序，要求对arr进行基数排序，数组长度为len
    @name cardSort(int*, int);
    @param arg1  需要排序对数组
    @param arg2  数组的长度
    @return 
*/
void cardSort(int* arr, int len);

void distribute(SLNode* &first, SLList* cardList, int len, int key);

void collect(SLNode* first, SLList* cardList, int len);