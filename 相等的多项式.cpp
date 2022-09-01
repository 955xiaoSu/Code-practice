#include <iostream>
#include <cstring>
using namespace std;

int origin[22], realAns[22], givenAns[22];
int test = 0;

void sour(int nowFloor, int digits, int sum) {
	if (nowFloor == test) {
		realAns[digits] += sum;
		return;
	}
	sour(nowFloor + 1, digits, sum);
	sour(nowFloor + 1, digits + 1, sum * origin[nowFloor]);
}

int main() {
	while (cin >> test && test) {
		memset(realAns, 0, sizeof(realAns));
		for (int index = 0; index < test; index++)  cin >> origin[index];
		for (int index = 0; index < test; index++)  cin >> givenAns[index];
		sour(0, 0, 1);
		bool flag = true;
		for (int index = 0; index < test; index++) {
			if (realAns[index + 1] != givenAns[index]) {
				flag = false;
				break;
			}
		}
		if (flag)  cout << "Y" << endl;
		else  cout << "N" << endl;
	} 
	return 0;
}
