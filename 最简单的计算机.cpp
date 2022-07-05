// ģ������ڴ���Ĵ���֮��Ľ���
// ��vector�洢�������int��ʾ������

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	long long M1 = 0, M2 = 0; // ��ʾ�����ڴ� 
	long long R1 = 0, R2 = 0, R3 = 0; // ��ʾ�����Ĵ��� 
	string s;
	vector<long long> m1, m2;
	while (cin >> M1 >> M2 >> s) {
		R1 = R2 = R3 = 0; // ��ʼ���Ĵ��� 
		int len = s.length();
		char operand = ' ';
		for (int index = 0; index < len; index++) {
			operand = s[index];
			if (operand == 'A') {
				R1 = M1;
			}
			else if (operand == 'B') {
				R2 = M2;
			}
			else if (operand == 'C') {
				M1 = R3;
			}
			else if (operand == 'D') {
				M2 = R3;
			}
			else if (operand == 'E') {
				R3 = R1 + R2;
			}
			else if (operand == 'F') {
				R3 = R1 - R2;
			}
		}
		m1.push_back(M1);  m2.push_back(M2);
	}
	vector<long long>::iterator memory1 = m1.begin();
	vector<long long>::iterator memory2 = m2.begin();
	for (; memory1 != m1.end(); memory1++, memory2++) {
		cout << *memory1 << "," << *memory2 << endl;
	}
	return 0;
} 
 
