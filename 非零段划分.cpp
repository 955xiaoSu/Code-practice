// 什么时候用差分法？
// 对范围内数据进行处理并且需要以空间换时间，节省时间的原因是从多次重复赋值转变为单次赋值
// 需要一个原数组和差分数组，并进行前缀和操作

#include <iostream>
using namespace std;

const int N = 1e6;
int diff[N], digit[N];
int n = 0;

void add(int left, int right) {
	diff[left] += 1;
	diff[right + 1] -= 1;
}

int main() {
	cin >> n;
	for (int index = 1; index <= n; index++)  cin >> digit[index];
	for (int index = 1; index <= n; index++) {
		if (digit[index] > digit[index - 1]) {
			add(digit[index - 1] + 1, digit[index]);
		}
	}
	int maxn = 0, count = 0;
	for (int num = 1; num < 1e4; num++) {
		count += diff[num];
		maxn = max(count, maxn);
	}
	cout << maxn;
	return 0;
}

