#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

double average = 0.0;
double Da = 0.0; 

double Function(double num) {
	double result = 0.0;
	result = (num - average) / Da;
	cout << setprecision(16) << result << endl;
}

int main() {
	int test = 0;  cin >> test;
	vector<double> digit;
	double temp = 0.0, sum = 0.0;
	for (int index = 0; index < test; index++) {
		cin >> temp;  digit.push_back(temp);
		sum += temp;
	}
	average = sum / test; // 获取平均数 
	for (int index = 0; index < test; index++) {
		Da += (digit[index] - average) *  (digit[index] - average);
	}
	Da /= test;  Da = sqrt(Da); // 获取标准差 
	//cout << setprecision(16) << Da;
	for (int index = 0; index < test; index++) {
		Function(digit[index]); // 按照所给公式进行输出 
	}
	return 0;
}
