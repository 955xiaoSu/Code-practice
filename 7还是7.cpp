// �����������ж����ַ��������ж�����
// ��vector<int>�����洢���д�
// �ѵ����ڰ�intת��Ϊstring 

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std; 

string Transfer(stringstream &sstream, string &numString, int num) {
	sstream.clear();  numString.clear();
	sstream << num;
	numString = sstream.str();
	sstream.str("");
	return numString;
}

// �����ò����������const���� 
bool Judge(string s) {
	if (s.find("7") != s.npos) return true;
	else return false;
}

int main() {
	int range = 0;  cin >> range;
	vector<int> ans;	
	bool result = false; // ���ܺ����ж��Ƿ���n�Ľ�� 
	stringstream sstream; 	string numString; // stringstream��һ���ַ����� 
		
	for (int num = 7; num <= range; num++) {
		if (num % 7 == 0) {
			ans.push_back(num);
			continue; 
		}
		
		result = Judge(Transfer(sstream, numString, num));
		if (result) ans.push_back(num);
	}
	
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
