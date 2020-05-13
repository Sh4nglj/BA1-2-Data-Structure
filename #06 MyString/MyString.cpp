/*******************************************************************************
* FileName:         MyString.cpp
* Author:           尚林杰
* Student Number:   3018216115
* Date:             2020/03/18 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #3
*                   完成程度：
*                       简要说一下自己写了多少，完成了哪些函数
*******************************************************************************/
#include <cstdio>
#include <cstdlib>
#include "MyString.h"
#include <string>


MyString::MyString(const char* str){
	/*len = strlen(str);
	myStr = new char[len + 1];
	//strcpy(myStr, str);
	strcpy_s(myStr, len, str);
	myStr[len] = '\0';*/

	len = strlen(str);
	myStr = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		myStr[i] = str[i];
	}
	myStr[len] = '\0';
}

MyString::~MyString(){
	delete[] myStr;
}

int MyString::length() const{
	return len;
}

void MyString::replace(const char* toReplace, int loc){
	/*int len2r = strlen(toReplace);
	char* dest = new char[loc + len2r + 1];
	//strncpy(dest, myStr, loc);
	//截取前半部分
	strncpy_s(dest, loc, myStr, loc);
	//后半部分
	strcpy_s(dest, len2r, toReplace);
	dest[loc + len2r] = '\0';

	char* temp = myStr;
	myStr = dest;
	delete temp;
	temp = NULL;*/

	if (loc<0 || loc>len)
	{
		return;
	}
	int len1 = strlen(toReplace);
	if (len1 + loc >= len)
	{
		char* temp = myStr;
		myStr = new char[loc + len1 + 1];
		myStr[loc + len1] = '\0';
		len = loc + len1;
		for (int i = 0; i < loc; i++)
		{
			myStr[i] = temp[i];
		}
		for (int i = loc; i < loc + len1; i++)
		{
			myStr[i] = toReplace[i - loc];
		}
		delete[] temp;
	}
	else
	{
		for (int i = loc; i < loc + len1; i++)
		{
			myStr[i] = toReplace[i - loc];
		}
	}
}

int MyString::find(const char* str) const{
	/*
	// getNext
	int* next = new int[strlen(str)];
	//int next[strlen(str)];
	next[0] = -1;
	int i = 0, j = -1;

	while (i < strlen(str)) {
		if (j == -1 || str[i] == str[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}

	// compare
	i = 0;
	j = 0;
	while (i < len && (j == -1 || j < strlen(str))) {
		if (j == -1 || myStr[i] == str[j]) {
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j == strlen(str)) {
		delete[] next;
		return i - j;
	}
	else {
		delete[] next;
		return -1;
	}*/

	int b = strlen(str);
	int i = 0, j = 0;
	while (i < len && j < b)
	{
		if (myStr[i] == str[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j = b)
		return i - b;
	else
		return 0;
}

const char* MyString::c_string() const{
	return myStr;
}