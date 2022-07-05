#include <iostream>
#include <map>
using namespace std;

int main() {
	map<char, int> counts;
	string s;  cin >> s;
	int len = s.length();
	
	for (char ch = '0'; ch <= '9'; ch++) {
		counts.insert(pair<char, int>(ch, 0)); // 要以pair的形式加入 
	}
	// 统计个数 
	for (int sub = 0; sub < len; sub++) {
		counts[s[sub]]++;		
	}
	
	for (char ch = '0'; ch <= '9'; ch++) {
		if (counts[ch] != 0)
			cout << ch << ":" << counts[ch] << endl;
	}
	return 0;
}
