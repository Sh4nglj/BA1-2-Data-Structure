/*******************************************************************************
* FileName:         LinkStack.cpp
* Author:           李晓鹏
* Student Number:   3019244114
* Date:             2020/03/05 14:20:06
* Version:          v1.0
* Description:      Data Structure Experiment #4
*******************************************************************************/


#include "LinkStack.h"
#include <iostream>


Stack::Stack(){
    head = NULL;
    length = 0;
}

Stack::~Stack(){
    for (int i = 0; i < length; i++) {
        StackNode *temp;
        temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
    }
    delete head;
    head = NULL;
}

void Stack::push_back(int data){
    StackNode *newNode = new StackNode;
    newNode->value = data;
    newNode->next = head;
    head = newNode;
    length++;
}

int Stack::top() const{
    if (length == 0)
        return 0;
    else
        return head->value;
}

void Stack::pop(){
    if (length == 0)
        return;
    else {
        StackNode *temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
        length--;
    }
}
