// �����ֵ����������ʤ������һ�ֶ�ʤ���Ľ׶�
// �����vector��һ����¼�ȷ������������һ����¼�������������һ����¼�ȷ��������ֵ÷֣�
// һ����¼���������ֵ÷֣�һ����¼����������������

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<char> firstPenalty, secondPenalty;
	vector<int> firstScore, secondScore;
	vector<int> penaltyFrequency;
	
	int times = 0;  string s = " ";
	int hostIntegral = 0, guestIntegral = 0;
	bool isHost = true;
	while (cin >> times) {
		if (times == 0) break;
		
		isHost = true;
		hostIntegral = guestIntegral = 0;
		
		for (int degree = 1; degree <= times; degree++) {
			// ����Ա���ֹ��� 
			while (cin >> s) {
			if (s == "good" || s == "no")
				break;
			}
			// �Խ����������д��� 
			if (s == "good") {
				// ���ȵ���Ľ�����д��� 
				if (isHost) {
					firstPenalty.push_back('O');
					isHost = false;
					hostIntegral++;
				}
				// �Ժ����Ľ�����д��� 
				else {
					secondPenalty.push_back('O');
					isHost = true;
					guestIntegral++;
				}
			}
			// �Բ������������д��� 
			else {
				cin >> s; // ������good��������
				// ���ȵ���Ĳ�����������д��� 
				if (isHost) {
					firstPenalty.push_back('X');
					isHost = false;
				}
				// �Ժ����Ĳ�����������д��� 
				else {
					secondPenalty.push_back('X');
					isHost = true;
				}
			} 
		}
			
		// ��ÿһ�ֵ��ܵ÷ֽ��м�¼ 
		firstScore.push_back(hostIntegral);
		secondScore.push_back(guestIntegral);	
		
		// ��˫���������������д��� 
		if (times % 2 == 0) {
			penaltyFrequency.push_back(times / 2); 
		}
		else {
			penaltyFrequency.push_back(times / 2 + 1);	
			// ����������ʹ������������ĿҪ�������һ��Ӧ�����һ��'-'��ĩβ 
			secondPenalty.push_back('-');
		}
	}
	
	vector<char>::iterator first = firstPenalty.begin();
	vector<char>::iterator second = secondPenalty.begin();
	vector<int>::iterator scoreF = firstScore.begin();
	vector<int>::iterator scoreS = secondScore.begin();
	for (vector<int>::iterator it = penaltyFrequency.begin(); it != penaltyFrequency.end(); it++) {
		for (int frequency = 1; frequency <= *it; frequency++) {
			cout << frequency << " ";
		}
		cout << "Score" << endl;
		
		for (int times = 1; times <= *it; times++, first++) {
			cout << *first << " ";
		} 
		cout << *scoreF << endl;  scoreF++;
		
		for (int times = 1; times <= *it; times++, second++) {
			cout << *second << " ";
		} 
		cout << *scoreS << endl;  scoreS++;
	}
	return 0;
} 
