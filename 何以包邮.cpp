// �Ѽ۸�������飬ÿ���¼۸����֮ǰ�����е��������ٴ�������
// ʹ�� set ��Ϊ���ݽṹ
// �������Ƚϣ����ִ����ٽ�ֱֵ������ѭ��

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num = 0, critical_value = 0;
	cin >> num >> critical_value;
	int tmp = 0, ans = 0; // tmp ��ǰ�鱾�ļ۸�ans ���մ�
	unsigned int len = 0; // len ��ʾ set ���ϵĴ�С 
	vector<int> digit;
	vector<int>::iterator it;
	for (int i = 0; i < num; i++) {
		cin >> tmp;
		len = digit.size();
		digit.push_back(tmp);
		for (unsigned int j = 0; j < len; j++) {
			digit.push_back(tmp + digit[j]);
		}
	}
	sort(digit.begin(), digit.end());
	for (unsigned int i = 0; i < digit.size(); i++) {
		if (digit[i] >= critical_value) {
			ans = digit[i];
			break;
		}
	}
	cout << ans;
	return 0;
} 
 
