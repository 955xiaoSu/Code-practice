// 需要统计球队的净胜球数，以及积分
// 根据排名规则，返回出前两名的结果
// 需要一个排序函数，用vector存储比赛结果
// 弄一个字符串对应数据结构的转换规则，用index记录 

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Team {
	string name;
	int integral;
	int margin;
	Team() {
		integral = margin = 0;
		name = " ";
	}
};

Team* digits;

void Classified(int first, int second, int firstScore, int secondScore) {
	if (firstScore > secondScore) {
		digits[first].integral += 3;
		digits[first].margin += firstScore - secondScore;	
		digits[second].margin += secondScore - firstScore;
	}
	
	else if (firstScore == secondScore) {
		digits[first].integral += 1;
		digits[second].integral += 1; 
	}
	
	else {
		digits[second].integral += 3;
		digits[second].margin += secondScore - firstScore;
		digits[first].margin += firstScore - secondScore;
	}
}

bool cmp(Team first, Team second) {
	if (first.integral != second.integral) {
		return first.integral > second.integral;
	} 
	else return first.margin > second.margin;
}

int main() {
	int test = 0;  cin >> test;
	map<string, int> transfer;
	vector<string> ans;
	
	string first, second, temp; // temp是用来吸收"vs."这个字符串 
	int firstScore = 0, secondScore = 0;
	int index = 1;
	while (test--) {
		index = 1;  transfer.clear();
		digits = new Team[5];
		
		for (int times = 1; times <= 12; times++) { // 对每一组数据进行处理 
			// 实现每一行数据的读入，并且将主队名称映射成下标 
			cin >> first; 
			if (transfer[first] == 0) {
				transfer[first] = index;
				digits[transfer[first]].name = first;
				index++;
			}
			
			
			cin >> firstScore >> temp >> secondScore >> second;
			if (transfer[second] == 0) {
				transfer[second] = index;
				digits[transfer[second]].name = second;
				index++;
			}
			
			// 对比赛的三种情况进行分类讨论 
			Classified(transfer[first], transfer[second], firstScore, secondScore);
		}
		
		sort(digits + 1, digits + 5, cmp); // 小心边界条件！ 
		//cout << endl;
		//for (int i = 1; i <= 4; i++) {
		//	cout << digits[i].name << " " << digits[i].integral << " " << digits[i].margin << endl;
		//}
		//cout << endl;
		ans.push_back(digits[1].name);
		ans.push_back(digits[2].name);
		//cout << digits[1].name << " " << digits[1].integral << " " << digits[1].margin << endl;
		//cout << digits[2].name << " " << digits[2].integral << " " << digits[2].margin << endl;

	}
	
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it;
		it++;
		cout << " " << *it << endl;
	} 
	return 0;
} 
