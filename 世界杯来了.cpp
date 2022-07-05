#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Team {
	string name;
	int integral; // 积分 
	int margin; // 净胜球 
	int score; // 进球数 
	Team() {
		integral = margin = score = 0;
		name = " ";
	}
};

Team* digits;

// 功能：对比赛的所有情况进行分类讨论 
void Classified(int first, int second, int firstScore, int secondScore) {
	if (firstScore > secondScore) {
		digits[first].integral += 3;
		digits[first].score += firstScore;
		digits[second].score += secondScore;
		digits[first].margin += firstScore - secondScore;	
		digits[second].margin += secondScore - firstScore;
	}
	
	else if (firstScore == secondScore) {
		digits[first].integral += 1;
		digits[second].integral += 1; 
		digits[first].score += firstScore;
		digits[second].score += secondScore;
	}
	
	else {
		digits[second].integral += 3;
		digits[first].score += firstScore;
		digits[second].score += secondScore;
		digits[first].margin += firstScore - secondScore;	
		digits[second].margin += secondScore - firstScore;
	}
}

// 功能：对结构体数组按照积分递减、净胜球递减以及进球数递减递增方式排名
bool cmp(Team first, Team second) {
	if (first.integral != second.integral) {
		return first.integral > second.integral;
	} 
	else if (first.margin != second.margin) return first.margin > second.margin;
	else return first.score > second.score;
}

// 功能：实现字符串的字典序排序
bool CMP(string first, string second) {
	return first.compare(second) < 0;
} 

// 功能：将数字从string转化为int 
int TransStrToInt(string s) {
	int result = 0, len = s.length();
	for (int index = 0; index < len; index++) {
		result = result * 10 + s[index] - '0';
	}
	return result;
}

int main() {
	map<string, int> transfer;
	vector<string> ans;
	
	// 实现球队名称->结构体数组下标的映射 
	int playTeamNum = 0;  cin >> playTeamNum;
	digits = new Team[playTeamNum + 1];
	int index = 1;
	string temp;
	for (int times = 1; times <= playTeamNum; times++) {
		cin >> temp;
		transfer[temp] = index;
		digits[index].name = temp;
		index++;
	} 
	
	string first, second; //first,second分别代表两支球队的名称 
	int firstScore = 0, secondScore = 0;  // 分别代表两支球队的进球数 
	string occa; // 字符串转换为数字的媒介 
	char ch = ' '; // 用于寻找特殊符号位置 
	size_t pos = 0; // 辅助截取字符串 
	for (int times = 1; times <= ((playTeamNum * (playTeamNum - 1)) / 2); times++) { // 对每一组数据进行处理 
		// 从字符串中提取球队名称 
		cin >> temp;
		ch = '-';
		pos = temp.find(ch);
		first = temp.substr(0, pos);
		second = temp.substr(pos + 1);
		
		// 从字符串中提取比分 
		cin >> temp;
		ch = ':';
		pos = temp.find(ch);
		occa = temp.substr(0, pos);
		firstScore = TransStrToInt(occa);
		occa = temp.substr(pos + 1);
		secondScore = TransStrToInt(occa);
		
		// 分类讨论所有的比赛情况 
		Classified(transfer[first], transfer[second], firstScore, secondScore);
	}
	
	sort(digits + 1, digits + 1 + playTeamNum, cmp); // 小心边界条件！ 
	for (int index = 1; index <= (playTeamNum / 2); index++) {
		ans.push_back(digits[index].name);	
	}
	sort(ans.begin(), ans.end(), CMP);
	
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	} 
	return 0;
} 
