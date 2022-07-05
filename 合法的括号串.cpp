#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

bool isVaild(string& s) {
	if (s.length() % 2 != 0 || s.length() == 0) return false;
	unordered_map<char, char> pairs = {
		{'>', '<'},
		{']', '['},
		{'}', '{'},
		{')', '('}
	};
	stack<char> stk;

	for (char ch : s) {
		if (pairs.count(ch)) { // count()方法就是查找map中有没有这样的键值对
			if (stk.empty() || stk.top() != pairs[ch]) {
				return false;
			}
			stk.pop();
		}
		else stk.push(ch);
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