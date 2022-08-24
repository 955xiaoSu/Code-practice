// 最大值直接相加
// 最小值可以比较前一个数，如果跟前一个数一样，那么取0，否则取该数

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
