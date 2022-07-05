#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

bool isVaild(string& s) {
	unordered_map<char, char> pairs = {
		{')', '('},
		{'<', '>'},
		{'[', ']'},
		{'{', '}'}
	};
	
	stack<char> stk;
	int len = s.length();
	for (int sub = 0; sub < len; sub++) {
		if (pairs.count(s[sub])) {
			if (stk.empty() || stk.top() != pairs[s[sub]])
				return false;
			else stk.pop();
		}
		stk.push(s[sub]);
	}
	return stk.empty();
}

int main() {
	vector<string> ans;
	int test = 0;  cin >> test;
	string s = " ";
	bool judge = false;
	
	for (int times = 1; times <= test; times++) {
		cin >> s;
		judge = isVaild(s);
		if (judge) ans.push_back("Yes");
		else ans.push_back("No");
	}
	
	for (int sub = 0; sub < test; sub++) {
		cout << ans[sub] << endl;
	}
	return 0;
}
