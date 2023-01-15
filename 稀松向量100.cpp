#include <iostream>
#include <map>
using namespace std;

map<int, int> digit1;
map<int, int> digit2;
int main() {
	int len = 0, num1 = 0, num2 = 0;
	cin >> len >> num1 >> num2;
	int index = 0, value = 0;
	for (int i = 1; i <= num1; i++) {
		cin >> index >> value;
		digit1[index] = value;
	}
	for (int i = 1; i <= num2; i++) {
		cin >> index >> value;
		digit2[index] = value;
	}
	map<int, int>::iterator it2;
	long long sum = 0; // ×¢ÒâÒç³ö£¡£¡ 
	for (map<int, int>::iterator it = digit1.begin(); it != digit1.end(); it++) {
		index = it->first;
		value = it->second;
		it2 = digit2.find(index);
		if (it2 != digit2.end()) {
			sum += value * it2->second;
		}
	}
	cout << sum;
	return 0;
}
