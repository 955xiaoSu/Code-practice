// ����map<string, int>����ӳ�䣬������β�����г�ȷ����Сֵ
// �ڸ����ķ�Χ�ڱ���
// ������������ۣ�Ψһ��������������������������
// �������뷨�ǣ�������ֻ��ȷ������������
// ʹ��vector<string>�洢��

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

void Init(map<string, int>& weekToInt) {
	weekToInt.insert(pair<string, int>("monday", 1));
	weekToInt.insert(pair<string, int>("tuesday", 2));
	weekToInt.insert(pair<string, int>("wednesday", 3));
	weekToInt.insert(pair<string, int>("thursday", 4));
	weekToInt.insert(pair<string, int>("friday", 5));
	weekToInt.insert(pair<string, int>("saturday", 6));
	weekToInt.insert(pair<string, int>("sunday", 7));
}

string IntToStr(int num) {
	stringstream sstream;
	sstream << num;
	string ans = sstream.str();
	return ans;
}

string Judge(int startWeek, int endWeek, int least, int most) {
	int minimum = 0;
	if (endWeek < startWeek)  minimum = endWeek - startWeek + 8; // һ��Ҫע������ת�� 
	else minimum = endWeek - startWeek + 1;
	
	if (minimum > most) return "impossible";
	
	int maybeAns = minimum;
	while (maybeAns < least)  maybeAns += 7;
	
	if (maybeAns > most) return "impossible";
	else {
		if (maybeAns + 7 <= most) return "many";
		else return IntToStr(maybeAns);
	}
}

int main() {
	int test = 0;  cin >> test;
	int least = 0, most = 0;
	string startWeek = " ", endWeek = " ";
	map<string, int> weekToInt;
	vector<string> ans;
	Init(weekToInt);
	
	while (test--) {
		cin >> startWeek >> endWeek >> least >> most;
		string finalAns = Judge(weekToInt[startWeek], weekToInt[endWeek], least, most);
		ans.push_back(finalAns);
	}
	
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
} 
