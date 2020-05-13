/*******************************************************************************
* FileName:         BinTree.h
* Author:           尚林杰
* Student Number:   3019244115
* Date:             2020/04/01 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #8
*******************************************************************************/

#ifndef BinTree_H
#define BinTree_H

class BinTree{
private:
    struct Node {
        int leftChild;
        int rightChild;
        int prt;
        int value;
        int high;
    };    
    Node* tree;
    int len;
    int maxHeight;
    const int MAX_ELMT = 10000;

public:
    /**
     *  构造函数，初始化二叉排序树
        @name BinTree();
        @param
        @return 
    */
    BinTree();


    /**
     *  析构函数，销毁二叉排序树
        @name ~BinTree();
        @param 
        @return 
    */
    ~BinTree();

    /**
     *  在二叉排序树中插入元素val，在插入过程中，节点编号从1开始逐渐递增。
        @name insert(int val)
        @param arg1  需要插入的元素值.
        @param arg2  插入元素的父亲节点编号，如果此项值为0，则表示为根结点。
        @param arg3  此元素是左子还是右子。 -1表示左子，1表示右子。
        @return  void
    */
    void insert(int val, int parent, int flg);


    /**
     *  使用前序遍历遍历二叉排序树
        @name p_traversal() const
        @param 
        @return  int*
                 二叉排序树遍历结果,结果需要保存在int数组中。
    */
    int* p_traversal() const;
    void pre_order(const BinTree* bin, int*& output, int pos_tree, int& pos_output) const;


    /**
     *  使用中序遍历遍历二叉排序树
        @name p_traversal() const
        @param 
        @return  int*
                 二叉排序树遍历结果,结果需要保存在int数组中。
    */
    int* m_traversal() const;
    void in_order(const BinTree* bin, int*& output, int pos, int& pos_output) const;

    /**
     *  获得二叉树节点总数
        @name countNode() const
        @param 
        @return  int 二叉树节点数量
    */
    int countNode() const;

    /**
     *  获得二叉树高度
        @name height() const
        @param 
        @return  int 二叉树高度
    */
    int height() const;

};

#endif