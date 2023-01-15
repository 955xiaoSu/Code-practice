// ʹ�����鱩��ģ��ƽ���ϵĵ� 
// ע���������������ʱ��ʹ�����飬ʹ�������� 
#include <iostream>
using namespace std;

int screen[2560][1440] = {0};
int index[11][4] = {0};

int judgeAndAssign(const int x, const int y) {
	int ans = screen[x][y];
	if (ans == 0) return 0;
	for (int j = index[ans][0]; j <= index[ans][2]; j++) { // ��Ӧ������Ч����������¸�ֵ
														   // ʹ����㴰���������䴰������Ӧ 
		for (int k = index[ans][1]; k <= index[ans][3]; k++) {
			screen[j][k] = ans;  
		}
	}
	return ans;
}

int main() {
	int num_window = 0, num_test = 0;
	cin >> num_window >> num_test;
	for (int i = 1; i <= num_window; i++) {
		cin >> index[i][0] >> index[i][1] >> index[i][2] >> index[i][3];
		for (int j = index[i][0]; j <= index[i][2]; j++) {
			for (int k = index[i][1]; k <= index[i][3]; k++) {
				screen[j][k] = i; // ����������ֵ��ƽ���ϵ����� 
			}
		}
	}
	int x = 0, y = 0, answer = 0;
	for (int i = 1; i <= num_test; i++) {
		cin >> x >> y;
		answer = judgeAndAssign(x, y);
		if (answer == 0) cout << "IGNORED" << endl;
		else cout << answer << endl;
	}
	return 0;
} 
