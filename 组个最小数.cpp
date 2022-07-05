// 不需要存储，只需要用map记录每个数字出现的次数，按照从小到大的顺序排列
// 对0进行特殊对待，将答案记录到vector<int>容器当中

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	vector<int> ans;
	map<int, int> counts;
	int num = 0;
	
	// 记录每个数字出现的次数 
	while (cin >> num) {
		counts[num]++;
	}
	
	// 首先找到最小的非0数字放在答案数组的首位 
	for (int digit = 1; digit <= 9; digit++) {
		if (counts[digit] != 0) {
			counts[digit]--;
			ans.push_back(digit);
			break;
		}
	}
	
	//  按从小到大的顺序将每个数字放入到答案数组当中
	for (int digit = 0; digit <= 9; digit++) {
		while (counts[digit] != 0) {
			ans.push_back(digit);
			counts[digit]--;
		}
	} 
	
	// 人还是喜欢理性，不然为什么要设计vector.end()这样的东西呢 
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it;
	}
	return 0;
}
