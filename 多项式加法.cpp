// ��һ������������� �ڶ���������ϵ����ֱ��ͳ����ͽ���
// map�����ǰ���洢�ģ����Ҿ���pair�����ʣ�����ͨ��first��second�����ʼ�ֵ�� 

#include <map>
#include <iostream>
using namespace std;

int main() {
	map<int, int> ans;	
	int frequence = 0, coefficent = 0;

	// ͳ����� 
	while (cin >> frequence >> coefficent) {
		if (frequence == 0 && coefficent == 0) break;
		ans[frequence] += coefficent;
	}
	while (cin >> frequence >> coefficent) {
		if (frequence == 0 && coefficent == 0) break;
		ans[frequence] += coefficent;
	}
	
	// ������� 
	for (map<int, int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); it++) {
		if (it->second == 0) continue; // ����ϵ����Ϊ0��������� 
		cout << it->first << " " << it->second;
		cout << endl;
	}
	return 0;
} 
 
