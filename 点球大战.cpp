// 罚三轮点球，如果不分胜负进入一轮定胜负的阶段
// 用五个vector，一个记录先罚球队伍的情况，一个记录后罚球队伍的情况，一个记录先发球队伍此轮得分，
// 一个记录后罚球队伍此轮得分，一个记录行数方便后来的输出

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<char> firstPenalty, secondPenalty;
	vector<int> firstScore, secondScore;
	vector<int> penaltyFrequency;
	
	int times = 0;  string s = " ";
	int hostIntegral = 0, guestIntegral = 0;
	bool isHost = true;
	while (cin >> times) {
		if (times == 0) break;
		
		isHost = true;
		hostIntegral = guestIntegral = 0;
		
		for (int degree = 1; degree <= times; degree++) {
			// 将球员名字过滤 
			while (cin >> s) {
			if (s == "good" || s == "no")
				break;
			}
			// 对进球的情况进行处理 
			if (s == "good") {
				// 对先点球的进球进行处理 
				if (isHost) {
					firstPenalty.push_back('O');
					isHost = false;
					hostIntegral++;
				}
				// 对后点球的进球进行处理 
				else {
					secondPenalty.push_back('O');
					isHost = true;
					guestIntegral++;
				}
			}
			// 对不进球的情况进行处理 
			else {
				cin >> s; // 把其后的good进行吸收
				// 对先点球的不进球情况进行处理 
				if (isHost) {
					firstPenalty.push_back('X');
					isHost = false;
				}
				// 对后点球的不进球情况进行处理 
				else {
					secondPenalty.push_back('X');
					isHost = true;
				}
			} 
		}
			
		// 将每一轮的总得分进行记录 
		firstScore.push_back(hostIntegral);
		secondScore.push_back(guestIntegral);	
		
		// 对双方点球次数情况进行处理 
		if (times % 2 == 0) {
			penaltyFrequency.push_back(times / 2); 
		}
		else {
			penaltyFrequency.push_back(times / 2 + 1);	
			// 如果点球次数使奇数，按照题目要求后点球的一方应该添加一个'-'在末尾 
			secondPenalty.push_back('-');
		}
	}
	
	vector<char>::iterator first = firstPenalty.begin();
	vector<char>::iterator second = secondPenalty.begin();
	vector<int>::iterator scoreF = firstScore.begin();
	vector<int>::iterator scoreS = secondScore.begin();
	for (vector<int>::iterator it = penaltyFrequency.begin(); it != penaltyFrequency.end(); it++) {
		for (int frequency = 1; frequency <= *it; frequency++) {
			cout << frequency << " ";
		}
		cout << "Score" << endl;
		
		for (int times = 1; times <= *it; times++, first++) {
			cout << *first << " ";
		} 
		cout << *scoreF << endl;  scoreF++;
		
		for (int times = 1; times <= *it; times++, second++) {
			cout << *second << " ";
		} 
		cout << *scoreS << endl;  scoreS++;
	}
	return 0;
} 
