/*
 *  ͳ��y�������븺���ĸ���
 *  ���ͳ�Ƹ�����һ��Ϊ1����ô���yes���������no
 */

#include <iostream>
using namespace std;

int main() {
	int totalDigit = 0;  cin >> totalDigit;
	int positiveNumCount = 0, negativeNumCount = 0;
	int x = 0, y = 0;
	for (int times = 1; times <= totalDigit; times++) {
		cin >> x >> y;
		if (x > 0) positiveNumCount++;
		else negativeNumCount++;
	}
	if (negativeNumCount == 1 || positiveNumCount == 1 || negativeNumCount == 0 || positiveNumCount == 0) cout << "Yes";
	else cout << "No";
	return 0;
}