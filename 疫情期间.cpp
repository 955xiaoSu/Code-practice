#include <iostream>
using namespace std;

int main() {
	int days = 0;  cin >> days;
	int* plan = new int[days + 1];
	for (int index = 1; index <= days; index++)  cin >> plan[index];
	int dp[101][3]; // dp[i][j]�����i����j�������Ϣ������
	// ��ʼ�� 
	for (int row = 0; row <= 100; row++) {
		for (int column = 0; column <= 2; column++) {
			dp[row][column] = 101;
		}
	}
	// 0������Ϣ��1��������2�����������������������һ����ʼ�� 
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
		if (plan[index] == 1) { // �����index��ѡ��������ôǰһ��ֻ��ѡ��ѡ���������Ϣ 
			dp[index][1] = min(dp[index - 1][2], dp[index - 1][0]);
		} else if (plan[index] == 2) { // �����index��ѡ������ôǰһ��ֻ��ѡ����������Ϣ 
			dp[index][2] = min(dp[index - 1][0], dp[index - 1][1]);
		} else if (plan[index] == 3){ // �������ȿ���ѡ�����ֿ���ѡ����Ļ�����ôȫ�����еݹ�
			dp[index][1] = min(dp[index - 1][2], dp[index - 1][0]);
 			dp[index][2] = min(dp[index - 1][0], dp[index - 1][1]);			
		}
		dp[index][0] = 1 + min(dp[index - 1][0], min(dp[index - 1][1], dp[index - 1][2]));
	}
	cout << min(dp[days][0], min(dp[days][1], dp[days][2]));
	return 0;
}
