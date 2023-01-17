// ʲôʱ���ò�ַ���
// �Է�Χ�����ݽ��д�������Ҫ�Կռ任ʱ�䣬��ʡʱ���ԭ���ǴӶ���ظ���ֵת��Ϊ���θ�ֵ
// ��Ҫһ��ԭ����Ͳ�����飬������ǰ׺�Ͳ���

#include <iostream>
using namespace std;

const int N = 1e6;
int diff[N], digit[N];
int n = 0;

void add(int left, int right) {
	diff[left] += 1;
	diff[right + 1] -= 1;
}

int main() {
	cin >> n;
	for (int index = 1; index <= n; index++)  cin >> digit[index];
	for (int index = 1; index <= n; index++) {
		if (digit[index] > digit[index - 1]) {
			add(digit[index - 1] + 1, digit[index]);
		}
	}
	int maxn = 0, count = 0;
	for (int num = 1; num < 1e4; num++) {
		count += diff[num];
		maxn = max(count, maxn);
	}
	cout << maxn;
	return 0;
}

