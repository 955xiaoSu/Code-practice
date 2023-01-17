// 开辟大数组，第一遍存数据
// 第二遍比对第一遍的数据，求和 

#include <iostream>
using namespace std;
const int MAX = 5e5 + 1; 

int index_a[MAX] = {0}; // 存放 a 的索引值 
int value_a[MAX] = {0}; // 存放 a 对应的 value 
int index_b[MAX] = {0}; // 存放 b 的索引值 
int value_b[MAX] = {0}; // 存放 b 对应的 value 
int main() {
	int len = 0, num1 = 0, num2 = 0;
	cin >> len >> num1 >> num2;
	int tmp_index = 0, tmp_value = 0;
	for (int i = 1; i <= num1; i++) {
		cin >> tmp_index >> tmp_value;
		index_a[i] = tmp_index;
		value_a[i] = tmp_value;
	}
	for (int i = 1; i <= num2; i++) {
		cin >> tmp_index >> tmp_value;
		index_b[i] = tmp_index;
		value_b[i] = tmp_value;
	}
	long long sum = 0; // 注意溢出！ 
	int ref_index_a = 1, ref_index_b = 1; // ref_index 指向 a 存储的索引 
	while (ref_index_a <= num1 && ref_index_b <= num2) {
		if (index_a[ref_index_a] < index_b[ref_index_b]) ref_index_a++;
		else if (index_a[ref_index_a] == index_b[ref_index_b]) {
			sum += value_a[ref_index_a] * value_b[ref_index_b];
			ref_index_a++;
			ref_index_b++;
		}
		else ref_index_b++;
	}
	cout << sum;
	return 0;
}
