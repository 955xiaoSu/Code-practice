// ���ֱֵ�����
// ��Сֵ���ԱȽ�ǰһ�����������ǰһ����һ������ôȡ0������ȡ����

#include <iostream>
using namespace std;

int main()  {
	int test = 0;	cin >> test;
	int max = 0, min = 0, tmp = 0;
	cin >> tmp;
	max += tmp;	 min += tmp;
	int before = tmp;
	for (int times = 0; times < test - 1; times++) {
		cin >> tmp;	
		max += tmp;
		if (before == tmp)  min += 0;
		else min += tmp;
		before = tmp; 
	}
	cout << max << endl << min;
	return 0;
}
