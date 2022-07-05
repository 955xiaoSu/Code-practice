#include <iostream>
using namespace std;

int main() {
	int days = 0;  cin >> days;
	int* plan = new int[days + 1];
	for (int index = 1; index <= days; index++)  cin >> plan[index];
	int dp[101][3]; // dp[i][j]代表第i天做j这件事休息的天数
	// 初始化 
	for (int row = 0; row <= 100; row++) {
		for (int column = 0; column <= 2; column++) {
			dp[row][column] = 101;
		}
	}
	// 0代表休息，1代表竞赛，2代表健身，对首天做的事情进行一个初始化 
	if (plan[1] == 1) {
		dp[1][1] = 0;
	} else if (plan[1] == 2) {
		dp[1][2] = 0;
	} else if (plan[1] == 3){
		dp[1][1] = 0;
		dp[1][2] = 0;
	} 
	dp[1][0] = 1;
	
	for (int index = 2; index <= days; index++) {
		if (plan[index] == 1) { // 如果第index天选择竞赛，那么前一天只能选择选择健身或者休息 
			dp[index][1] = min(dp[index - 1][2], dp[index - 1][0]);
		} else if (plan[index] == 2) { // 如果第index天选择健身，那么前一天只能选择竞赛或者休息 
			dp[index][2] = min(dp[index - 1][0], dp[index - 1][1]);
		} else if (plan[index] == 3){ // 如果该天既可以选择竞赛又可以选择健身的话，那么全部进行递归
			dp[index][1] = min(dp[index - 1][2], dp[index - 1][0]);
 			dp[index][2] = min(dp[index - 1][0], dp[index - 1][1]);			
		}
		dp[index][0] = 1 + min(dp[index - 1][0], min(dp[index - 1][1], dp[index - 1][2]));
	}
	cout << min(dp[days][0], min(dp[days][1], dp[days][2]));
	return 0;
}
