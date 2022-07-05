// 位数与整除之间的关系 
// 因为位数很大，必须用字符串处理
// 用一个映射关系处理进制 

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

char CalculateCheckCode(int system, string s, map<char, int> transfer) {
	// 计算各位数之和 
	int sum = 0, len = s.length();
	for (int index = 0; index < len; index++) {
		sum += transfer[s[index]];
	}
	
	// 尝试'0'-'f'的所有可能 
	for (char ch = '0'; ch <= '9'; ch++) {
		if ((sum + transfer[ch]) % (system - 1) == 0)
			return ch;
	}
	for (char ch = 'a'; ch <= 'f'; ch++) {
		if ((sum + transfer[ch]) % (system - 1) == 0)
			return ch;
	}
	
	return '0'; // 这条语句永远不会执行，写出此语句是为了形式的完整性 
}

void Init(map<char, int>& transfer) {
	transfer.insert(pair<char, int>('0', 0));
	transfer.insert(pair<char, int>('1', 1));
	transfer.insert(pair<char, int>('2', 2));
	transfer.insert(pair<char, int>('3', 3));
	transfer.insert(pair<char, int>('4', 4));
	transfer.insert(pair<char, int>('5', 5));
	transfer.insert(pair<char, int>('6', 6));
	transfer.insert(pair<char, int>('7', 7));
	transfer.insert(pair<char, int>('8', 8));
	transfer.insert(pair<char, int>('9', 9));
	transfer.insert(pair<char, int>('a', 10));
	transfer.insert(pair<char, int>('b', 11));
	transfer.insert(pair<char, int>('c', 12));
	transfer.insert(pair<char, int>('d', 13));
	transfer.insert(pair<char, int>('e', 14));
	transfer.insert(pair<char, int>('f', 15));
	return;
}

int main() {
	int test = 0;  cin >> test;
	vector<char> ans;	ans.resize(test, ' ');
	map<char, int> transfer; // 实现从字符->数值的映射 
	Init(transfer);
	
	int system = 0;
	string s = " ";
	char result = ' ';
	while (test--) {
		cin >> system >> s;
		result = CalculateCheckCode(system, s, transfer);
		ans.push_back(result);
	}
	
	for (vector<char>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
} 
