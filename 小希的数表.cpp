// 已知数据长度
// 根据简单的加减法可以得出数据
// 先创建临时的数组，然后把答案加入vector中

#include <iostream>
#include <vector>
using namespace std; 

int main() {
	vector<int> len, ans;
	int length = 0;
	while (cin >> length) {
		if (length == 0) break;
		len.push_back(length);
		int* originAns = new int[length * (length - 1) / 2 + 1];
		int* origin = new int[length + 1];
		for (int index = 1; index <= length * (length - 1) / 2; index++) {
			cin >> originAns[index];
		}
		 
		for (int index = 1; index <= length; index++) {
			ans.push_back(origin[index]);
		}
	}
	vector<int>::iterator ANS = ans.begin();
	vector<int>::iterator LEN = len.begin();
	for (; LEN != len.end(); LEN++) {
		for (int times = 1; times <= *LEN; times++, ANS++) {
			cout << *ANS << " ";
		}
		cout << endl;
	}
	return 0;
}
