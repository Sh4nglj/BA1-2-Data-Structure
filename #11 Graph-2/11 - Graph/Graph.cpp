/*******************************************************************************
* FileName:         Graph.cpp
* Author:           尚林杰
* Student Number:   3019244115
* Date:             2020/04/22 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #11
*******************************************************************************/

#include "Graph.h"

Graph::Graph(int max_v){
	num = max_v;
	data = new VexNode[max_v + 1];
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
	//s -> t
	EdgeNode* newEdge_out = new EdgeNode;
	newEdge_out->next = nullptr;
	newEdge_out->dest = t;
	newEdge_out->weight = w;

	if (data[s].outdegree == 0) {		//第一个
		data[s].first = newEdge_out;
	}
	else {
		EdgeNode* temp = data[s].first;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newEdge_out;
	}
	data[s].outdegree++;
	data[t].indegree++;

	//t -> s
	EdgeNode* newEdge_in = new EdgeNode;
	newEdge_in->next = nullptr;
	newEdge_in->dest = s;
	newEdge_in->weight = w;

	if (data[t].outdegree == 0) {
		data[t].first = newEdge_in;
	}
	else {
		EdgeNode* temp = data[t].first;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newEdge_in;
	}
	data[t].outdegree++;
	data[t].indegree++;

	edgeNum++;
	return;
}

int Graph::prim(){
	/*int result = 0;
	int* lowcase = new int[num + 1];
	int* nearvex = new int[num + 1];
	int pos = 1;

	for (int i = 0; i < num + 1; i++) {
		lowcase[i] = 0;
		nearvex[i] = 0;
	}

	for (int i = 1; i < num + 1; i++) {
		int min = MAX_VALUE;
		nearvex[i] = -1;
		for (int j = 1; j < num + 1; j++) {
			EdgeNode* temp = data[i].first;
			//int v = 0; 
						
			while (1) {
				if (nearvex[temp->dest] != -1 && temp->weight < lowcase[temp->dest])
					lowcase[temp->dest] = temp->weight;
				
				if (temp->next != nullptr)
					temp = temp->next;
				else
					break;
			}//while
		}//for (j)
	}//for (i)

	for (int i = 1; i < num + 1; i++)
		result += lowcase[i];

	delete[] lowcase;
	delete[] nearvex;
	return result;*/
	int result = 0;
	int* lowcost = new int[num + 1];
	int* nearvex = new int[num + 1];
	int countNum = 0;
	int v = 1;
	

	for (int i = 0;i < num + 1; i++) {
		lowcost[i] = MAX_VALUE;
		nearvex[i] = 0;
	}
	lowcost[1] = 0;

	while (countNum <= num) {
		nearvex[v] = -1;
		EdgeNode* temp = data[v].first;

		int min = MAX_VALUE;
		int minPos = -1;
		while (1) {
			int tar = temp->dest;
			int wei = temp->weight;

			if (wei < lowcost[tar] && nearvex[tar] != -1) {
				lowcost[tar] = wei;
				
				if (wei < min) {
					min = wei;
					minPos = tar;
				}
			}

			if (temp->next != nullptr)
				temp = temp->next;
			else
				break;			
		}
		v = minPos;
		if (minPos == -1)
			break;
	}

	for (int i = 1; i < num + 1; i++)
		result += lowcost[i];

	delete[] lowcost;
	delete[] nearvex;

	return result;
}

int Graph::kruskal(){
	int result = 0;
	int* nearvex = new int[num + 1];
	int countVex = 0;
	
	for (int i = 0; i < num + 1; i++) {
		nearvex[i] = 0;
	}
	
	struct forKruskal {
		int weight = 0;
		int head = 0;
		int tail = 0;
	};
	forKruskal* allEdge = new forKruskal[edgeNum];

	for (int i = 0; i < edgeNum; i++) {
		//已经是连通图
		if (countVex == num)
			break;

		int minWeight = MAX_VALUE;
		int minHead, minTail;
		
		for (int j = 1; j < num + 1; j++) {
			EdgeNode* temp = data[j].first;
			while (1) {
				if ((nearvex[j] != -1 || nearvex[temp->dest] != -1)
					&& (temp->weight < minWeight)) {
					minWeight = temp->weight;
					minHead = j;
					minTail = temp->dest;
				}
				
				if (temp->next != nullptr)
					temp = temp->next;
				else
					break;			
			}//while
		}//for (j)
		if (nearvex[minHead] == 0) {
			countVex++;
			nearvex[minHead] = -1;
		}
		if (nearvex[minTail] == 0) {
			countVex++;
			nearvex[minTail] = -1;
		}	
		allEdge[i].head = minHead;
		allEdge[i].tail = minTail;
		allEdge[i].weight = minWeight;
	}//for (i)

	for (int i = 0; i < edgeNum; i++) {
		result += allEdge[i].weight;
	}

	delete[] nearvex;
	delete[] allEdge;
	return result;
}