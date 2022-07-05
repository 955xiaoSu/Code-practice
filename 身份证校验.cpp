// ��һ��vector�洢�𰸣���string���������֤�űȽϷ���
// ��һ��int�����Ȩ�أ���һ��map��У�����Ӧ���� 
// ������͡������ģ�������ݹ������У����

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void Judge(string& s, int weight[], map<int, char>& rule, vector<int>& ans) {
	int sum = 0;
	
	// ��� 
	for (int index = 0; index <= 16; index++) {
		sum += (s[index] - '0') * weight[index];
	}
	
	// ȡģ 
	sum = sum % 11;
	
	// ���ݹ���ó���ȷ��У����
	char checkCode = ' ';
	checkCode = rule[sum];
	
	if (checkCode == s[17])  ans.push_back(1);
	else  ans.push_back(0);
	return;
}

int main() {
	vector<int> ans;
	int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2}; // ��Ӧλ�õ�Ȩ�� 
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
	
	// У�����֤ 
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
