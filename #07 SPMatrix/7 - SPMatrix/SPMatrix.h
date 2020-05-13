/*******************************************************************************
* FileName:         SPMatrix.h
* Author:           尚林杰
* Student Number:   3019244115
* Date:             2020/03/22 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #7
*                   注意： 1. 矩阵i, j 下标默认从0开始
*
*******************************************************************************/

#ifndef SPMATRIX_H
#define SPMATRIX_H
#define MAXSIZE 10000

class SPMatrix{
private:
	struct TpNode {
		int row;
		int col;
		int value;
	}; 
	int mu;		//行数
	int nu;		//列数
	int tu;		//非零元素总数
	int* numR;	//每行元素个数
	int* numC;	//每列元素个数
	TpNode* data;

public:

    /**
        稀疏矩阵 构造函数， 构造行为rows， 列为cols的稀疏矩阵，元素最多为max_elements的矩阵
        @name SPMatrix(int, int, int);
        @param arg1 矩阵的行数
	    @param arg2 矩阵的列数
        @return 

    */
    SPMatrix(int r, int c, int max_elements);
    /**
        稀疏矩阵 构造函数， 构造行为rows， 列为cols的稀疏矩阵
        @name SPMatrix(int r, int c);
        @param arg1 矩阵的行数
	    @param arg2 矩阵的列数
        @return 
    */
    SPMatrix(int r, int c);


    virtual ~SPMatrix();


    /**
        指定第i行第j列的数字为val ()
        @name void set(int i, int j, int val);
        @param arg1 目标行
	    @param arg2 目标列
	    @param arg3 需要设定的数字
        @return  void
    */
    void set(int i, int j, int val);


    /**
        获取第i行第j列位置的值，如果三元表中没有，则默认为0
        @name void get(int i, int j);
        @param arg1 目标行
	    @param arg2 目标列
        @return  int (i, j)中储存的值
    */
    int get(int i, int j)const;
    
    /**
        重载矩阵的转置
        @name void rotate();
        @return  void
    */
    void rotate();


    /**
        重载矩阵的加法
        @name SPMatrix operator+(const SPMatrix& b);
        @param arg1 需要加上的矩阵
        @return  SPMatrix 相加的结果
    */
    SPMatrix operator+(const SPMatrix& b);
    SPMatrix operator-(const SPMatrix& b);

    SPMatrix operator*(const SPMatrix& c);

};
#endif