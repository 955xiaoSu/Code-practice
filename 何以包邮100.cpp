// 0-1�������⣬
// ����֮������������ֵ������ɾ��������ֵ�Ƕ��٣�

#include <iostream>
using namespace std;
const int MN = 1e5 + 5;

int a[33];
int dp[MN];
int main() {
	int num = 0, critical_value = 0;
	cin >> num >> critical_value;
	int sum = 0; // �ܼ�ֵ
	for (int i = 1; i <= num; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= num; i++) { // ����ÿһ����ѯ���Ƿ�ɾ��
		for (int j = sum - critical_value; j >= a[i]; j--) {
			dp[j] = max(dp[j], dp[j - a[i]] + a[i]); // ǰ��Ϊ��ɾ�����Ӧ��ֵ������Ϊɾ�����Ӧ��ֵ
		}
	}
	cout << sum - dp[sum - critical_value]; // dp[sum - critical_value] ����ɾ��������ֵ
	return 0;
}
