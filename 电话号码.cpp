// ʹ�ýṹ��洢���ݣ������ַ������к����
// ʹ��set��̭���ظ����ַ���������find()������̭���к���
// ��һ��mapʵ���������ṹ�������±��ӳ��

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct People {
	string name;
	int totalPhoneNum;
	set<string> phonenumber; // ȥ��
	vector<string> ans;
	People() {
		name = " "; 
		ans.clear();  phonenumber.clear();
		totalPhoneNum = 0;
	}
};

bool cmp(People first, People second) {
	return (first.name.compare(second.name) < 0);
}

bool CMP(string first, string second) {
	if (first.length() != second.length()) {
		return first.length() <= second.length();
	}
	return first.compare(second) < 0;
}

int main() {
	int test = 0;
	cin >> test;
	People* persons = new People[test + 1];
	map<string, int> nameToIndex;
	string name = " ", phone = " ";
	int records = 0, index = 1;

	for (int times = 1; times <= test; times++) {
		cin >> name;
		// ʵ���������ṹ�������±��ӳ��
		if (nameToIndex[name] == 0) {
			nameToIndex[name] = index;
			index++;
		}
		persons[nameToIndex[name]].name = name;
		cin >> records;
		for (int fre = 1; fre <= records; fre++) {
			cin >> phone;
			// ���ص��ÿ��ܱ������޷�ʶ��ע������õ��������ȼ�
			persons[nameToIndex[name]].phonenumber.insert(phone);
		}
	}
	index--;
	set<string>::iterator it;
	set<string>::reverse_iterator reverse;
	bool result = false;
	// �ṹ���������totalPhoneNum��ͳ�ơ�ɾ�����к��벢��������ĸ����
	for (int sub = 1; sub <= index; sub++) {
		// ɾ�����к���
		for (it = persons[sub].phonenumber.begin(); it != persons[sub].phonenumber.end(); it++) {
			result = false;
			for (reverse = persons[sub].phonenumber.rbegin(); reverse != persons[sub].phonenumber.rend(); reverse++) {
				// �����߱���ɾ���Ŀ��� 
				if ((*reverse).find(*it) != (*reverse).npos && *reverse != *it) {
					// Ҫ�ﵽ��β����ʼ�ȶԶ�һ����Ч��
					unsigned int len1 = (*it).length(), len2 = (*reverse).length();
					for (int index = len1 - 1; index >= 0; index--, len2--) {
						if ((*it)[index] != (*reverse)[len2 - 1]) {
							result = false;
							break;
						}
						if (index == 0) result = true;
					} 
					if (result) {
						persons[sub].phonenumber.erase(it);
						break;
					}
				}
				else continue;
			}
		}
		// ת�Ƶ�vector�������з����Զ���ȽϺ��� 
		for (it = persons[sub].phonenumber.begin(); it != persons[sub].phonenumber.end(); it++) {
			persons[sub].ans.push_back(*it);
		}
		sort(persons[sub].ans.begin(), persons[sub].ans.end(), CMP);
		// totalPhoneNum��ͳ��
		persons[sub].totalPhoneNum = persons[sub].phonenumber.size();
	}
	cout << index << endl;
	// ��������ĸ����
	sort(persons + 1, persons + 1 + index, cmp);
	for (int sub = 1; sub <= index; sub++) {
		cout << persons[sub].name << " " << persons[sub].totalPhoneNum << " ";
		for (vector<string>::iterator final = persons[sub].ans.begin(); final != persons[sub].ans.end(); final++) {
			cout << *final << " ";
		}
		cout << endl;
	}
	return 0;
}
