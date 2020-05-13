/*******************************************************************************
* FileName:         Haffman.cpp
* Author:           尚林杰
* Student Number:   3019244115
* Date:             2020/04/08 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #10
*******************************************************************************/

#include "Huffman.h"
#include <iostream>
#include <string>
using namespace std;

HuffmanTree::HuffmanTree(const char* str){
	int len = strlen(str);
	int count[26];
	
	//count中计数各个字母数量——权重
	for (int i = 0; i < 26; i++)
		count[i] = 0;
	for (int i = 0; i < len; i++) {
		if (count[str[i] - 'a'] == 0)
			n++;
		count[str[i] - 'a']++;
	}

	//初始化l[]
	l = new int[n];
	
	//初始化data[]
	m = 2 * n - 1;
	data = new HuffmanNode[m];
	for (int i = 0; i < n; i++) {
		data[i].ch = i + 'a';
		data[i].weight = count[i];
		data[i].leftchild = -1;
		data[i].rightchild = -1;
		data[i].parent = -1;
	}
	for (int i = n; i < m; i++) {
		data[i].ch = 0;
		data[i].weight = 0;
		data[i].leftchild = -1;
		data[i].rightchild = -1;
		data[i].parent = -1;
	}

	//构造
	for (int i = n; i < m; i++) {
		int min1 = MAX_NUM;
		int min2 = MAX_NUM;
		int pos1 = 0;
		int pos2 = 0;

		for (int j = 0; j < i; j++) {
			if (data[j].parent == -1) {
				if (data[j].weight < min1) {
					pos2 = pos1;
					min2 = min1;
					pos1 = j;
					min1 = data[j].weight;
				}//if
				else if (data[j].weight < min2) {
					pos2 = j;
					min2 = data[j].weight;
				}//else if
			}//if			
		}//for
		data[i].leftchild = pos1;
		data[i].rightchild = pos2;
		data[i].weight = min1 + min2;
		data[pos1].parent = i;
		data[pos2].parent = i;
		data[i].ch = 'a' + n;
	}//for
}//HuffmanTree

HuffmanTree::~HuffmanTree(){
	delete[] data;
	delete[] l;
	delete[] result;
}

char* HuffmanTree::getcode(char c){
	char target = c;
	
	//get pos
	int pos = 0;
	for (int i = 0; i < n; i++) {
		if (data[i].ch == c) {
			pos = i;
			break;
		}
	}

	string code = "";
	int temp = pos;
	while (data[temp].parent != -1) {
		temp = data[temp].parent;
	
		if (data[data[temp].leftchild].ch == target) 
			code = "0" + code;				//可能有问题
		else
			code = "1" + code;				//可能有问题

		target = data[temp].ch;
	}

	int len = code.size();
	l[pos] = len;
	result = new char[len + 1];
	for (int i = 0; i < len; i++) 
		result[i] = code[i];
	result[len] = '\0';
	return result;
}

int HuffmanTree::getWPL(){
	int result = 0;
	for (int i = 0; i < n; i++) 
		result += data[i].weight * l[i];
	return result;
}