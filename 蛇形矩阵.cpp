// ͨ�����������Եõ����ķ�Χ
// ���������˼�룬��������������ĸ���֮��Ϊ��ֵ 
// ÿ����֮���й��ɣ����ĸ�����ʼ���н���

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int piles = 0;  cin >> piles;
	vector<int> proIncrease;
	
	for (int digit = 0; digit <= piles; digit++)  proIncrease.push_back(digit);
	
	int basicNum = 1, temp = 0;
	for (int row = 1; row <= piles; row++) {
		basicNum += proIncrease[row - 1];
		cout << basicNum << " ";
		temp = basicNum;
		for (int column = 1; column <= piles - row; column++) {
			temp += proIncrease[row + column];
			cout << temp << " ";
		}
		cout << endl;
	}
	
	return 0;
} 


