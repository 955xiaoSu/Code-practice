// �ж��Ƿ���һ���Ƶ����ÿ��Ա����������
// ��Ϊ����һ��ȫ���Ե����⣬���Ա���ô洢
// ���ҽ���һյ�����˱����ķ����Ƿǳ��ǳ���Ч��
// ����map�洢�����õƵĿ�������ֻ�����������

#include <iostream>
#include <map>
using namespace std;

int main() {
	map<char, int> counts; // ͳ��ÿ���ƿ��Ա����ٸ����ؿ���
	int row = 0, column = 0;  cin >> row >> column;
	char light[row][column]; // ������û�б��ո�������ʱ�򣬿��Կ�����char���� 
	
	for (int sub1 = 0; sub1 < row; sub1++) {
		for (int sub2 = 0; sub2 < column; sub2++) {
			cin >> light[sub1][sub2];
			if (light[sub1][sub2] == '1') {
				counts[sub2]++;
			}
		}
		cout << endl;
	}
	
	bool judge = true; // �жϿ����Ƿ�ɱ����� 
	for (int sub1 = 0; sub1 < row; sub1++) {
		judge = true;
		for (int sub2 = 0; sub2 < column; sub2++) {
			if (light[sub1][sub2] == '1') {
				if (counts[sub2] == 1) { 
					judge = false;
					break; // �˿������ò����ܱ����
				}
				else continue;
			}
			else continue;
		}
		if (judge) {
			cout << "YES";
			return 0;
		}
	}
	
	cout << "NO";
	return 0;
} 
