// ����Ƿ�����ͬ�ĵ绰����
// ����������εĵ绰����
// ʹ��map<char, char>ӳ���ȹ���ͳһ�ĵ绰�����ʽ
// ��ʹ��map<string, int>��������->���ִ�����ӳ��
// �ٶԷ���Ҫ����ַ������뵽vector�����н������ 
 
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void Init(map<char, char>& phoneNum) {
	char number = '2';
	int count = 0;
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		if (count == 3) {
			number++;
			count = 0;
		}
		phoneNum.insert(pair<char, char>(ch, number));
		count++;
	}
	phoneNum['S'] = '7';  phoneNum['V'] = '8';  phoneNum['Y'] = '9';
	phoneNum['Q'] = phoneNum['Z'] = '0';
	return;
}

// ���ܣ�������ת��Ϊ��׼��ʽ 
string Transfer(string& s, map<char, char>& phoneNum) {
	string finalAns = " ";  finalAns.resize(8);  finalAns[3] = '-';
	// ���Ȱ��ַ����е�'-'ȫ����ϴ��
	size_t pos = 0;
	while (1) {
		pos = s.find("-");
		if (pos == s.npos) break;
 		else s.erase(pos, 1);
	} 
	// ��ΰ��ַ����е���ĸȫ��ת��������
	for (unsigned int index = 0; index < s.length(); index++) {
		if (s[index] > '9' || s[index] < '0') {		
			s[index] = phoneNum[s[index]];
		}
		else continue;
	} 
	// ���ת��Ϊ���ַ�������
	for (int index = 0; index <= 2; index++) finalAns[index] = s[index];
	for (int index = 4; index <= 7; index++) finalAns[index] = s[index - 1];
	return finalAns;
}

bool cmp(string first, string second) {
	return first.compare(second) <= 0;
}

int main() {
	int test = 0;  cin >> test;
	map<char, char> phoneNum; // ʵ����ĸ�����ֵ�ӳ�� 
	Init(phoneNum);
	
	string s = " ", result = " ";
	map<string, int> record; // ͳ������Ĵ��� 
	while (test--) {
		cin >> s;
		result = Transfer(s, phoneNum); // ���绰����ת��Ϊ��׼��ʽ
		record[result]++; 
	}
	// ������Ҫ����ַ�������������� 
	vector<string> ans;
	for (map<string, int>::iterator it = record.begin(); it != record.end(); it++) {
		if (it->second >= 2) 
			ans.push_back(it->first);
	}
	// ʵ���ֵ������� 
	sort(ans.begin(), ans.end(), cmp);
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << " " << record[*it] << endl;
	}
	return 0;
}
