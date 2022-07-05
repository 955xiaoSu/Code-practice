// 统计位于B的左侧的'('个数，如果出现了')'那么相应个数减减
// 用vector容器存储答案，用string的处理方法进行判断 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> ans;

void CalculateMinimum(string &s) {
	int count1 = 0, count2 = 0; // count1记录'('个数，count2记录')'个数
	int sub = 0; // sub记录下标
	
	while (s[sub] != 'B') {
		if (s[sub] == '(') count1++;
		else count2++;
		sub++;
	} 
	
	ans.push_back(count1 - count2);
	return;
}

int main() {
	string s;
	
	while (cin >> s) {
		CalculateMinimum(s);		
	}
	
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
