// 用一个vector存储答案，用string来处理身份证号比较方便
// 用一个int数组存权重，用一个map存校验码对应规则 
// 首先求和、其次算模，最后根据规则查找校验码

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void Judge(string& s, int weight[], map<int, char>& rule, vector<int>& ans) {
	int sum = 0;
	
	// 求和 
	for (int index = 0; index <= 16; index++) {
		sum += (s[index] - '0') * weight[index];
	}
	
	// 取模 
	sum = sum % 11;
	
	// 根据规则得出正确的校验码
	char checkCode = ' ';
	checkCode = rule[sum];
	
	if (checkCode == s[17])  ans.push_back(1);
	else  ans.push_back(0);
	return;
}

int main() {
	vector<int> ans;
	int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2}; // 对应位置的权重 
	map<int, char> rule;
	rule.insert(pair<int, char>(0, '1'));
	rule.insert(pair<int, char>(1, '0'));
	rule.insert(pair<int, char>(2, 'X'));
	rule.insert(pair<int, char>(3, '9'));
	rule.insert(pair<int, char>(4, '8'));
	rule.insert(pair<int, char>(5, '7'));
	rule.insert(pair<int, char>(6, '6'));
	rule.insert(pair<int, char>(7, '5'));
	rule.insert(pair<int, char>(8, '4'));
	rule.insert(pair<int, char>(9, '3'));
	rule.insert(pair<int, char>(10, '2'));
	
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
