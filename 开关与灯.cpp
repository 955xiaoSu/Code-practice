// 判定是否有一个灯的作用可以被其它灯替代
// 因为这是一个全局性的问题，所以必须得存储
// 有且仅有一盏决定了遍历的方法是非常非常低效的
// 利用map存储点亮该灯的开关数，只能逐个遍历了

#include <iostream>
#include <map>
using namespace std;

int main() {
	map<char, int> counts; // 统计每个灯可以被多少个开关开启
	int row = 0, column = 0;  cin >> row >> column;
	char light[row][column]; // 当数字没有被空格间隔开的时候，可以考虑用char数组 
	
	for (int sub1 = 0; sub1 < row; sub1++) {
		for (int sub2 = 0; sub2 < column; sub2++) {
			cin >> light[sub1][sub2];
			if (light[sub1][sub2] == '1') {
				counts[sub2]++;
			}
		}
		cout << endl;
	}
	
	bool judge = true; // 判断开关是否可被忽略 
	for (int sub1 = 0; sub1 < row; sub1++) {
		judge = true;
		for (int sub2 = 0; sub2 < column; sub2++) {
			if (light[sub1][sub2] == '1') {
				if (counts[sub2] == 1) { 
					judge = false;
					break; // 此开关作用不可能被替代
				}
				else continue;
			}
			else continue;
		}
		if (judge) {
			cout << "YES";
			return 0;
		}
	}
	
	cout << "NO";
	return 0;
} 
