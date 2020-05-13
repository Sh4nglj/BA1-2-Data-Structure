/*******************************************************************************
* FileName:         Graph.cpp
* Author:           尚林杰
* Student Number:   3019244115
* Date:             2020/04/29 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #11
*******************************************************************************/

#include "Graph.h"
#include <iostream>

Stack::Stack() {
	head = NULL;
	length = 0;
}

Stack::~Stack() {
	for (int i = 0; i < length; i++) {
		StackNode* temp;
		temp = head;
		head = head->next;
		delete temp;
		temp = NULL;
	}
	delete head;
	head = NULL;
}

void Stack::push_back(int data) {
	StackNode* newNode = new StackNode;
	newNode->value = data;
	newNode->next = head;
	head = newNode;
	length++;
}

int Stack::top() const {
	if (length == 0)
		return 0;
	else
		return head->value;
}

void Stack::pop() {
	if (length == 0)
		return;
	else {
		StackNode* temp = head;
		head = head->next;
		delete temp;
		temp = NULL;
		length--;
	}
}

Graph::Graph(int max_v){
	num = max_v;
	numV = 0;
	
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
	delete[] data;
	delete[] result;
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

int* Graph::topological(){
	result = new int[numV];
	int pos = 0;
	
	int* count = new int[numV + 1];
	for (int i = 1; i <= numV; i++) {
		count[i] = data[i].indegree;
	}
	
	Stack S;
	for (int i = 1; i <= numV; i++) {
		if (data[i].indegree == 0)
			S.push_back(i);
	}

	int topElmt = S.top();
	
	while (topElmt) {
		result[pos++] = topElmt;
		S.pop();
		
		EdgeNode* temp = data[topElmt].first;
		//结束
		if (temp == nullptr && S.top() == 0)
			break;
		else if (temp == nullptr && S.top() != 0) {
			topElmt = S.top();
			continue;
		}

		while (1) {
			//入度减一，即为删去一条边
			count[temp->dest]--;
			
			//入度为0，进栈
			if (count[temp->dest] == 0)
				S.push_back(temp->dest);

			if (temp->next != nullptr)
				temp = temp->next;
			else
				break;
		}

		topElmt = S.top();
	}
	
	delete[] count;
	return result;
}