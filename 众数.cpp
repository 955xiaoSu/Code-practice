// ����������Ҫһ�������飬��Ҫ��������������ж�
// ���η�����һ����������жϵ�ʱ������Ҫһ��vector����
// �ж��������������⣬ʹ�ù�ϣ��

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorElement(vector<int>& test) {
	unordered_map<int, int> counts;
	int majority = 0, cnt = 0;
	for (int num : test) {
		++counts[num];
		if (counts[num] > cnt) {
			majority = num;
			cnt = counts[num];
		}
	}
	return majority;
}

int main() {
	vector<int> nums;
	vector<int> ans; // �洢��Ԫ��
	int digit = 0; // ���ڼ�¼ÿ�������ж��ٸ�Ԫ��
	int temp = 0; // ���ڼ�¼ÿһ����ʱԪ��
	while (cin >> digit) {
		if (digit == 0) break; // 0��ζ��������̵Ľ���
		nums.clear(); // ��Ϊ����push_back�ķ�������Ԫ�أ����Բ���resize()������ᵼ���������
		for (int sub = 0; sub < digit; sub++) {
			cin >> temp;
			nums.push_back(temp);
		}
		ans.push_back(majorElement(nums));
	}
	for (int ansNum : ans) cout << ansNum << endl;
	return 0;
}