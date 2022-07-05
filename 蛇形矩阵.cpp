// 通过层数，可以得到数的范围
// 层序遍历的思想，层数与输出的数的个数之和为定值 
// 每个数之间有规律，从哪个数开始加有讲究

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


