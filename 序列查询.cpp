// ע��sum(A)�Ǽ����±�֮��
// ��ʵ���Ǻ�һ������ǰһ�����ٳ������±�
// �����˷ѿռ�洢 

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
