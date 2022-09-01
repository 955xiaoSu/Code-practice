// 用set进行排名，map进行映射与输出 
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	int total = 0;  cin >> total; // total参赛选手人数 
	int* score = new int[total];
	set<int> scoreRank;	// set容器本身是有序的，故可以对成绩进行排名 
	for (int index = 0; index < total; index++) {
		cin >> score[index];
		scoreRank.insert(score[index]);
	} 
	map<int, int> scoreToRank;
	int rank = 1;
	for (set<int>::reverse_iterator it = scoreRank.rbegin(); it != scoreRank.rend(); it++) {
		scoreToRank.insert(pair<int, int>(*it, rank)); // 将参赛选手成绩自动转化为相应的排名 
		rank++;
	}
	for (int index = 0; index < total; index++) {
		cout << scoreToRank[score[index]] << " "; // 输出选手对应的排名 
	}
	return 0;
}
