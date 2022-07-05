#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverseWords(string s) { // ���ÿ���ָ�뷴ת�ַ���
	int slow = 0, quick = 1;
	int len = s.length();
	int temp = 0;
	while (quick < len) {
		while (s[quick] != ' ' && quick < len)  quick++; // �ж�һ�����ʵ�λ��
		temp = quick;   quick--;
		while (slow <= quick) {
			swap(s[slow], s[quick]);
			slow++;
			quick--;
		}
		quick = slow = temp + 1;
	}
	return s;
}

int main() {
	int totalTest = 0;  cin >> totalTest;
	string s = " ", ans = "";
	vector<string> ansString;
	for (int times = 1; times <= totalTest + 1; times++) {
		getline(cin, s);
		ans = reverseWords(s);
		ansString.push_back(ans);
	}
	for (string temp : ansString)
		cout << temp << endl;
	return 0;
}