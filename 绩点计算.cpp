// 在输入时记录并统计所有所有学分之和，在输入课程分数时，首先实现绩点转化然后直接求出所有学科绩点之和

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
	// 绩点转化并直接得出学分绩点 
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
