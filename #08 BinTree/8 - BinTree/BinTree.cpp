/*******************************************************************************
* FileName:         BinTree.cpp
* Author:           ипаж╫э
* Student Number:   3019244115
* Date:             2020/04/01 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #8
*******************************************************************************/


#include "BinTree.h";
#include <iostream>

BinTree::BinTree(){
    tree = new Node[MAX_ELMT];
    len = 0;
    maxHeight = 1;
}


BinTree::~BinTree(){
    delete[] tree;
    len = 0;
}

void BinTree::insert(int val, int parent, int flg){
    //tree[] start from [1], 
    len++;
    tree[len].value = val;
    tree[len].leftChild = NULL;
    tree[len].rightChild = NULL;
    tree[len].prt = parent;
    if (flg == -1)
        tree[parent].leftChild = len;
    else
        tree[parent].rightChild = len;
    if (parent == 0) {
        tree[len].high = 1;
        maxHeight = 1;
    }
    else {
        tree[len].high = tree[tree[len].prt].high + 1;
        maxHeight = tree[len].high >= maxHeight ? tree[len].high : maxHeight;
    }
    return;
}

int* BinTree::m_traversal() const{
    int* result = new int[len];
    int pos_tree = 1;
    int pos_output = 0;
    in_order(this, result, pos_tree, pos_output);
    return result;
}

void BinTree::in_order(const BinTree* bin, int*& output, int pos_tree, int& pos_output) const{
    if (pos_tree != NULL) {
        in_order(bin, output, bin->tree[pos_tree].leftChild, pos_output);        
        output[pos_output++] = bin->tree[pos_tree].value;        
        in_order(bin, output, bin->tree[pos_tree].rightChild, pos_output);       
    }
}

int* BinTree::p_traversal() const{
    int* result = new int[len];
    int pos_tree = 1;
    int pos_output = 0;
    pre_order(this, result, pos_tree, pos_output);
    return result;
}

void BinTree::pre_order(const BinTree* bin, int*& output, int pos_tree, int& pos_output) const {
    if (pos_tree != NULL) {
        output[pos_output++] = bin->tree[pos_tree].value;
        pre_order(bin, output, bin->tree[pos_tree].leftChild, pos_output);
        pre_order(bin, output, bin->tree[pos_tree].rightChild, pos_output);
    }
}

int BinTree::countNode() const{
    return len;
}

int BinTree::height() const{
    return maxHeight;
}

