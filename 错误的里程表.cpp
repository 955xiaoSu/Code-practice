#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int test = 0; cin >> test;
	
	vector<long long> ans;
	long long num = 0, transfer = 0;
	int temp = 0;
	while (test--) {
		cin >> num;
		transfer = 0;
		for (int product = 0; num > 0; product++) {
			temp = num % 10;
			if (temp > 3 && temp < 8)  temp -= 1;
			if (temp == 9) temp -= 2;
			transfer += temp * pow(8, product);
			num /= 10;
		}
		ans.push_back(transfer);
	}
	for (vector<long long>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
