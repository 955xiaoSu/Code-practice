// ����ÿһ��ֱ��Ӧ����һ����ʽ
// ��һ�������ѹ�ʽ�ж���װ����
// ��ÿ��ֱ�߸������϶�A��B�������֮���໥��ͻ��AB�ж��г�ͻ����ֹ�����ж�
// �ýṹ��洢�����Ϣ 
// �ý����״̬��ˣ��������0Ϊ��ȷ������Ϊ����
 
#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int x, y;
	char state;
	Node() {
		x = y = 0;
		state = ' ';
	}
};

int main() {
	int nodeNum = 0, lineNum = 0; 
	cin >> nodeNum >> lineNum;
	Node* digits = new Node[nodeNum];
	for (int times = 0; times < nodeNum; times++) {
		cin >> digits[times].x >> digits[times].y >> digits[times].state;
	}
	vector<string> ans(lineNum, "Yes"); // Ԥ���϶�����ֱ�߶����㻮������ 
	
	int parameter1 = 0, parameter2 = 0, parameter3 = 0; // �ֱ����ֱ�ߵ��������� 
	for (int times = 0; times < lineNum; times++) {
		cin >> parameter1 >> parameter2 >> parameter3;
		// ���õ���������ж���ͬ���͵����Judge������Ϊ������֮Ϊ�� 
		for (int index = 0; index < nodeNum; index++) {
			char kindFirst = 'a', kindSecond = 'b';
			int result = parameter1 + parameter2 * digits[index].x + parameter3 * digits[index].y;
			if (result > 0) {
				kindFirst = digits[index].state;
			}
			else  kindSecond = digits[index].state;
			if (kindFirst == kindSecond) {
				ans[times] = "No";
				break;
			}
		}
	}
	
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	} 
	return 0;
}
