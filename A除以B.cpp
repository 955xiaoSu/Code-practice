// 逐字符处理字符串就是了

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s = " "; char divisor = '0';
	cin >> s >> divisor;
	vector<char> result; char remainder = ' ';
	
	int len = s.length(); 
	int index = 0;
	while (index < len - 1) {
		s[index + 1] += ((s[index] - '0') % (divisor - '0')) * 10;
		if (s[index] >= divisor) {
			result.push_back((s[index] - '0') / (divisor - '0') + '0');
		}
		else result.push_back('0');
		index++;
	}
	result.push_back((s[len - 1] - '0') / (divisor - '0') + '0');
	remainder = (s[index] - '0') % (divisor - '0') + '0';
	
	vector<char>::iterator it = result.begin();
	if (result[0] == '0' && result.size() >= 2) result.erase(result.begin());
	for (; it != result.end(); it++) {
		cout << *it;
	}
	cout << " " << remainder;
	return 0;
} 
