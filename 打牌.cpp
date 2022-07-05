// 牌的规则实质是统计每个数字的个数
// 因为数字规模大，只能使用字符串处理，用map统计数据，用vector容器存储答案string 
// 输入样例的时候首先得判断位数，其次再讨论各种对应情况

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void AddUp(map<int, int>& counts, string& s) {
	int len = s.length(), temp = 0;

	for (int sub = 0; sub < len; sub++) {
		temp = s[sub] - '0';
		counts[temp]++;
	}
	return;
}

inline int CalculateDigits(int num) {
	int result = 0;
	while (num > 0) {
		num /= 10;
		result++;
	}
	return result;
}

void ClassfiedDiscussion(int num, vector<vector<int>>& ansNum, vector<string>& ansStr, map<int, int>& counts, int& sub) {
	int digits = CalculateDigits(num); // 首先判断输入样例的位数
	bool haveJoined = false; // 对是否已加入答案容器进行判断
	int basicNum = num % 10; // 输入样例的最后一位数字有助于情况判断

	// 对方出一到四张牌进行讨论
	if (digits <= 4) {
		int finalAns = 0; // 根据输入样例的位数与样例的最后一位数字，决定符合情况的数字是什么

		for (int posNum = basicNum + 1; posNum <= 9; posNum++) {
			if (counts[posNum] >= digits) { // 如果压过对方的牌的数量足够，则可加入到答案容器当中

				for (int times = 1; times <= digits; times++) {
					finalAns = finalAns * 10 + basicNum;
				}
				//ansNum[sub].push_back(finalAns);
				if (!haveJoined) ansStr.push_back("YES");
				haveJoined = true;
			}
		}

		if (!haveJoined) ansStr.push_back("NO");
		return;
	}

	// 对方出五张牌的情况讨论
	else {
		if (basicNum == 9) {
			ansStr.push_back("NO");
			return;
		}
		for (int start = basicNum - 3; start <= 5; start++) {
			if (counts[start] == 0) continue;

			for (int find = start + 1; find <= 9 && find <= start + 4; find++) {
				if (counts[find] == 0) break;
				else if (find == start + 4) {
					ansNum[sub].push_back(start * 10000 + (start + 1) * 1000 + (start + 2) * 100 + (start + 3) * 10 + (start + 4));
					ansStr.push_back("YES");
					haveJoined = true;
				}
				else continue;
			}
		}

		if (!haveJoined) ansStr.push_back("NO");
		return;
	}
}

int main() {
	string s = " ";  cin >> s;
	map<int, int> counts;

	AddUp(counts, s); // 统计每个数字出现的次数

	int num = 0, sub = 0; // sub是答案数组的下标
	vector<vector<int>> ansNum; // 统计所有可能情况
	vector<string> ansStr; // 记录是否有压过对方的牌
	while (cin >> num) {
		ClassfiedDiscussion(num, ansNum, ansStr, counts, sub); // 进行分类讨论
		sub++;
	}

	vector<int>::iterator it;
	vector<vector<int>>::iterator iter = ansNum.begin();
	vector<int> vec_tmp;
	for (int row = 0; row < sub; row++, iter++) {
		cout << ansStr[row] << " ";
		vec_tmp = *iter;
		for (it = vec_tmp.begin(); it != vec_tmp.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
	return 0;
}