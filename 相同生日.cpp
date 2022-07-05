// ֱ�Ӵ���������ַ���
// ��map��Ӧ�±꣬��һ���ṹ�����飬����������������
// ������stringΨһ��ʾ��ѧ����һ��vector

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	string birthday;
	vector<string> id;
	Student() {
		birthday = " ";
		id.clear();
	}
};

int StrToInt(string s) {
	int result = 0;
	for (unsigned int index = 0; index < s.length(); index++) {
		result = result * 10 + s[index] - '0';
	}
	return result;
}

bool cmp(Student first, Student second) {
	int firstMonth = 0, secondMonth = 0, firstDay = 0, secondDay = 0;
	size_t pos = 0;
	pos = first.birthday.find(" ");
	firstMonth = StrToInt(first.birthday.substr(0, pos));	
	firstDay = StrToInt(first.birthday.substr(pos + 1));
	pos = second.birthday.find(" ");
	secondMonth = StrToInt(second.birthday.substr(0, pos));	
	secondDay = StrToInt(second.birthday.substr(pos + 1));
	if (firstMonth != secondMonth) {
		return firstMonth < secondMonth;
	}
	else {
		return firstDay < secondDay;
	}
	
}

int main() {
	int test = 0;  cin >> test;
	Student* persons = new Student[test + 1];
	map<string, int> counts; // ͳ��ͬһ�����յ�ѧ������ 
	map<string, int> birthToIndex;
	string id = " ", birthday = " ";
	char ch = ' ';
	int index = 1;
	for (int times = 1; times <= test; times++) {
		cin >> id;  ch = getchar();  getline(cin, birthday);
		//cout << endl << id << " " << birthday << endl;
		if (counts[birthday] == 0) {
			//cout << endl << "Add it" << endl;
			counts[birthday]++;
			birthToIndex[birthday] = index;
			persons[index].birthday = birthday;
			persons[index].id.push_back(id);
			index++;
		}
		else {
			//cout << endl << "This way " << endl;
			persons[birthToIndex[birthday]].id.push_back(id);
		}
	}
	index--;
	vector<string>::iterator it;
	sort(persons + 1, persons + 1 + index, cmp); // û��test��ô�࣬ʵ����ֻ��index�� 
	//cout << endl << "index : " << index << endl;
	for (int sub = 1; sub <= index; sub++) {
		cout << persons[sub].birthday << " ";
		for (it = persons[sub].id.begin(); it != persons[sub].id.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	return 0;
} 
