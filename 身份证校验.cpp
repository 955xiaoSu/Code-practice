// 用一个vector存储答案，用string来处理身份证号比较方便
// 用一个int数组存权重，用一个map存校验码对应规则 
// 首先求和、其次算模，最后根据规则查找校验码

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void Judge(string& s, int* weight, map<int, char>& rule, vector<int>& ans) {
	int sum = 0;
	for (int index = 0; index <= 16; index++) { // 求和 
		sum += (s[index] - '0') * weight[index];
	}
	sum = sum % 11; // 取模 
	// 根据规则得出正确的校验码，并校验 
	char checkCode = ' ';
	checkCode = rule[sum];
	if (checkCode == s[17])  ans.push_back(1);
	else  ans.push_back(0);
	return;
}

void InitRule(map<int, char>& rule) {
	int module[11];
	for (int index = 0; index <= 10; index++)  module[index] = index;
	char checkCode[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
	for (int times = 0; times <= 10; times++) {
		rule.insert(pair<int, char>(module[times], checkCode[times]));
	} 
	return;
}

int main() {
	vector<int> ans;
	int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2}; // 对应位置的权重 
	map<int, char> rule;
	InitRule(rule); // 对校验规则进行初始化

	// 校验身份证 
	string s;
	while (cin >> s) {
		if (s == "-1") break;
		Judge(s, weight, rule, ans);	
	}
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
} 
