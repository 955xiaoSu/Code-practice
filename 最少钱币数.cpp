#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 100000

int main() {
	int dp[2500];  //dp[i] Ϊ�յ�iԪǮ����Ҫ����СǮ�� 
	int mark[2500];
	int target;
	while (cin >> target && target) {
		for (int i = 0; i < 2500; i++) dp[i] = maxn;
		memset(mark, 0, sizeof(mark)); //��ʼ��dp����ͱ�����飬���������Ϊ����������ֵ=��ǰ������� 

		int kinds;	 cin >> kinds;
		int* money = new int[kinds];
		for (int i = 0; i < kinds; i++) cin >> money[i];
		sort(money, &money[kinds]);  //�ȶ�����Ÿ���
		for (int i = 0; i < kinds; i++) {
			dp[money[i]] = 1;
			mark[money[i]] = 1;   //������ֵ���Ȼ����dp������ֱ���������ǣ����ǵ�ֵ�Ѿ��̶�Ϊ1�ˣ�
		}

		if (target < money[0]) {
			cout << "Impossible" << '\n';  //���С����С��ֵ  ���ܶһ�
			continue;
		}
		for (int i = money[0]; i <= target; i++) {  //����С��ֵ��ʼ���� 
			if (!mark[i]) {
				vector<int> v;
				for (int k = 0; k < kinds; k++) {
					if (money[k] < i) {
						v.push_back(dp[i - money[k]] + 1);  //����dp[i]���ܴ��ĸ�ǰ���dp����
														 //�����п��ܼ���vector
					}
					else break;
				}
				sort(v.begin(), v.end());    //�����п������ҵ�ʹ��dp[i]��С������
				dp[i] = v[0];
				v.clear();
			}
		}
		if (dp[target] >= 100000) cout << "Impossible" << '\n';    //�ɲ����ܵ�·������
		else cout << dp[target] << '\n';
	}
}
