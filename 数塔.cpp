// 动态规划 
// 巧妙利用一维数组，找到对应元素与下标之间的关系 
#include <iostream>
using namespace std;

int floor;
int* digits;
int* path;

int dp(int nowSite, int nowFloor, int originSite) {
	if (nowFloor == floor) {
		return digits[nowSite];
	}
	int left = digits[nowSite] + dp(nowSite + nowFloor, nowFloor + 1, nowSite); // 往左 
	int right = digits[nowSite] + dp(nowSite + nowFloor + 1, nowFloor + 1, nowSite); // 往右 
	path[nowSite] = left > right ? nowSite + nowFloor : nowSite + nowFloor + 1; // 保存路径 
	return max(left, right);
}

int main() {
	cin >> floor;
	int nodes = (floor * (floor + 1)) / 2;
	digits = new int[nodes];
	path = new int[nodes];
	for (int index = 0; index < nodes; index++)  cin >> digits[index];
	
	cout << dp(0, 1, 0) << endl;
	int index = 0;
	int nowFloor = 1;
	while (nowFloor <= floor) {
		cout << digits[index] << " ";
		index = path[index];
		nowFloor++;
	}
	return 0;
}
