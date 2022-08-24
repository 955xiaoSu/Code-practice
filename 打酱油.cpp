#include <iostream>
using namespace std;

int main() {
	int money = 0;  cin >> money;
	int count = money / 10;
	int send1 = count / 5 * 2;
	int send2 = (count % 5) / 3;
	cout << count + send1 + send2;
	return 0;
}
