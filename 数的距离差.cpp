// 用struct存储数据，存储过程中找出最大最小值，计算每个元素的距离差，采用冒泡排序
 
#include <iostream>
#include <cmath>
using namespace std;

struct Data {
	int num;
	int distance;
	Data() {
		num = distance = 0;
	}
};

int main() {
	int test = 0; cin >> test;
	Data* digits = new Data[test];
	
	cin >>digits[0].num;
	int max = digits[0].num, min = digits[0].num;
	
	// 存储数据并找出最值 
	for (int sub = 1; sub < test; sub++) {
		cin >> digits[sub].num;
		if (digits[sub].num > max) max = digits[sub].num;
		if (digits[sub].num < min) min = digits[sub].num;
	}
	
	// 计算距离差 
	for (int sub = 0; sub < test; sub++) {
		digits[sub].distance = abs(abs(digits[sub].num - max) - abs(digits[sub].num - min));
	}
	
	// 对距离差进行排序
	for (int sub = 0; sub < test - 1; sub++) {
		for (int sub2 = sub + 1; sub2 < test; sub2++) {
			if (digits[sub].distance > digits[sub2].distance) {
				Data temp = digits[sub];
				digits[sub] = digits[sub2];
				digits[sub2] = temp;
			}
			else if (digits[sub].distance == digits[sub2].distance && digits[sub].num > digits[sub2].num) {
				Data temp = digits[sub];
				digits[sub] = digits[sub2];
				digits[sub2] = temp;
			}
		}
	} 
	
	cout << digits[0].num;
	return 0;
} 
