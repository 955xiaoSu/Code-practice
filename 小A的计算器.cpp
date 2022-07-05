// 两个26进制相加，就是实现普通的加法 

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

string Plus(string& s1, string& s2) {
	string result;
	int len1 = s1.length(), len2 = s2.length();
	char temp = ' ';  int next = 0;
	stack<char> stk;
	
	if (len1 >= len2) {
		while (len2 >= 1) {
			temp = s1[--len1] + s2[--len2] - 'a' + next;
			next = 0;
			if (temp > 'z') {
				next++;
				temp -= 26;
			}
			stk.push(temp);
		}
		while (len1 >= 1) {
			temp = s1[--len1];
			stk.push(temp);
		}
		
		while (!stk.empty()) {
			result += stk.top();
			stk.pop();
		}
	}
	
	else {
		while (len1 >= 1) {
			temp = s1[--len1] + s2[--len2] - 'a' + next;
			next = 0;
			if (temp > 'z') {
				next++;
				temp -= 26;
			}
			stk.push(temp);
		}
		while (len2 >= 1) {
			temp = s2[--len2];
			stk.push(temp);
		}
		
		while (!stk.empty()) {
			result += stk.top();
			stk.pop();
		}
	}
	
	return result;
}

int main() {
	int test = 0;  cin >> test;
	vector<string> ans;
	
	string s1 = " ", s2 = " ";
	string result = " ";
	while (test--) {
		cin >> s1 >> s2;
		result = Plus(s1, s2);
		ans.push_back(result); 
	}
	
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
