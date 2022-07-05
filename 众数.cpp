// 分析：我需要一个答案数组，需要对输入结束进行判断
// 分治法：对一个数组进行判断的时候我需要一个vector容器
// 判定众数：计数问题，使用哈希表

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorElement(vector<int>& test) {
	unordered_map<int, int> counts;
	int majority = 0, cnt = 0;
	for (int num : test) {
		++counts[num];
		if (counts[num] > cnt) {
			majority = num;
			cnt = counts[num];
		}
	}
	return majority;
}

int main() {
	vector<int> nums;
	vector<int> ans; // 存储答案元素
	int digit = 0; // 用于记录每个数组有多少个元素
	int temp = 0; // 用于记录每一个临时元素
	while (cin >> digit) {
		if (digit == 0) break; // 0意味着输入过程的结束
		nums.clear(); // 因为是用push_back的方法输入元素，所以不用resize()，否则会导致输入错误
		for (int sub = 0; sub < digit; sub++) {
			cin >> temp;
			nums.push_back(temp);
		}
		ans.push_back(majorElement(nums));
	}
	for (int ansNum : ans) cout << ansNum << endl;
	return 0;
}