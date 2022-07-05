// ��һ����ά���飬ȷ���տ�ʼ��λ�ã���������
// ��������ϵ�������������Ƿ�ֹͣ����1��ʼ���еĻ�������˳��Ϊ
// ����->����->����->���� ѭ��
// �������������Ŀ����ģ��������ѣ�һ���͸���ȫ������ 

#include <iostream>
using namespace std;

const int maxN = 11;
int numMatrix[maxN][maxN];

int main() {
	// ��ʼ�� 
	for (int row = 1; row <= 10; row++) {
		for (int column = 1; column <= 10; column++) {
			numMatrix[row][column] = 0;
		}
	}
	int total = 0;  cin >> total;
	int target = total * total, num = 1;
	int startRow = 0, startColumn = 0;
	if (total % 2 == 0) startRow = startColumn = total / 2;
	else startRow = startColumn = total / 2 + 1;
	// Ҫ������do����while��do + while 
	while (num <= target) {
		// ���� 
		do {
			numMatrix[startRow][startColumn] = num;
			num++;
			startColumn++;
		} while (numMatrix[startRow + 1][startColumn] != 0);
		// ���� 
		do {
			numMatrix[startRow][startColumn] = num;
			num++;
			startRow++;
		} while (numMatrix[startRow][startColumn - 1] != 0);
		// ���� 
		do {
			numMatrix[startRow][startColumn] = num;
			num++;
			startColumn--;
		} while (numMatrix[startRow - 1][startColumn] != 0);
		// ���� 
		do {
			numMatrix[startRow][startColumn] = num;
			num++;
			startRow--;
		} while (numMatrix[startRow][startColumn + 1] != 0);
	}
	for (int row = 1; row <= total; row++) {
		for (int column = 1; column <= total; column++) {
			cout << numMatrix[row][column] << " ";
		}
		cout << endl;
	}
	return 0;
}
