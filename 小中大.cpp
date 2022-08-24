// 以空间换时间，并交换程序的简洁易读是非常值得的一件事情 
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int test = 0;  cin >> test;
	int* digit = new int[test];
	for (int times = 0; times < test; times++) {
		cin >> digit[times];
	}
	int max = 0, min = 0;
	max = digit[0], min = digit[test - 1];
	if (max < min)  swap(max, min);
	if (test % 2 == 1) {
		cout << max << " " << digit[test / 2] << " " << min;
	}
	else {
		double median = (double)((digit[test / 2 - 1] + digit[test / 2]) / 2.0);
		if (median - (int)median == 0) {
			cout << fixed << setprecision(0) << max << " " << median << " " << min;
		}
		else {
			cout << max << fixed << setprecision(1) << " " << median << " " << setprecision(1) << min;
		}
	}
	return 0;
}
