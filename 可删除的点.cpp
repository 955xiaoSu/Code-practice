/*
 *  统计y轴正数与负数的个数
 *  如果统计个数有一个为1，那么输出yes，否则输出no
 */

#include <iostream>
using namespace std;

int main() {
	int totalDigit = 0;  cin >> totalDigit;
	int positiveNumCount = 0, negativeNumCount = 0;
	int x = 0, y = 0;
	for (int times = 1; times <= totalDigit; times++) {
		cin >> x >> y;
		if (x > 0) positiveNumCount++;
		else negativeNumCount++;
	}
	if (negativeNumCount == 1 || positiveNumCount == 1 || negativeNumCount == 0 || positiveNumCount == 0) cout << "Yes";
	else cout << "No";
	return 0;
}