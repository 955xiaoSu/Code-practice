#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int test = 0;
	string s;
	vector<int> answer;
	while (cin >> test) {
		if (test == 0) break;
		cin >> s;
		string rev_s = s;
		reverse(rev_s.begin(), rev_s.end());
		if (s == rev_s){
			answer.push_back(0);
			continue;
		}
		string now = ""; int count = 0;
		for (int index = (int)rev_s.length() - 1; index >= 0; index--){
			now = rev_s[index] + now; count++; // 加入最后一个字符 
			string ss = s + now;
			string rev_ss = ss;
			reverse(rev_ss.begin(), rev_ss.end());
			// cout<<"i="<<i<<", ss="<<ss<<", ss_rev="<<rev_ss<<endl;
			if (ss == rev_ss){ // 再次判断两个字符串是否为回文串 
				answer.push_back(count);
				break;
			}
		}
	}
	for (vector<int>::iterator it = answer.begin(); it != answer.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
