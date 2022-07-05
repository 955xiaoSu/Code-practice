// 如果输入的是"\n"，结束输入，计算一个数所有的约数和，并重复利用这个数

#include <vector>
#include <iostream>
using namespace std;

int productSum(int num) {
	int count = 0;
	for (int i = 1; i <= num / 2; i++) {
		if (num % i == 0) 
			count += i;
	}
	return count;
}

int main() {
	int A = 0, B = 0;
	vector<string> ans;  ans.clear();
	
	while (cin >> A >>B){
		if (productSum(A) == B && productSum(B) == A) {
			ans.push_back("YES");
		}
		else ans.push_back("NO");
	} 
	
	vector<string>::iterator it = ans.begin();
	for (; it != ans.end(); it++) cout << *it << endl;
	return 0;
}
 
