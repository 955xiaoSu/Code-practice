// 1ֱ�����
// 2�жϸô��Ƿ�Ϊ��һ�� / �ô�ǰ���Ƿ�Ϊ1

#include <iostream>
using namespace std;

int main() {
	int tmp = 0;  cin >> tmp;
	int count = 0;
	if (tmp == 0) {
		cout << count;
		return 0;
	}
	else count = tmp; 					  // �����һ�Σ��˺�����������
	int lastState = tmp, lastScore = tmp; // �ֱ��¼�ϴε�״̬�͵÷� 
	while (cin >> tmp) {
		if (tmp == 0)  break; // �������� 
		else if (tmp == 1) {
			count += 1;
			lastState = lastScore = 1;
		}
		else {
			if (lastState == 1) { // ǰһ��״̬Ϊ1������״̬Ϊ2 
				count += 2;
				lastState = lastScore = 2;
			}
			else { // ǰһ��״̬Ϊ2������״̬Ϊ2 
				count += lastScore + 2;
				lastState = 2;
				lastScore += 2;
			}
		}
	} 
	cout << count;
	return 0;
}
