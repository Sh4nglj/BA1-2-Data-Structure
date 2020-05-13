/*******************************************************************************
* FileName:         SPMatrix.cpp
* Author:           ���ֽ�
* Student Number:   3019244115
* Date:             2020/03/20 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #7
*
*******************************************************************************/

#include "SPMatrix.h"

SPMatrix::SPMatrix(int r, int c){
	mu = r;
	nu = c;
	tu = 0;
	data = new TpNode[MAXSIZE + 1];		//delete
	numR = new int[r + 1];				//delete
	for (int i = 0; i < r + 1; i++) {
		numR[i] = 0;
	}
	numC = new int[c + 1];				//delete
	for (int i = 0; i < c + 1; i++) {
		numC[i] = 0;
	}
}

SPMatrix::SPMatrix(int r, int c, int max_element){
	mu = r;
	nu = c;
	tu = 0;
	data = new TpNode[max_element + 1];
	numR = new int[r + 1];
	for (int i = 0; i < r + 1; i++) {
		numR[i] = 0;
	}
	numC = new int[c + 1];
	for (int i = 0; i < c + 1; i++) {		
		numC[i] = 0;
	}
}

int SPMatrix::get(int i, int j)const{
	for (int k = 1; k <= tu; k++) {
		if (data[k].row == i && data[k].col == j)
			return data[k].value;
	}
	//δ�ҵ�
	return 0;
}

void SPMatrix::set(int i, int j, int val){
	tu++;
	data[tu].row = i;
	data[tu].col = j;
	data[tu].value = val;
	numR[i]++;
	numC[j]++;
}

void SPMatrix::rotate() {
	//����ÿ����ʼλ��
	int* cPos = new int[nu + 1];	
	cPos[0] = 0;
	cPos[1] = 1;
	for (int i = 2; i <= nu; i++) {
		cPos[i] = cPos[i - 1] + numC[i - 1];
	}//for

	//����temp����	
	int sizeData = sizeof(data) / sizeof(data[1]);	//data�Ĵ�С
	TpNode* old_data = data;	//��Ҫdelete
	data = new TpNode[sizeData];
	TpNode* new_data = data;

	for (int i = 1; i <= tu; i++) {
		int colOld = old_data[i].col;	//old_data��i��Ԫ�ص�����
		int posNew = cPos[colOld];		//old_data��i��
		new_data[posNew].row = old_data[i].col;
		new_data[posNew].col = old_data[i].row;
		new_data[posNew].value = old_data[i].value;
		cPos[colOld]++;
	}//for
	
	//����mu,nu��ֵ
	int tempU = mu;
	mu = nu;
	nu = tempU;

	//����num����
	int* tempNum = numR;
	numR = numC;
	numC = tempNum;

	delete[] cPos;
	delete[] old_data;
	return;
}//rotate

SPMatrix SPMatrix::operator+(const SPMatrix& b){
	//����ӷ�Ϊÿ���������
	//�˶���this��ʾdata�����ľ���
	
	SPMatrix result(mu, nu);
	
	int posA = 1;
	int posB = 1;
	int posR = 1;
	int valueR = 0;	//result��value������Ϊ0�����

	while (posA <= this->tu && posB <= b.tu) {
		//λ��ͬһ��
		if (this->data[posA].row == b.data[posB].row) {
			if (this->data[posA].col < b.data[posB].col) {
				result.data[posR].row = this->data[posA].row;
				result.data[posR].col = this->data[posA].col;
				result.data[posR].value = this->data[posA].value;
				posA++;
				posR++;
			}//if
			else if (this->data[posA].col > b.data[posB].col) {
				result.data[posR].row = b.data[posB].row;
				result.data[posR].col = b.data[posB].col;
				result.data[posR].value = b.data[posB].value;
				posB++;
				posR++;
			}//else if
			else {
				valueR = this->data[posA].value + b.data[posB].value;				
				//���������
				if (valueR != 0) {
					result.data[posR].row = this->data[posA].row;
					result.data[posR].col = this->data[posA].col;
					result.data[posR].value = valueR;
					posR++;
				}//if
				posA++;
				posB++;
			}//else
		}//if ͬһ��
		else if (this->data[posA].row < b.data[posB].row) {
			result.data[posR].row = this->data[posA].row;
			result.data[posR].col = this->data[posA].col;
			result.data[posR].value = this->data[posA].value;
			posA++;
			posR++;
		}//else if A��ǰһ��
		else {
			result.data[posR].row = b.data[posB].row;
			result.data[posR].col = b.data[posB].col;
			result.data[posR].value = b.data[posB].value;
			posB++;
			posR++;
		}//else B��ǰһ��
		result.tu = posR;
	}//while
	return result;
}//operator+

SPMatrix SPMatrix::operator-(const SPMatrix& b){
	SPMatrix result(mu, nu);

	int posA = 1;
	int posB = 1;
	int posR = 1;
	int valueR = 0;	//result��value������Ϊ0�����

	while (posA <= this->tu && posB <= b.tu) {
		//λ��ͬһ��
		if (this->data[posA].row == b.data[posB].row) {
			if (this->data[posA].col < b.data[posB].col) {
				result.data[posR].row = this->data[posA].row;
				result.data[posR].col = this->data[posA].col;
				result.data[posR].value = this->data[posA].value;
				posA++;
				posR++;
			}//if
			else if (this->data[posA].col > b.data[posB].col) {
				result.data[posR].row = b.data[posB].row;
				result.data[posR].col = b.data[posB].col;
				result.data[posR].value = -b.data[posB].value;
				posB++;
				posR++;
			}//else if
			else {
				valueR = this->data[posA].value - b.data[posB].value;
				//���������
				if (valueR != 0) {
					result.data[posR].row = this->data[posA].row;
					result.data[posR].col = this->data[posA].col;
					result.data[posR].value = valueR;
					posR++;
				}//if
				posA++;
				posB++;
			}//else
		}//if ͬһ��
		else if (this->data[posA].row < b.data[posB].row) {
			result.data[posR].row = this->data[posA].row;
			result.data[posR].col = this->data[posA].col;
			result.data[posR].value = this->data[posA].value;
			posA++;
			posR++;
		}//else if A��ǰһ��
		else {
			result.data[posR].row = b.data[posB].row;
			result.data[posR].col = b.data[posB].col;
			result.data[posR].value = -b.data[posB].value;
			posB++;
			posR++;
		}//else B��ǰһ��
		result.tu = posR;
	}//while
	return result;
}//operator-

SPMatrix SPMatrix::operator*(const SPMatrix& b){
	SPMatrix result(this->mu, b.nu);
	
	int tuR = 0;
	int posR = 1;
	int valueR = 0;

	for (int rowA = 1; rowA <= this->mu; rowA++) {
		for (int colB = 1; colB <= b.nu; colB++) {
			valueR = 0;
			for (int colA = 1; colA <= nu; colA++) {
				valueR += this->get(rowA, colA) * b.get(colA, colB);
			}//for
			if (tuR != 0) {
				result.data[posR].row = rowA;
				result.data[posR].col = colB;
				result.data[posR].value = valueR;
				posR++;
				tuR++;
			}//if
		}//for colB
	}//for rowA
	result.mu = this->mu;
	result.nu = b.nu;
	result.tu = tuR;
	return result;
}//operator*

SPMatrix::~SPMatrix(){
	//delete[] data;
	delete[] numR;
	delete[] numC;
}