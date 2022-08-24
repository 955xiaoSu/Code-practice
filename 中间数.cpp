// 用vector自动排序，中间的数是唯一可能的答案
// 用正反两个迭代器求出有多少比它大，有多少比它小

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int test = 0;	cin >> test;
	vector<int> num;
	int tmp = 0;
	for (int index = 0; index < test; index++) {
		cin >> tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	int target = num[test / 2];
	int largeCount = 0, smallCount = 0;
	for (vector<int>::iterator it = num.begin(); (*it) != target; it++) {
		largeCount++;
	}
	for (vector<int>::iterator it = num.end() - 1; (*it) != target; it--) {
		smallCount++;
	}
	if (largeCount == smallCount)  cout << target;
	else cout << "-1";
	return 0;
}
