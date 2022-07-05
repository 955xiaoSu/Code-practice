// 程序法 

#include <iostream>
using namespace std;

struct Work {
	int start;
	int end;
	Work() {
		start = end = 0;
	}
};
int main() {
	int test = 0, P1 = 0, P2 = 0, P3 = 0, T1 = 0, T2 = 0;
	cin >> test >> P1 >> P2 >> P3 >> T1 >> T2;
	
	Work* record = new Work[test];
 	int totalConsume = 0;
 	
 	// 计算使用时耗能 
	for (int sub = 0; sub < test; sub++) {
		cin >> record[sub].start >> record[sub].end;
		totalConsume += P1 * (record[sub].end - record[sub].start);
	}
	if (test == 1) {
		cout << totalConsume;
		return 0;
	}
	// 计算待机时耗能 
	int timeGap = 0;
	for (int sub = 1; sub < test; sub++) {
		timeGap = record[sub].start - record[sub - 1].end;
		if (timeGap > T1 + T2) totalConsume += T1 * P1 + T2 * P2 + (timeGap - T1 -T2) * P3; // 间隔时间能达到睡眠模式
		else if (timeGap > T1) totalConsume += T1 * P1 + (timeGap - T1) * P2; // 间隔时间能达到保护程序 
		else totalConsume += timeGap * P1; 
	}
	
	cout << totalConsume;
	return 0;
}
