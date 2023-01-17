// 把价格存入数组，每个新价格加上之前数组中的所有数再存入数组
// 使用 set 作为数据结构
// 最后排序比较，发现大于临界值直接跳出循环

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num = 0, critical_value = 0;
	cin >> num >> critical_value;
	int tmp = 0, ans = 0; // tmp 当前书本的价格，ans 最终答案
	unsigned int len = 0; // len 表示 set 集合的大小 
	vector<int> digit;
	vector<int>::iterator it;
	for (int i = 0; i < num; i++) {
		cin >> tmp;
		len = digit.size();
		digit.push_back(tmp);
		for (unsigned int j = 0; j < len; j++) {
			digit.push_back(tmp + digit[j]);
		}
	}
	sort(digit.begin(), digit.end());
	for (unsigned int i = 0; i < digit.size(); i++) {
		if (digit[i] >= critical_value) {
			ans = digit[i];
			break;
		}
	}
	cout << ans;
	return 0;
} 
 
