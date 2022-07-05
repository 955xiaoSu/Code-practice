// 第一次数代表次数， 第二个数代表系数，直接统计求和结束
// map本身是按序存储的，并且具有pair的性质，可以通过first、second来访问键值对 

#include <map>
#include <iostream>
using namespace std;

int main() {
	map<int, int> ans;	
	int frequence = 0, coefficent = 0;

	// 统计求和 
	while (cin >> frequence >> coefficent) {
		if (frequence == 0 && coefficent == 0) break;
		ans[frequence] += coefficent;
	}
	while (cin >> frequence >> coefficent) {
		if (frequence == 0 && coefficent == 0) break;
		ans[frequence] += coefficent;
	}
	
	// 逆序输出 
	for (map<int, int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); it++) {
		if (it->second == 0) continue; // 考虑系数和为0的特殊情况 
		cout << it->first << " " << it->second;
		cout << endl;
	}
	return 0;
} 
 
