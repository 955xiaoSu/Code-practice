// ��̬�滮 
// ���������벻������ֵ�����һ���� 


#include <iostream>
using namespace std;

int main() {
	int total = 0;  cin >> total;
	int* digits = new int[total];
	int* intercept = new int[total]; // �洢��Ӧ�±�����صĵ�����
	// ��ʼ���ǳ���Ҫ 
	for (int index = 0; index < total; index++)  cin >> digits[index];
	int temp = 1, height = 0;
	for (int i = 0; i < total - 1; i++) {
		temp = 1; height = digits[i];
		for (int j = i + 1; j < total; j++) {
			if (height >= digits[j]) {
				temp++;
				height = digits[j];
			}
		}
		intercept[i] = temp;
	}
	intercept[total - 1] = 1;
	
	for (int subPlane = 0; subPlane < total - 1; subPlane++) {
		height = digits[subPlane];
		for (int subIntercept = subPlane + 1; subIntercept < total; subIntercept++) {
			if (height < digits[subIntercept]) {
				continue;
			}
			else {
				// ѡ�񲻴���ߴ�����֮�����������+1
				intercept[subPlane] = max(intercept[subPlane], intercept[subIntercept] + 1);
			}
		}
	}
	int maximum = 0;
	for (int index = 0; index < total; index++) {
		if (intercept[index] > maximum) maximum = intercept[index];
	}
	cout << maximum;
	return 0;
}
