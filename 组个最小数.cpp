// ����Ҫ�洢��ֻ��Ҫ��map��¼ÿ�����ֳ��ֵĴ��������մ�С�����˳������
// ��0��������Դ������𰸼�¼��vector<int>��������

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	vector<int> ans;
	map<int, int> counts;
	int num = 0;
	
	// ��¼ÿ�����ֳ��ֵĴ��� 
	while (cin >> num) {
		counts[num]++;
	}
	
	// �����ҵ���С�ķ�0���ַ��ڴ��������λ 
	for (int digit = 1; digit <= 9; digit++) {
		if (counts[digit] != 0) {
			counts[digit]--;
			ans.push_back(digit);
			break;
		}
	}
	
	//  ����С�����˳��ÿ�����ַ��뵽�����鵱��
	for (int digit = 0; digit <= 9; digit++) {
		while (counts[digit] != 0) {
			ans.push_back(digit);
			counts[digit]--;
		}
	} 
	
	// �˻���ϲ�����ԣ���ȻΪʲôҪ���vector.end()�����Ķ����� 
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it;
	}
	return 0;
}
