/*******************************************************************************
* FileName:         myHash.cpp
* Author:           Your_name
* Student Number:   Student_Number
* Date:             2020/05/20 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #15
*******************************************************************************/

#include "myHash.h"
#include <iostream>

MyHash::MyHash(int max_element){
    data = new HashList[p];
    for (int i = 0; i < p; i++) {
        data[i].first = nullptr;
        data[i].flag = false;
    }
}

MyHash::~MyHash(){
    for (int i = 0; i < p; i++) {
        if (!data[i].flag) {
            continue;
        }

        HashNode* temp = data[i].first;
        while (temp->next != nullptr) {
            HashNode* toDlt = temp;
            temp = temp->next;
            delete toDlt;
        }
        delete temp;
    }//for
    delete[] data;
}

void MyHash::setvalue(int key, int value){
   int rem = key % p;

   if (!data[rem].flag) {
       HashNode* newNode = new HashNode;
       newNode->numKey = key;
       newNode->val = value;
       newNode->next = nullptr;
       data[rem].flag = true;
       data[rem].first = newNode;
   }
   else {
       HashNode* temp = data[rem].first;
       while(temp->numKey != key && temp->next != nullptr) {
           temp = temp->next;
       }
       if (temp->numKey == key) {
           temp->val = value;
       }
       else {
            HashNode* newNode = new HashNode;
            newNode->numKey = key;
            newNode->val = value;
            newNode->next = nullptr;
            temp->next = newNode;
       }
   }
   return;
}

int MyHash::getvalue(int key){
    int result = 0;
    int rem = key % p;
    
    /* No such key in the array */
    if (!data[rem].flag) {
        std::cout << "ERROR!" << std::endl;
        return -1;
    }

    HashNode* temp = data[rem].first;
    while (temp) {
        if (temp->numKey)
            result = temp->val;
        
        temp = temp->next;
    }

    return result;
}