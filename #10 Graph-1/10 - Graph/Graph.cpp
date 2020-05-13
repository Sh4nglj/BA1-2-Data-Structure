/*******************************************************************************
* FileName:         Graph.cpp
* Author:           尚林杰
* Student Number:   3019244115
* Date:             2020/04/14 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #10
*******************************************************************************/

#include "Graph.h"
#include <iostream>


Graph::Graph(int v){
	num = v;
	data = new VexNode[v + 1];
}

Graph::~Graph(){
	for (int i = 1; i <= num; i++) {
		if (data[i].outdegree == 0)
			continue;

		EdgeNode* temp = data[i].first;
		while (temp->next != nullptr) {
			EdgeNode* toDelete = temp;
			temp = temp->next;
			delete toDelete;
		}
		delete temp;
	}//for
	delete[] data;
}

void Graph::addedge(int s, int t, int w){
	EdgeNode* newEdge = new EdgeNode;
	newEdge->next = nullptr;
	newEdge->dest = t;
	newEdge->weight = w;	

	if (data[s].outdegree == 0) {		//第一个
		data[s].first = newEdge;
	}
	else {
		EdgeNode* temp = data[s].first;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newEdge;
	}

	data[s].outdegree++;
	data[t].indegree++;
}

int Graph::getInDegree(int v){
	return data[v].indegree;
}

int Graph::getOutDegree(int v){
	return data[v].outdegree;
}

int Graph::access(int s, int t){
	EdgeNode* temp = data[s].first;
	
	if (data[s].outdegree == 0)
		return -1;
	
	do {
		if (temp->dest == t)
			return temp->weight;
		else
			temp = temp->next;
	} while (temp->next != nullptr);
	return -1;
}