// ���ݺ��������Чʱ�䣬�ж����мƻ��Ƿ�����Чʱ����
// ��Чʱ��q + k��q + k + c
// �ж���q + k <= t && q + k + c > t   �ȼ���   t - c < q + k <= t
// ��ʱ->�Կռ任ʱ�䣬��ʱ��ת����һ�����䷶Χ�ڵ��ж� 
#include <iostream>
#include <string.h>
using namespace std;

const int maxN = 4e5; 
int section[maxN + 1]; // ����һ�����мƻ�����Ч���� 

void Insert(int left, int right) { // �����������Ч��ֵ��һ�ִӵ㵽�ߵ����죬��ѧ�����
	section[left] += 1;
	section[right + 1] -= 1;
}

int main() {
	int plan = 0, query = 0, needTime = 0; // plan���мƻ����� query��ѯ������needtime����������ʱ��
	cin >> plan >> query >> needTime;
	memset(section, 0, sizeof(section));
	
	int left = 0, right = 0;   // �ֱ������������ 
	int start = 0, expiry = 0; // startǰ��ʱ�̣�expiry������ʱ�� 
	for (int index = 0; index < plan; index++) {
		cin >> start >> expiry;
		left = start - expiry + 1;	 // ���ݲ���ʽ���ұգ�������Ч���������+1 
		left = left >= 1 ? left : 1; // ��ֹ�������С������ʵ����� 
		right = start;
		Insert(left, right);
	}
	
	// ǰ׺�Ӻͣ�ͳ�Ƴ������е�ÿһ��ʱ�̶�Ӧ�Ŀɳ��мƻ��� 
	for (int index = 1; index <= maxN; index++) {
		section[index] = section[index - 1] + section[index];
	} 
	
	int tmp = 0; // ��¼��ʱ��ѯʱ�� 
	for (int times = 0; times < query; times++) {
		cin >> tmp;
		cout << section[tmp + needTime] << endl;
	}
	return 0;
}
 
