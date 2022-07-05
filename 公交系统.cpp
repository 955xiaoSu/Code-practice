// 计算出过程中的峰值，用最大容量相减结束战斗
// 没那么简单，还需要关注最少的人数，求出一个区间范围才是答案 
// 还要考虑特殊情况，把公交车挤炸了 
// 所以还是提醒我不可飘飘然，每一题都要认真对待 

#include <iostream>
using namespace std;

int main() {
	int numStations = 0, maxLoad = 0;
	cin >> numStations >> maxLoad;
	
	int peak = 0, minimum = 0, temp = 0, occa = 0; // peak记录峰值，minimum计算最少需要的人数，temp记录变化量 
	for (int times = 1; times <= numStations; times++) {
		cin >> occa;
		temp += occa;
		if (temp > peak) peak = temp;
		if (temp < minimum) minimum = temp;
	}
	if (minimum < -maxLoad || peak > maxLoad) cout << 0;
	else cout << (maxLoad - peak) - (-minimum) + 1;
	return 0;
} 
