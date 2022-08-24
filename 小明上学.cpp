// 如果是0或1，直接相加
// 如果是2，看到的秒数+红灯秒数
// 如果是3，忽略此时记时 
#include <iostream>
using namespace std;

int main() {
	int red = 0, yellow = 0, green = 0;
	cin >> red >> yellow >> green;
	int test = 0;  cin >> test;
	int id = 0, seconds = 0, totalCount = 0; // id是标识遇到的情况，seconds代表通过当前道路花费发时间，totalCount代表上学的总耗时 
	for (int times = 0; times < test; times++) {
		cin >> id >> seconds;
		if (id == 2)  totalCount += seconds + red;
		else if (id != 3)	totalCount += seconds; 
	} 
	cout << totalCount;
	return 0;
}
