/*******************************************************************************
* FileName:         Graph.h
* Author:           Name
* Student Number:   Student_id
* Date:             2020/04/29 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #11
*******************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
private:
    struct EdgeNode {
        EdgeNode* next;
        int dest;
        int weight;
    };
    struct VexNode {
        EdgeNode* first = nullptr;
        int data;
        int indegree = 0;
        int outdegree = 0;
    };
    VexNode* data;
    int num = 0;
    int point_Num = 0;//��¼��ĸ���

public:
    /**
     *  ��Ĺ��캯��
        @name Graph(int)
        @param  arg1 ���Ķ�����
        @return
    */
    Graph(int max_v);

    /**
     *  �����������
        @name ~Graph()
        @param
        @return
    */
    ~Graph();

    /**
     *  ��ͼ�м���(s, t)�� Ȩ��Ϊw�ĵ���
        @name addedge(int, int, int)
        @param  arg1 �ߵĶ���1
        @param  arg2 �ߵĶ���2
        @param  arg3 �ߵ�Ȩ��
        @return  void
    */
    void addedge(int s, int t, int w);

    /**
     *  ѯ��ͼ�нڵ�ĸ���
        @name int getV()
        @param
        @return  int ͼ�нڵ�ĸ���
    */
    int getV();

    /**
     *  ѯ��ͼ��������Ľ�����������������������
        @name int* topological()
        @param
        @return  int* ��������Ľ��
    */
    int* topological();
};
#endif;
