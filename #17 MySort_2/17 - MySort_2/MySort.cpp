/*******************************************************************************
* FileName:         MySort.cpp
* Author:           Your_name
* Student Number:   Student_Number
* Date:             2019/06/03 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #17
*******************************************************************************/

#include "MySort.h"
#include "cmath"

void mergeSort(int *arr, int n){
    int* tempList = new int[n];
    int len = 1;

    while (len < n) {
        mergePass(arr, tempList, len, n);
        len *= 2;
        mergePass(tempList, arr, len, n);
        len *= 2;
    }

    delete[] tempList;
    return;
}

void mergePass(int* initList, int* mergedList, int len, int n) {
    int i = 0;
    while (i + len * 2 - 1 < n - 1) {
        merge(initList, mergedList, i, i + len - 1, i + len * 2 - 1);
        i += len * 2;
    }

    if (i + len <= n - 1)
        merge(initList, mergedList, i, i + len - 1, n - 1);
    else
    {
        for (int j = i; j <= n - 1; j++)
            mergedList[j] = initList[j];
    }
    return;
}

void merge(int* initList, int* mergedList, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        if (initList[i] <= initList[j])
            mergedList[k++] = initList[i++];
        else
            mergedList[k++] = initList[j++];
    }

    while (i <= mid)
    {
        mergedList[k++] = initList[i++];
    }
    while (j <= right)
    {
        mergedList[k++] = initList[j++];
    }       
    return; 
}

void cardSort(int* arr, int len){
    /* 存入链表 */
    /* arr[0] */
    int max_num = arr[0];
    SLNode* first = new SLNode;
    first->value = arr[0];
    first->next = nullptr;
    SLNode* temp = first;
    /* 后续 */
    for (int i = 1; i < len; i++)
    {
        max_num = arr[i] > max_num ? arr[i] : max_num;

        SLNode* newNode = new SLNode;
        newNode->value = arr[i];
        newNode->next = nullptr;
        temp->next = newNode;
        temp = temp->next;
    }

    /* 算出最高有几位 */
    int digit = 0;
    for (digit = 0; max_num > 0; digit++)
    {
        max_num /= 10;
    }
    
    /* 创建关键字序列，在每次<distribute>开始时初始化 */
    SLList* cardList = new SLList[10]; 

    for (int key = 0; key < digit; key++)
    {
        distribute(first, cardList, len, key);
        collect(first, cardList, len);
    }
    
    SLNode* inpt = first;
    int i = 0;
    while (inpt)
    {
        arr[i++] = inpt->value;
        inpt = inpt->next;
    }

    delete[] cardList;
    while (first)
    {
        SLNode* toDelete = first;
        first = first->next;
        delete toDelete;
    }   
    
    return;
}

void distribute(SLNode* &first, SLList* cardList, int len, int key) {
    /* 清空cardList */
    for (int i = 0; i < 10; i++)
    {
        cardList[i].head = nullptr;
        cardList[i].tail = nullptr;
        cardList[i].num = 0;
    }
    
    
    /* keyNum为计算第key位的模板 */
    int keyTemplate = 1;
    for (int i = 0; i < key; i++)
    {
        keyTemplate *= 10;
    }

    /* 依次存入cardList */
    for (int i = 0; i < len; i++, first = first->next)
    {
        /* 以temp记录first的位置，并调整first所指向的地址 */
        SLNode* temp = first;

        /* 计算关键字 */
        int keyNum = (temp->value / keyTemplate) % 10;

        /* 存入cardList */
        if (cardList[keyNum].num == 0)
        {
            cardList[keyNum].head = temp;
            cardList[keyNum].tail = temp;
            cardList[keyNum].num++;
        }
        else
        {
            cardList[keyNum].tail->next = temp;
            cardList[keyNum].tail = temp;
            cardList[keyNum].num++;
        }        
    }
    
    /* 调整first指向第一个的head */
    int pos = 0;
    while (cardList[pos].num == 0)
    {
        pos++;
    }
    first = cardList[pos].head;
    return;
}

void collect(SLNode* first, SLList* cardList, int len) {
    /* 找到第一个有元素的 */
    int pos = 0;
    while (cardList[pos].num == 0)
    {
        pos++;
    }

    /* 首尾相连 */
    while (pos < 9)
    {
        int tar = pos + 1;
        
        /* 如果下一项没有元素 */
        while (cardList[tar].num == 0)
        {
            if (tar == 9)
            {
                break;
            }
            else
            {
                tar++;
            }                       
        }

        /* 连接 */
        cardList[pos].tail->next = cardList[tar].head;
        
        pos = tar;
    }
    
    return;
}