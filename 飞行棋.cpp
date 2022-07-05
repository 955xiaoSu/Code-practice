// 骰子数越界处理，特殊格子功能标记，骰子数有固定规律
// 用vector存储答案与骰子数，用map映射特殊格子功能
// 结束条件就是某个人走到了终点 
//  因为情况不交叉，所以可以分别处理 

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int main() {
	stack<int> point;
	vector<string> ans;
	map<int, int> special;
	int N = 0, A = 0, B = 0, C = 0;
	int lele = 0, yueyue = 0, before = 0;
	string s = " ";
	while (cin >> N >> A >> B >> C) {
		// 本局游戏的初始化 
		special.clear();  
		lele = yueyue = 0;
		for (int index = 0; index < N; index++) {
			cin >> s;
			if (s[0] == 'G') special[index] = s[1] - '0';
			else special[index] = 0;
		}
		point.push((A * C + B) % 6 + 1);
		while (true) {
			before = lele;
			lele += point.top();
			// 处理遇到特殊格子 
			if (special[lele] != 0) lele = special[lele];
			// 处理越界情况 
			if (lele >= N) lele = 2 * N - lele;
			// 处理两棋子相遇
			if (lele == yueyue) lele = before;
			// 处理lele获胜
			if (lele == N - 1) break; 
			// 处理下一步骰子数
			point.push((A * point.top() + B) % 6 + 1); 
			before = yueyue;
			yueyue += point.top();
			// 处理遇到特殊格子 
			if (special[yueyue] != 0) yueyue = special[yueyue];
			// 处理越界情况 
			if (yueyue >= N) yueyue = 2 * N - yueyue;
			// 处理两棋子相遇
			if (yueyue == lele) yueyue = before;
			// 处理yueyue获胜
			if (yueyue == N - 1) break; 
			// 处理下一步骰子数 
			point.push((A * point.top() + B) % 6 + 1); 
 			
		}
		if (lele == N - 1) ans.push_back("Lele");
		else ans.push_back("Yueyue");
	}
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
} 
