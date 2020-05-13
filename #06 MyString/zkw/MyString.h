#pragma once/*******************************************************************************
* FileName:         MyString.h
* Author:           �ſ�Ϊ
* Student Number:   2019244121
* Date:             2020/03/18 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #6
*******************************************************************************/

#ifndef MYSTRING_H
#define MYSTRING_H

class MyString {
private:
    int len;
    char* str;
public:
    /**
        ���캯��
        @name MyString(const char*);
        @param  const char* ��Ҫ����ΪString���ַ�����
        @return
    */
    MyString(const char* str1);
 
    //��������
    ~MyString();

    /**
     * ���ַ���location��λ���Լ�֮���λ���滻Ϊstr
        @name replace(const char*, const int&);
        @param  const char* ��Ҫ�滻���ַ���
                const int& ��Ҫ�滻��λ��
        @return  void
    */
    void replace(const char* str, int location);

    /**
        �����ַ�������
        @name length()
        @param
        @return  int �ַ����ĳ���
    */
    int length() const;


    /**
        ����str���ַ����е�һ�γ��ֵ�λ��
        @name length()
        @param const char* ��Ҫ���ҵ��ַ���
        @return  int �ַ���str��һ�γ��ֵ�λ�ã����û�г��֣��򷵻�-1.
    */
    int find(const char*) const;

    /**
        ���ش�����ַ�����C���Է���ʾ��
        @name c_string()
        @param
        @return  const char*  ���ص�C���Է���ַ�����
    */
    const char* c_string() const;
};
#endif
