/*******************************************************************************
* FileName:         Haffman.h
* Author:           Name
* Student Number:   3019244XXX
* Date:             2020/04/07 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #10
*******************************************************************************/

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

class HuffmanTree{
private:
public:
    /**
     *  构造函数
        @name HuffmanTree(const char* str)
        @param arg1 需要进行哈夫曼编码的字符串
        @return
        注意： 要求树的左孩子为权制较小的编码，左孩子的二进制编号为0
    */
    HuffmanTree(const char* str);

    /**
     *  析构函数
        @name ~HuffmanTree()
        @param 
        @return
    */
    ~HuffmanTree();

    /**
     *  获得哈夫曼树关于字符C的编码
        @name int getcode(char)
        @param  arg1 需要获取编码的字符
        @return 哈夫曼树下C的编码
    */
    char* getcode(char c);


    /**
     *  获得哈夫曼树的WPL
        @name int getWPL()
        @param 
        @return 哈夫曼树的WPL
    */
    int getWPL();
};

#endif