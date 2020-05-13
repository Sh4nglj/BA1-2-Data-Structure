/*******************************************************************************
* FileName:         Graph.cpp
* Author:           尚林杰
* Student Number:   3019244115    
* Date:             2020/05/06 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #13
*******************************************************************************/

#include "Graph.h"

Graph::Graph(int max_v){
	num = max_v;
	numV = 0;
	dist = new int[numV];

	data = new VexNode[max_v + 1];
	for (int i = 0; i < max_v + 1; i++) {
		data[i].first = nullptr;
		data[i].indegree = 0;
		data[i].outdegree = 0;
	}
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
	
	delete[] dist;
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

	if (data[s].outdegree == 0 && data[s].indegree == 0)
		numV++;
	if (data[t].indegree == 0 && data[t].outdegree == 0)
		numV++;

	data[s].outdegree++;
	data[t].indegree++;

	return;
}

int Graph::getV(){
	return numV;
}

int* Graph::dijkstra(){
	int* done = new int[numV + 1];
		
	for (int i = 1; i < numV + 1; i++) {
		dist[i - 1] = -1;
		done[i] = 0;
	}
	dist[0] = 0;
	
	EdgeNode* tempFirst = data[1].first;
	while (1) {
		dist[tempFirst->dest - 1] = tempFirst->weight;

		if (tempFirst->next != nullptr)
			tempFirst = tempFirst->next;
		else
			break;
	}

	for (int i = 1; i <= numV; i++) {
		int min = MAX_VALUE;
		int pos = 0;

		for (int j = 2; j <= numV; j++) {
			if (dist[j - 1] != -1 && !done[j] && dist[j - 1] < min) {
				pos = j;
				min = dist[j - 1];
			}//if
		}//for
		if (pos == 0)
			break;
		done[pos] = 1;

		if (data[pos].first == nullptr)
			continue;

		EdgeNode* tempPos = data[pos].first;
		while (1) {
			int tar = tempPos->dest;
			int value = dist[pos - 1] + tempPos->weight;

			if ((dist[tar - 1] == -1) ||
				(tar != 1 && !done[tar] && value < dist[tar - 1]))
				dist[tar - 1] = value;

			if (tempPos->next != nullptr)
				tempPos = tempPos->next;
			else
				break;
		}//while
	}//for

	delete[] done;
	return dist;
}