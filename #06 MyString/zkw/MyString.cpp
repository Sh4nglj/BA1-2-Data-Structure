/*******************************************************************************
* FileName:         MyString.cpp
* Author:           尚林杰
* Student Number:   3019244121
* Date:             2020/03/18 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #3
*                   完成程度：
*                       简要说一下自己写了多少，完成了哪些函数
*******************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "MyString.h"


MyString::MyString(const char* myStr) {
	len = strlen(myStr);
	str = new char[len+1];
	for (int i = 0; i < len; i++)
	{
		str[i] = myStr[i];
	}
	str[len] = '\0';
}

MyString::~MyString() {
	delete[] str;
}

int MyString::length() const {
	return len;
}

void MyString::replace(const char* toReplace, int loc)
{
	/*if (loc<0 || loc>len)
	{
		return;
	}
	int len1 = strlen(replace);
	if (len1 + loc >= len)
	{
		char* temp = str;
		str = new char[loc + len1 + 1];
		str[loc + len1] = '\0';
		len = loc + len1;
		for (int i = 0; i < loc; i++)
		{
			str[i] = temp[i];
		}
		for (int i = loc; i < loc + len1; i++)
		{
			str[i] = replace[i - loc];
		}
		delete[] temp;
	}
	else
	{
		for (int i = loc; i < loc + len1; i++)
		{
			str[i] = replace[i - loc];
		}
	}*/

	int len2r = strlen(toReplace);
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
	temp = NULL;
}

int MyString::find(const char* str2) const{
	int b = strlen(str2);
	int i = 0, j = 0;
	while (i <len && j < b)
	{
		if (str[i] == str2[j])
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

const char* MyString::c_string() const {
	return str;
}