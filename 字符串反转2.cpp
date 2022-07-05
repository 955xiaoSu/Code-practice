#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

void Reversal(string& s, vector<string>& ans) {
	stringstream sstream;
	stack<string> stk;
	string temp, result;
	
	sstream << s;
	while (sstream >> temp) { // 导出自动忽略空格 
		stk.push(temp);
	}
	
	while (!stk.empty()) {
		result +=  stk.top() + " ";
		stk.pop();
	}
	
	ans.push_back(result);
	return;
}

int main() {
	vector<string> ans;
	
	string s;
	while (getline(cin, s)) {
		Reversal(s, ans);
	}
	
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
} 
