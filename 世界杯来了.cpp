#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Team {
	string name;
	int integral; // ���� 
	int margin; // ��ʤ�� 
	int score; // ������ 
	Team() {
		integral = margin = score = 0;
		name = " ";
	}
};

Team* digits;

// ���ܣ��Ա���������������з������� 
void Classified(int first, int second, int firstScore, int secondScore) {
	if (firstScore > secondScore) {
		digits[first].integral += 3;
		digits[first].score += firstScore;
		digits[second].score += secondScore;
		digits[first].margin += firstScore - secondScore;	
		digits[second].margin += secondScore - firstScore;
	}
	
	else if (firstScore == secondScore) {
		digits[first].integral += 1;
		digits[second].integral += 1; 
		digits[first].score += firstScore;
		digits[second].score += secondScore;
	}
	
	else {
		digits[second].integral += 3;
		digits[first].score += firstScore;
		digits[second].score += secondScore;
		digits[first].margin += firstScore - secondScore;	
		digits[second].margin += secondScore - firstScore;
	}
}

// ���ܣ��Խṹ�����鰴�ջ��ֵݼ�����ʤ��ݼ��Լ��������ݼ�������ʽ����
bool cmp(Team first, Team second) {
	if (first.integral != second.integral) {
		return first.integral > second.integral;
	} 
	else if (first.margin != second.margin) return first.margin > second.margin;
	else return first.score > second.score;
}

// ���ܣ�ʵ���ַ������ֵ�������
bool CMP(string first, string second) {
	return first.compare(second) < 0;
} 

// ���ܣ������ִ�stringת��Ϊint 
int TransStrToInt(string s) {
	int result = 0, len = s.length();
	for (int index = 0; index < len; index++) {
		result = result * 10 + s[index] - '0';
	}
	return result;
}

int main() {
	map<string, int> transfer;
	vector<string> ans;
	
	// ʵ���������->�ṹ�������±��ӳ�� 
	int playTeamNum = 0;  cin >> playTeamNum;
	digits = new Team[playTeamNum + 1];
	int index = 1;
	string temp;
	for (int times = 1; times <= playTeamNum; times++) {
		cin >> temp;
		transfer[temp] = index;
		digits[index].name = temp;
		index++;
	} 
	
	string first, second; //first,second�ֱ������֧��ӵ����� 
	int firstScore = 0, secondScore = 0;  // �ֱ������֧��ӵĽ����� 
	string occa; // �ַ���ת��Ϊ���ֵ�ý�� 
	char ch = ' '; // ����Ѱ���������λ�� 
	size_t pos = 0; // ������ȡ�ַ��� 
	for (int times = 1; times <= ((playTeamNum * (playTeamNum - 1)) / 2); times++) { // ��ÿһ�����ݽ��д��� 
		// ���ַ�������ȡ������� 
		cin >> temp;
		ch = '-';
		pos = temp.find(ch);
		first = temp.substr(0, pos);
		second = temp.substr(pos + 1);
		
		// ���ַ�������ȡ�ȷ� 
		cin >> temp;
		ch = ':';
		pos = temp.find(ch);
		occa = temp.substr(0, pos);
		firstScore = TransStrToInt(occa);
		occa = temp.substr(pos + 1);
		secondScore = TransStrToInt(occa);
		
		// �����������еı������ 
		Classified(transfer[first], transfer[second], firstScore, secondScore);
	}
	
	sort(digits + 1, digits + 1 + playTeamNum, cmp); // С�ı߽������� 
	for (int index = 1; index <= (playTeamNum / 2); index++) {
		ans.push_back(digits[index].name);	
	}
	sort(ans.begin(), ans.end(), CMP);
	
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	} 
	return 0;
} 
