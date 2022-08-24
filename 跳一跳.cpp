// 1直接相加
// 2判断该次是否为第一次 / 该次前次是否为1

#include <iostream>
using namespace std;

int main() {
	int tmp = 0;  cin >> tmp;
	int count = 0;
	if (tmp == 0) {
		cout << count;
		return 0;
	}
	else count = tmp; 					  // 处理第一次，此后的情况可普适
	int lastState = tmp, lastScore = tmp; // 分别记录上次的状态和得分 
	while (cin >> tmp) {
		if (tmp == 0)  break; // 结束条件 
		else if (tmp == 1) {
			count += 1;
			lastState = lastScore = 1;
		}
		else {
			if (lastState == 1) { // 前一次状态为1，本次状态为2 
				count += 2;
				lastState = lastScore = 2;
			}
			else { // 前一次状态为2，本次状态为2 
				count += lastScore + 2;
				lastState = 2;
				lastScore += 2;
			}
		}
	} 
	cout << count;
	return 0;
}
