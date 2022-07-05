// 用一个二维数组，确定刚开始的位置，结束条件
// 用依赖关系决定基本操作是否停止，从1开始所有的基本操作顺序为
// 向右->向下->向左->向上 循环
// 困扰我两天的题目，娘的，不过则已，一过就给你全部过掉 

#include <iostream>
using namespace std;

const int maxN = 11;
int numMatrix[maxN][maxN];

int main() {
	// 初始化 
	for (int row = 1; row <= 10; row++) {
		for (int column = 1; column <= 10; column++) {
			numMatrix[row][column] = 0;
		}
	}
	int total = 0;  cin >> total;
	int target = total * total, num = 1;
	int startRow = 0, startColumn = 0;
	if (total % 2 == 0) startRow = startColumn = total / 2;
	else startRow = startColumn = total / 2 + 1;
	// 要充分理解do……while是do + while 
	while (num <= target) {
		// 向右 
		do {
			numMatrix[startRow][startColumn] = num;
			num++;
			startColumn++;
		} while (numMatrix[startRow + 1][startColumn] != 0);
		// 向下 
		do {
			numMatrix[startRow][startColumn] = num;
			num++;
			startRow++;
		} while (numMatrix[startRow][startColumn - 1] != 0);
		// 向左 
		do {
			numMatrix[startRow][startColumn] = num;
			num++;
			startColumn--;
		} while (numMatrix[startRow - 1][startColumn] != 0);
		// 向上 
		do {
			numMatrix[startRow][startColumn] = num;
			num++;
			startRow--;
		} while (numMatrix[startRow][startColumn + 1] != 0);
	}
	for (int row = 1; row <= total; row++) {
		for (int column = 1; column <= total; column++) {
			cout << numMatrix[row][column] << " ";
		}
		cout << endl;
	}
	return 0;
}
