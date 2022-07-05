// 因此自然数n非常大，所以得采用字符串处理
// 逐字符统计和，最后采用vector<string>容器存储答案，反序输出 

#include <vector>
#include <string>
#include <iostream>
using namespace std;


int countSum(string& s) {
	int len = s.length();
	int sum = 0;
	for (int sub = 0; sub < len; sub++) {
		sum += s[sub] - '0';
	}
	return sum;	
}

void outPut(int num) {
	vector<string> ans;
	if (num == 0) {
		cout << "ling"; 
		return;
	}
	else {
		int temp = 0; // temp记录最低位上的数 
		while (num > 0) {
			temp = num % 10;  num /= 10;
			if (temp == 0) ans.push_back("ling");
			else if (temp == 1) ans.push_back("yi");
			else if (temp == 2) ans.push_back("er");
			else if (temp == 3) ans.push_back("san");
			else if (temp == 4) ans.push_back("si");
			else if (temp == 5) ans.push_back("wu");
			else if (temp == 6) ans.push_back("liu");
			else if (temp == 7) ans.push_back("qi");
			else if (temp == 8) ans.push_back("ba");
			else ans.push_back("jiu");
		}
	}
	
	for (vector<string>::reverse_iterator it = ans.rbegin(); it != ans.rend(); it++) {
		cout << *it << " ";
	}
	return;
}

int main() {
	string s;  cin >> s;
	int ans = countSum(s);	
	outPut(ans);
	return 0;
} 
