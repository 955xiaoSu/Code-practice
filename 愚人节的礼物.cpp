// ͳ��λ��B������'('���������������')'��ô��Ӧ��������
// ��vector�����洢�𰸣���string�Ĵ����������ж� 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> ans;

void CalculateMinimum(string &s) {
	int count1 = 0, count2 = 0; // count1��¼'('������count2��¼')'����
	int sub = 0; // sub��¼�±�
	
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
