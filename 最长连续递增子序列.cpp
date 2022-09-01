#include <iostream>
using namespace std;

int main() {
	int total = 0;  cin >> total;
	int* origin = new int[total + 1]; // 开辟数组记录元素
	for (int sub = 1; sub <= total; sub++)  {
		cin >> origin[sub];
	}
	int count = 1, temp = 0, maximum = 0; 
	for (int sub = 1; sub < total; sub++) { // 依次遍历数组中的每个元素，记录从该元素开始的最长递增子序列长度
		count = 1; temp = origin[sub];
		for (int sub2 = sub + 1; sub2 <= total; sub2++) {
			if (origin[sub2] > temp) {
				temp = origin[sub2];
				count++;
			}
			else break;
		}
		if (count > maximum) maximum = count;
 	}
	cout << maximum;
	return 0; 
}
