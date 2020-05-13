#include <iostream>
#include <string>
using namespace std;

int main()
{
	//获取输入的字符串，保存在input中
	string input;
	getline(cin, input);
	int len = input.size();			//字符串长度

	string result = "";
	for (int i = 0; i < len; i++) {
		result += input[i];
		if (input[i] == '#')
			result += " ";
	}

	cout << result << endl;

}