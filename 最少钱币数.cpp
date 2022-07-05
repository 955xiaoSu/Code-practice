#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 100000

int main() {
	int dp[2500];  //dp[i] 为凑到i元钱所需要的最小钱数 
	int mark[2500];
	int target;
	while (cin >> target && target) {
		for (int i = 0; i < 2500; i++) dp[i] = maxn;
		memset(mark, 0, sizeof(mark)); //初始化dp数组和标记数组，标记数组是为了跳过【面值=当前金额】的情况 

		int kinds;	 cin >> kinds;
		int* money = new int[kinds];
		for (int i = 0; i < kinds; i++) cin >> money[i];
		sort(money, &money[kinds]);  //先对面额排个序
		for (int i = 0; i < kinds; i++) {
			dp[money[i]] = 1;
			mark[money[i]] = 1;   //标记面额值，等会儿在dp过程中直接跳过他们（他们的值已经固定为1了）
		}

		if (target < money[0]) {
			cout << "Impossible" << '\n';  //如果小于最小面值  不能兑换
			continue;
		}
		for (int i = money[0]; i <= target; i++) {  //从最小面值开始遍历 
			if (!mark[i]) {
				vector<int> v;
				for (int k = 0; k < kinds; k++) {
					if (money[k] < i) {
						v.push_back(dp[i - money[k]] + 1);  //看看dp[i]可能从哪个前面的dp而来
														 //把所有可能加入vector
					}
					else break;
				}
				sort(v.begin(), v.end());    //在所有可能中找到使得dp[i]最小的那种
				dp[i] = v[0];
				v.clear();
			}
		}
		if (dp[target] >= 100000) cout << "Impossible" << '\n';    //由不可能的路径而来
		else cout << dp[target] << '\n';
	}
}
