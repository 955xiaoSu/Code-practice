// ��һ��mapͳ���ж��ٸ�������ȶ�һ�¾��У������vector�洢

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
	string have = " ", want = " ";
	map<char, int> counts;
	vector<string> ans;
	vector<int> numBeeds;
	while (cin >> have >> want) {
		counts.clear();
		int len = have.length();
		for (int index = 0; index < len; index++) {
			counts[have[index]]++;
		}
		int less = 0; // ͳ��ȱ�ٵ����Ӽ��� 
		len = want.length();
		for (int index = 0; index < len; index++) {
			if (counts[want[index]] == 0) less++;
			else counts[want[index]]--;
		}
		if (less > 0) {
			ans.push_back("No"); numBeeds.push_back(less);
		}
		else {
			ans.push_back("Yes"); numBeeds.push_back(have.length() - want.length());
		}
	}
	vector<int>::iterator num = numBeeds.begin();
	vector<string>::iterator answer = ans.begin();
	for (; answer != ans.end(); answer++, num++) {
		cout << *answer << " " << *num << endl;
	}
	return 0;
} 
