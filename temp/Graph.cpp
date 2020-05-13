/*******************************************************************************
* FileName:         Graph.cpp
* Author:           Your_name
* Student Number:   Student_Number
* Date:             2020/04/29 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #11
*******************************************************************************/

#include "Graph.h"
#include <cstddef>

Graph::Graph(int max_v) {
	num = max_v;
	data = new VexNode[max_v + 1];
}

Graph::~Graph() {
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

void Graph::addedge(int s, int t, int w) {
	EdgeNode* newEdge = new EdgeNode;
	newEdge->next = nullptr;
	newEdge->dest = t;
	newEdge->weight = w;

	if (data[s].outdegree == 0) {		//µÚÒ»¸ö
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

int Graph::getV() {
	for (int i = 0; i < num + 1; i++)
	{
		if (data[i].indegree != 0 || data[i].outdegree != 0)
			point_Num++;
	}
	return point_Num;
}

int* Graph::topological() {
	int* arr = new int[100];
	int j = 0;
	
	for (int i = 0; i < num + 1; i++)
		arr[i] = 0;
	
	for (int i = 1; i < num + 1; i++)
	{
		if (data[i].indegree == 0)
		{
			arr[j++] = i;
			
			EdgeNode* temp = data[i].first;
			
			while (temp != nullptr)
			{
				data[temp->dest].indegree--;
				temp = temp->next;
			}//while
		}//if
	}//for

	return arr;
}
