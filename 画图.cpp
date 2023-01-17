// ¿¿¿¿¿¿¿¿

#include <iostream>
using namespace std;

int digit[101][101] = {0};

int main() {
	int test_num = 0;
	cin >> test_num;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int count = 0; // ¿¿¿¿¿¿¿¿¿
	for (int num = 1; num <= test_num; num++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				if (!digit[i][j]) {
					digit[i][j] = 1; // ¿¿¿¿¿¿¿¿¿ 
					count++;
				}
			} 
		}
	}
	cout << count;
	return 0;
} 
