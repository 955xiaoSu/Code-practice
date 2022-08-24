// 注意sum(A)是计算下标之和
// 其实就是后一个数减前一个数再乘以其下标
// 不用浪费空间存储 

#include <iostream>
using namespace std;

int main() {
	int goodsNum = 0, max = 0;
	cin >> goodsNum >> max;
	int price = 0, sumA = 0, beforePrice = 0;
	for (int times = 0; times < goodsNum; times++) {
		cin >> price;
		sumA += (price - beforePrice)* times;
		beforePrice = price;
	}
	sumA += (max - beforePrice) * goodsNum;
	cout << sumA;
	return 0; 
} 
