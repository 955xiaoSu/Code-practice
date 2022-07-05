// ��̬�滮 
// ��������һά���飬�ҵ���ӦԪ�����±�֮��Ĺ�ϵ 
#include <iostream>
using namespace std;

int floor;
int* digits;
int* path;

int dp(int nowSite, int nowFloor, int originSite) {
	if (nowFloor == floor) {
		return digits[nowSite];
	}
	int left = digits[nowSite] + dp(nowSite + nowFloor, nowFloor + 1, nowSite); // ���� 
	int right = digits[nowSite] + dp(nowSite + nowFloor + 1, nowFloor + 1, nowSite); // ���� 
	path[nowSite] = left > right ? nowSite + nowFloor : nowSite + nowFloor + 1; // ����·�� 
	return max(left, right);
}

int main() {
	cin >> floor;
	int nodes = (floor * (floor + 1)) / 2;
	digits = new int[nodes];
	path = new int[nodes];
	for (int index = 0; index < nodes; index++)  cin >> digits[index];
	
	cout << dp(0, 1, 0) << endl;
	int index = 0;
	int nowFloor = 1;
	while (nowFloor <= floor) {
		cout << digits[index] << " ";
		index = path[index];
		nowFloor++;
	}
	return 0;
}
