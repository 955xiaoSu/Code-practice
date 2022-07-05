// ��Ҫͳ����ӵľ�ʤ�������Լ�����
// �����������򣬷��س�ǰ�����Ľ��
// ��Ҫһ������������vector�洢�������
// Ūһ���ַ�����Ӧ���ݽṹ��ת��������index��¼ 

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Team {
	string name;
	int integral;
	int margin;
	Team() {
		integral = margin = 0;
		name = " ";
	}
};

Team* digits;

void Classified(int first, int second, int firstScore, int secondScore) {
	if (firstScore > secondScore) {
		digits[first].integral += 3;
		digits[first].margin += firstScore - secondScore;	
		digits[second].margin += secondScore - firstScore;
	}
	
	else if (firstScore == secondScore) {
		digits[first].integral += 1;
		digits[second].integral += 1; 
	}
	
	else {
		digits[second].integral += 3;
		digits[second].margin += secondScore - firstScore;
		digits[first].margin += firstScore - secondScore;
	}
}

bool cmp(Team first, Team second) {
	if (first.integral != second.integral) {
		return first.integral > second.integral;
	} 
	else return first.margin > second.margin;
}

int main() {
	int test = 0;  cin >> test;
	map<string, int> transfer;
	vector<string> ans;
	
	string first, second, temp; // temp����������"vs."����ַ��� 
	int firstScore = 0, secondScore = 0;
	int index = 1;
	while (test--) {
		index = 1;  transfer.clear();
		digits = new Team[5];
		
		for (int times = 1; times <= 12; times++) { // ��ÿһ�����ݽ��д��� 
			// ʵ��ÿһ�����ݵĶ��룬���ҽ���������ӳ����±� 
			cin >> first; 
			if (transfer[first] == 0) {
				transfer[first] = index;
				digits[transfer[first]].name = first;
				index++;
			}
			
			
			cin >> firstScore >> temp >> secondScore >> second;
			if (transfer[second] == 0) {
				transfer[second] = index;
				digits[transfer[second]].name = second;
				index++;
			}
			
			// �Ա���������������з������� 
			Classified(transfer[first], transfer[second], firstScore, secondScore);
		}
		
		sort(digits + 1, digits + 5, cmp); // С�ı߽������� 
		//cout << endl;
		//for (int i = 1; i <= 4; i++) {
		//	cout << digits[i].name << " " << digits[i].integral << " " << digits[i].margin << endl;
		//}
		//cout << endl;
		ans.push_back(digits[1].name);
		ans.push_back(digits[2].name);
		//cout << digits[1].name << " " << digits[1].integral << " " << digits[1].margin << endl;
		//cout << digits[2].name << " " << digits[2].integral << " " << digits[2].margin << endl;

	}
	
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it;
		it++;
		cout << " " << *it << endl;
	} 
	return 0;
} 
