// �ж���ֵ�Ƿ�Ϊ֮ǰ����ֵ

#include <iostream>
#include <map>
using namespace std;

int main() {
	int variable = 0, state = 0;
	cin >> variable >> state;
	int left = 0, right = 0, count = 0;
	map<int, int> occurBefore;
	for (int vari = 1; vari <= variable; vari++) {
		occurBefore.insert(pair<int, int>(vari, 0)); // ��ʼ���ܱ���ܶ����벻���Ĵ��� 
	}
	for (int times = 0; times < state; times++) {
		cin >> left >> right;
		if ((right != 0) && (occurBefore[right] == 0 ))  {
			count++;		
		}
		occurBefore[left] = 1;
	}
	cout << count;
	return 0;
} 
