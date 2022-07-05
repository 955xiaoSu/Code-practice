// 回溯法构建排列数，模拟真实的多项式相乘 

#include <iostream>
#include <cstring>
using namespace std;

int origin[22], realAns[22], givenAns[22];
int test = 0;

void sour(int nowFloor, int digits, int sum) {
	cout << "nowFloor : " << nowFloor << " digits : " << digits << " sum : " << sum << endl;
	cout << givenAns[0] << " " << givenAns[1] << " " << givenAns[2] << " " << endl;
	if (nowFloor == test) {
		//cout << givenAns[0] << " " << givenAns[1] << " " << givenAns[2] << " " << endl;
		realAns[digits] += sum;
		//cout << "nowFloor : " << nowFloor << " digits : " << digits << " sum : " << sum << endl;
		//cout << givenAns[0] << " " << givenAns[1] << " " << givenAns[2] << " " << endl;
		return;
	}
	sour(nowFloor + 1, digits, sum);
	sour(nowFloor + 1, digits + 1, sum * origin[nowFloor]);
}

int main() {
	while (cin >> test && test) {
		memset(realAns, 0, sizeof(realAns));
		
		for (int index = 0; index < test; index++)	cin >> origin[index];
		for (int index = 0; index < test; index++) cin >> givenAns[index];
		
		cout << "Strat: ";
		cout << givenAns[0] << " " << givenAns[1] << " " << givenAns[2] << " " << endl;
		sour(0, 0, 1);
		bool flag = true;
		for (int index = 0; index < test; index++) {
			if (realAns[index + 1] != givenAns[index]) {
				flag = false;
				break;
			}
		}
		
		if (flag) cout << "Y" << endl;
		else cout << "N" << endl;
	} 
	return 0;
}
