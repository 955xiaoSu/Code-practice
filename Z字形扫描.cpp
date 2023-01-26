// 用 while 循环模拟 Z 字形扫描

#include <iostream>
using namespace std;

const int MAXN = 501;
int digit[MAXN][MAXN] = {0};

int main() {
	// 修改 I/O 操作，提升速度
	// 但这只是 side effect，不是普适的，同时也牺牲了线程安全
	ios::sync_with_stdio(false); cin.tie(0);

	int matrix = 0;  cin >> matrix;
	for (int i = 1; i <= matrix; i++) {
		for (int j = 1; j <= matrix; j++) {
			cin >> digit[i][j];
		}
	}

	int x = 1, y = 1;
	bool flag = false;
	while (x != matrix || y != matrix) {
		if (x <= matrix && y <= matrix) // 保证不输出越界数据
			cout << digit[x][y] << " ";
		
		if (flag) x++, y--;
		else x--, y++;

		// 调整越界位置
		if (x < 1) {
			x = 1;
			flag = !flag;
		}
		if (y < 1) {
			y = 1;
			flag = !flag;
		}
	}
	cout << digit[matrix][matrix];
	return 0;
}
