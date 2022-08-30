// һ��Ҫ��д�߲��� 
#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int people = 0, continuity = 0, times = 0;  					 // people���������� continuity�ж�����������ʱ�̣�times����ʱ����                      
	int  leftColumn = 0, leftRow = 0, rightColumn = 0, rightRow = 0; // ���վ������������������ 
	cin >> people >> continuity >> times >> leftColumn >> leftRow >> rightColumn >> rightRow;
	
	int* passCount = new int [people + 1];            // passCount������Ⱥͳ�ƣ�
	int* lingerCount = new int [people + 1];          // lingerCount������Ⱥͳ�� 
	memset(passCount, 0, sizeof(int) * (people + 1)); // ʹ��memsetֻ�ܳ�ʼ��Ϊ0 / -1�����ҳ�ʼ����С������sizeof(pointer)������ᵼ��ֻ��ʼ��һ�����ڴ� 
	memset(lingerCount, 0, sizeof(int) * (people + 1));
	
	int tmpColumn = 0, tmpRow = 0, tmpCount = 0; // tmpColumn��tmpRow��ʱ����ͳ�ƣ�tmpCountͳ��ĳ�������ڷ��վ���������� 
	for (int person = 1; person <= people; person++) {
		tmpCount = 0;
		for (int time = 1; time <= times; time++) {
			cin >> tmpColumn >> tmpRow;
			if (tmpColumn < leftColumn || tmpColumn > rightColumn)  { // �޳������겻���ϵ���� 
				tmpCount = 0;
				continue;
			}
			else if (tmpRow < leftRow || tmpRow > rightRow)  { // �޳������겻���ϵ���� 
				tmpCount = 0;
				continue;
			}
			else { // �ж�Ϊ������Ⱥ 
				tmpCount++;
				passCount[person] = 1;
				if (tmpCount >= continuity) { // ���������������������times�����ж�Ϊ������Ⱥ 
					lingerCount[person] = 1;
				}
			}
		}
	}
	
	int resultPass = 0, resultLinger = 0;
	for (int index = 1; index <= people; index++) {
		resultPass += passCount[index];
		resultLinger += lingerCount[index];
	}
	delete[] passCount;
	delete[] lingerCount;
	cout << resultPass << endl << resultLinger;
	return 0;
}
