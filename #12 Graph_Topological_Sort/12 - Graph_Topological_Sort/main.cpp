#include <iostream>
#include <string>
using namespace std;

int main()
{
	//��ȡ������ַ�����������input��
	string input;
	getline(cin, input);
	int len = input.size();			//�ַ�������

	string result = "";
	for (int i = 0; i < len; i++) {
		result += input[i];
		if (input[i] == '#')
			result += " ";
	}

	cout << result << endl;

}