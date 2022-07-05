// 统计个数，再直接计算出P

#include <iostream>
using namespace std;

long long Calculate(long long num, long long target) {
	long long digit = 0, temp = 0;
	while (num > 0) {
		temp = num % 10;  num /= 10;
		if (temp == target)
			digit++;
	}
	
	long long ans = 0;
	while (digit--) {
		ans = ans * 10 + target;
	}
	return ans;
} 

int main() {
	long long A, Da, B, Db;
	A = Da = B = Db = 0;
	cin >> A >> Da >> B >> Db; 
	
	cout << Calculate(A, Da) + Calculate(B, Db);
	return 0;
}
