// ������ʱ��¼��ͳ����������ѧ��֮�ͣ�������γ̷���ʱ������ʵ�ּ���ת��Ȼ��ֱ���������ѧ�Ƽ���֮��

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int test = 0;  cin >> test;
	int* credit = new int[test];
	int sumCredit = 0;
	
	for (int sub = 0; sub < test; sub++) {
		cin >> credit[sub];
		sumCredit += credit[sub];
	}
	
	double transfer = 0.0, sumGPA = 0.0;
	int score = 0;
	// ����ת����ֱ�ӵó�ѧ�ּ��� 
	for (int sub = 0; sub < test; sub++) {
		cin >> score;
		if (score >= 90 && score <= 100) transfer = 4.0;
		else if (score >= 85) transfer = 3.7;
		else if (score >= 82) transfer = 3.3;
		else if (score >= 78) transfer = 3.0;
		else if (score >= 75) transfer = 2.7;
		else if (score >= 72) transfer = 2.3;
		else if (score >= 68) transfer = 2.0;
		else if (score >= 64) transfer = 1.5;
		else if (score >= 60) transfer = 1.0;
		else transfer = 0.0;
		
		sumGPA += transfer * credit[sub];
	}
	
	cout << fixed << setprecision(2) << (sumGPA / sumCredit);
	return 0;
} 
