// �����0��1��ֱ�����
// �����2������������+�������
// �����3�����Դ�ʱ��ʱ 
#include <iostream>
using namespace std;

int main() {
	int red = 0, yellow = 0, green = 0;
	cin >> red >> yellow >> green;
	int test = 0;  cin >> test;
	int id = 0, seconds = 0, totalCount = 0; // id�Ǳ�ʶ�����������seconds����ͨ����ǰ��·���ѷ�ʱ�䣬totalCount������ѧ���ܺ�ʱ 
	for (int times = 0; times < test; times++) {
		cin >> id >> seconds;
		if (id == 2)  totalCount += seconds + red;
		else if (id != 3)	totalCount += seconds; 
	} 
	cout << totalCount;
	return 0;
}
