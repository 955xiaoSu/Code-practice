// 用一个vector存储数据，首先计算平均值，其次计算平方和，最后除以数列个数

#include <iostream>
#include <vector>
using namespace std;

int main() {
	double counts = 0;
	vector<int> ans;
	vector<double> temp;
	
	while (cin >> counts) {
		if (counts == 0)  break;
		
		// 读入数据 
		double sum = 0.0, occa = 0.0;
		temp.clear(); // 记得每次使用之前得清空 
		for (int times = 1; times <= counts; times++) {
			cin >> occa;  temp.push_back(occa);
			sum += occa;  
		}
		
		double average = sum / counts; // 求平均数
		
		double quadraticSum = 0.0; // 求平方和 
		for (int index = 0; index < counts; index++) {
			quadraticSum += (temp[index] - average) * (temp[index] - average);
		}
		
		ans.push_back((int)(quadraticSum / counts));
	}
	
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
} 
