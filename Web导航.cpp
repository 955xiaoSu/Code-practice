// 封装三个操作按序操作即可
#include <string>
#include <stack>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	stack<string> forward, back;
	string operand = " ", now = "http://www.game.org/", url = " ";
	vector<string> ans;
	while (cin >> operand) {
		if (operand == "QUIT") break;
		else if (operand == "VISIT") {
			cin >> url;
			while (!forward.empty()) {
				forward.pop();
			}
			back.push(now);
			now = url;
			ans.push_back(now);
		}
		else if (operand == "BACK") {
			if (!back.empty()) {
				forward.push(now);
				now = back.top();  back.pop();
				ans.push_back(now);
			}
			else ans.push_back("Ignored");
		}
		else if (operand == "FORWARD") {
			if (!forward.empty()) {
				back.push(now);
				now = forward.top();  forward.pop();
				ans.push_back(now);
			}
			else ans.push_back("Ignored");
		}
	}
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
} 
