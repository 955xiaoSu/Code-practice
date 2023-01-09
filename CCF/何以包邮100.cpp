// 0-1背包问题，
// 特殊之处：质量即价值。问能删除的最大价值是多少？

#include <iostream>
using namespace std;
const int MN = 1e5 + 5;

int a[33];
int dp[MN];
int main() {
	int num = 0, critical_value = 0;
	cin >> num >> critical_value;
	int sum = 0; // 总价值
	for (int i = 1; i <= num; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= num; i++) { // 对于每一本书询问是否删除
		for (int j = sum - critical_value; j >= a[i]; j--) {
			dp[j] = max(dp[j], dp[j - a[i]] + a[i]); // 前者为不删该书对应价值，后者为删该书对应价值
		}
	}
	cout << sum - dp[sum - critical_value]; // dp[sum - critical_value] 是能删除的最大价值
	return 0;
}
