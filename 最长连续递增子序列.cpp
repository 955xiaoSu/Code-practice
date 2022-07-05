#include <iostream>
using namespace std;

int main() {
	int total = 0;  cin >> total;
	int* origin = new int[total + 1];
	for (int sub = 1; sub <= total; sub++)  {
		cin >> origin[sub];
	}
	// 对rank进行初始化
	int count = 1, temp = 0, maximum = 0;
	for (int sub = 1; sub < total; sub++) {
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
