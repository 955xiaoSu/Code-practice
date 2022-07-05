// �ƵĹ���ʵ����ͳ��ÿ�����ֵĸ���
// ��Ϊ���ֹ�ģ��ֻ��ʹ���ַ���������mapͳ�����ݣ���vector�����洢��string 
// ����������ʱ�����ȵ��ж�λ������������۸��ֶ�Ӧ���

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void AddUp(map<int, int>& counts, string& s) {
	int len = s.length(), temp = 0;

	for (int sub = 0; sub < len; sub++) {
		temp = s[sub] - '0';
		counts[temp]++;
	}
	return;
}

inline int CalculateDigits(int num) {
	int result = 0;
	while (num > 0) {
		num /= 10;
		result++;
	}
	return result;
}

void ClassfiedDiscussion(int num, vector<vector<int>>& ansNum, vector<string>& ansStr, map<int, int>& counts, int& sub) {
	int digits = CalculateDigits(num); // �����ж�����������λ��
	bool haveJoined = false; // ���Ƿ��Ѽ�������������ж�
	int basicNum = num % 10; // �������������һλ��������������ж�

	// �Է���һ�������ƽ�������
	if (digits <= 4) {
		int finalAns = 0; // ��������������λ�������������һλ���֣��������������������ʲô

		for (int posNum = basicNum + 1; posNum <= 9; posNum++) {
			if (counts[posNum] >= digits) { // ���ѹ���Է����Ƶ������㹻����ɼ��뵽����������

				for (int times = 1; times <= digits; times++) {
					finalAns = finalAns * 10 + basicNum;
				}
				//ansNum[sub].push_back(finalAns);
				if (!haveJoined) ansStr.push_back("YES");
				haveJoined = true;
			}
		}

		if (!haveJoined) ansStr.push_back("NO");
		return;
	}

	// �Է��������Ƶ��������
	else {
		if (basicNum == 9) {
			ansStr.push_back("NO");
			return;
		}
		for (int start = basicNum - 3; start <= 5; start++) {
			if (counts[start] == 0) continue;

			for (int find = start + 1; find <= 9 && find <= start + 4; find++) {
				if (counts[find] == 0) break;
				else if (find == start + 4) {
					ansNum[sub].push_back(start * 10000 + (start + 1) * 1000 + (start + 2) * 100 + (start + 3) * 10 + (start + 4));
					ansStr.push_back("YES");
					haveJoined = true;
				}
				else continue;
			}
		}

		if (!haveJoined) ansStr.push_back("NO");
		return;
	}
}

int main() {
	string s = " ";  cin >> s;
	map<int, int> counts;

	AddUp(counts, s); // ͳ��ÿ�����ֳ��ֵĴ���

	int num = 0, sub = 0; // sub�Ǵ�������±�
	vector<vector<int>> ansNum; // ͳ�����п������
	vector<string> ansStr; // ��¼�Ƿ���ѹ���Է�����
	while (cin >> num) {
		ClassfiedDiscussion(num, ansNum, ansStr, counts, sub); // ���з�������
		sub++;
	}

	vector<int>::iterator it;
	vector<vector<int>>::iterator iter = ansNum.begin();
	vector<int> vec_tmp;
	for (int row = 0; row < sub; row++, iter++) {
		cout << ansStr[row] << " ";
		vec_tmp = *iter;
		for (it = vec_tmp.begin(); it != vec_tmp.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
	return 0;
}