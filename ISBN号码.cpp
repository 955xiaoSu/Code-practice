// 对字符数组进行数学计算
// 比对，如果成功返回 Right，如果失败填上正确的数字
 
#include <iostream>
using namespace std;

int main() {
	char ISBN[14];
	char tmp;
	for (int i = 1; i <= 13; i++) {
		cin >> tmp;
		ISBN[i] = tmp;
	}
	int result = 0;
	result += (ISBN[1] - '0') * 1;
	int product = 2;
	for (int i = 3; i <= 5; i++) {
		result += ISBN[i] * product;
		product++;
	}
	for (int i = 7; i <= 11; i++) {
		result += ISBN[i] * product;
		product++;
	}
	result = result % 11;
	if (result == 10) {
		if (ISBN[13] == 'X') {
			cout << "Right";
		}
		else {
			ISBN[13] = 'X';
			for (int i = 1; i <= 13; i++) {
				cout << ISBN[i];
			}
		}
		return 0;
	}
	if (result == (ISBN[13] - '0')) {
		cout << "Right";
	}
	else {
		ISBN[13] = result + '0';
		for (int i = 1; i <= 13; i++) {
			cout << ISBN[i];
		}
	}
	return 0;
}
