// 用string接收输入，用vector容器存储根据规则变换后的字符串

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Transfer(string& s, vector<string>& ans) {
	int len = s.length();
	for (int index = 0; index < len; index++) {
		if (s[index] < 'A' || s[index] > 'Z') continue;
		else {
			if (s[index] < 'F') {
				s[index] = s[index] + 21;
			}
			else s[index] = s[index] - 5;
		}
	}
	ans.push_back(s);
	return;
}

int main() {
	vector<string> ans;
	string s;
	
	while (getline(cin, s)) {
		if (s == "ENDOFINPUT") break;
		getline(cin, s);
		Transfer(s, ans);
		getline(cin, s);
	}
	
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
