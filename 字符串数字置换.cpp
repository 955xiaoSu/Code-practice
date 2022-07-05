// ��һ��vector�������ܴ洢��
// ��һ��map��ͳ�����ֵ�ת������

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	vector<char> ans;
	map<char, int> counts;
	string s;  getline(cin, s); // ע����ĿҪ��������һ���ַ��� 
	
	// ��ʼ�� 
	for (char ch = '0'; ch <= '9'; ch++)  counts.insert(pair<char, int>(ch, 0));
	int len = s.length();
	
	// ���ݹ�����ans�����м����ַ� 
	for (int sub = 0; sub < len; sub++) {
		if (s[sub] < '0' || s[sub] > '9') 
			ans.push_back(s[sub]);
		else {
			counts[s[sub]]++;
			if (s[sub] == '0') {
				ans.push_back('(');
				ans.push_back('Z');
				ans.push_back('e');
				ans.push_back('r');
				ans.push_back('o');
				ans.push_back(')');
			}
			else if (s[sub] == '1') {
				ans.push_back('(');
				ans.push_back('O');
				ans.push_back('n');
				ans.push_back('e');
				ans.push_back(')');
			}
			else if (s[sub] == '2') {
				ans.push_back('(');
				ans.push_back('T');
				ans.push_back('w');
				ans.push_back('o');
				ans.push_back(')');
			}
			else if (s[sub] == '3') {
				ans.push_back('(');
				ans.push_back('T');
				ans.push_back('h');
				ans.push_back('r');
				ans.push_back('e');
				ans.push_back('e');
				ans.push_back(')');
			}
			else if (s[sub] == '4') {
				ans.push_back('(');
				ans.push_back('F');
				ans.push_back('o');
				ans.push_back('u');
				ans.push_back('r');
				ans.push_back(')');
			}
			else if (s[sub] == '5') {
				ans.push_back('(');
				ans.push_back('F');
				ans.push_back('i');
				ans.push_back('v');
				ans.push_back('e');
				ans.push_back(')');
			}
			else if (s[sub] == '6') {
				ans.push_back('(');
				ans.push_back('S');
				ans.push_back('i');
				ans.push_back('x');
				ans.push_back(')');
			}
			else if (s[sub] == '7') {
				ans.push_back('(');
				ans.push_back('S');
				ans.push_back('e');
				ans.push_back('v');
				ans.push_back('e');
				ans.push_back('n');				
				ans.push_back(')');
			}
			else if (s[sub] == '8') {
				ans.push_back('(');
				ans.push_back('E');
				ans.push_back('i');
				ans.push_back('g');
				ans.push_back('h');
				ans.push_back('t');
				ans.push_back(')');
			}
			else {
				ans.push_back('(');
				ans.push_back('N');
				ans.push_back('i');
				ans.push_back('n');
				ans.push_back('e');
				ans.push_back(')');
			}
		}
	}
	
	vector<char>::iterator it = ans.begin();
	for (; it != ans.end(); it++) cout << *it;
	cout << endl;
	for (char ch = '0'; ch <= '9'; ch++) {
		cout << counts[ch] << " "; 
	}
	return 0;
}
 
