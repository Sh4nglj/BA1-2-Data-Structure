/*******************************************************************************
* FileName:         Graph.cpp
* Author:           Your_name
* Student Number:   Student_Number
* Date:             2020/04/14 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #10
*******************************************************************************/

#include "Graph.h"


Graph::Graph(int v){
	vexList = new VexData[v];
	edge = new EdgeData[v * v];
	num = 0;
}

Graph::~Graph(){
	delete[] vexList;
	delete[] edge;
}

void Graph::addedge(int s, int t, int w){
	int inVex = s - 1;
	int outVex = t - 1;
	edge[num].in = inVex;
	edge[num].out = outVex;
	edge[num].weight = w;
	vexList[inVex].outdegree++;
	vexList[outVex].indegree++;
	num++;
}

int Graph::getInDegree(int v){
	return vexList[v - 1].indegree;
}

int Graph::getOutDegree(int v){
	return vexList[v - 1].outdegree;
}

int Graph::access(int s, int t){
	for (int i = 0; i < num; i++) {
		if (edge[i].in == (s - 1) && edge[i].out == (t - 1))
			return edge[i].weight;
	}
	return -1;
}