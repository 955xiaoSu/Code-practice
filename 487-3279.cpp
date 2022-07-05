// 检查是否有相同的电话号码
// 输出超过两次的电话号码
// 使用map<char, char>映射先构建统一的电话号码格式
// 再使用map<string, int>建立号码->出现次数的映射
// 再对符合要求的字符串存入到vector容器中进行输出 
 
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

// 功能：将号码转换为标准格式 
string Transfer(string& s, map<char, char>& phoneNum) {
	string finalAns = " ";  finalAns.resize(8);  finalAns[3] = '-';
	// 首先把字符串中的'-'全部清洗掉
	size_t pos = 0;
	while (1) {
		pos = s.find("-");
		if (pos == s.npos) break;
 		else s.erase(pos, 1);
	} 
	// 其次把字符串中的字母全部转换成数字
	for (unsigned int index = 0; index < s.length(); index++) {
		if (s[index] > '9' || s[index] < '0') {		
			s[index] = phoneNum[s[index]];
		}
		else continue;
	} 
	// 最后转换为答案字符串返回
	for (int index = 0; index <= 2; index++) finalAns[index] = s[index];
	for (int index = 4; index <= 7; index++) finalAns[index] = s[index - 1];
	return finalAns;
}

bool cmp(string first, string second) {
	return first.compare(second) <= 0;
}

int main() {
	int test = 0;  cin >> test;
	map<char, char> phoneNum; // 实现字母到数字的映射 
	Init(phoneNum);
	
	string s = " ", result = " ";
	map<string, int> record; // 统计输入的次数 
	while (test--) {
		cin >> s;
		result = Transfer(s, phoneNum); // 将电话号码转化为标准格式
		record[result]++; 
	}
	// 将符合要求的字符串输出容器当中 
	vector<string> ans;
	for (map<string, int>::iterator it = record.begin(); it != record.end(); it++) {
		if (it->second >= 2) 
			ans.push_back(it->first);
	}
	// 实现字典序排序 
	sort(ans.begin(), ans.end(), cmp);
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << " " << record[*it] << endl;
	}
	return 0;
}
