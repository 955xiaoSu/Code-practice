// 使用结构体存储数据，并用字符序排列后输出
// 使用set淘汰掉重复的字符串，并用find()函数淘汰城市号码
// 用一个map实现人名到结构体数组下标的映射

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
	set<string> phonenumber; // 去重
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
		// 实现人名到结构体数组下标的映射
		if (nameToIndex[name] == 0) {
			nameToIndex[name] = index;
			index++;
		}
		persons[nameToIndex[name]].name = name;
		cin >> records;
		for (int fre = 1; fre <= records; fre++) {
			cin >> phone;
			// 多重调用可能编译器无法识别，注意解引用的运算优先级
			persons[nameToIndex[name]].phonenumber.insert(phone);
		}
	}
	index--;
	set<string>::iterator it;
	set<string>::reverse_iterator reverse;
	bool result = false;
	// 结构体数组进行totalPhoneNum的统计、删除城市号码并进行首字母排序
	for (int sub = 1; sub <= index; sub++) {
		// 删除城市号码
		for (it = persons[sub].phonenumber.begin(); it != persons[sub].phonenumber.end(); it++) {
			result = false;
			for (reverse = persons[sub].phonenumber.rbegin(); reverse != persons[sub].phonenumber.rend(); reverse++) {
				// 初步具备被删除的可能 
				if ((*reverse).find(*it) != (*reverse).npos && *reverse != *it) {
					// 要达到从尾部开始比对都一样的效果
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
		// 转移到vector容器当中方便自定义比较函数 
		for (it = persons[sub].phonenumber.begin(); it != persons[sub].phonenumber.end(); it++) {
			persons[sub].ans.push_back(*it);
		}
		sort(persons[sub].ans.begin(), persons[sub].ans.end(), CMP);
		// totalPhoneNum的统计
		persons[sub].totalPhoneNum = persons[sub].phonenumber.size();
	}
	cout << index << endl;
	// 进行首字母排序
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
