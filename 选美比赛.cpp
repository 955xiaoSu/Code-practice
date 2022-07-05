// 用set进行排名，map进行映射与输出 

#include <iostream>
#include <map> 
#include <set>
using namespace std;

int main() {
	int totalPeople = 0;  cin >> totalPeople;
	int* digits = new int[totalPeople + 1];
	for (int index = 1; index <= totalPeople; index++) cin >> digits[index];
	set<int> myset;
	map<int, int> scoreToRank;
	for (int index = 1; index <= totalPeople; index++) {
		myset.insert(digits[index]);
	}
	int rank = 1;
	for (set<int>::reverse_iterator it = myset.rbegin(); it != myset.rend(); it++) { // 注意正反向迭代器名称不同 
		scoreToRank.insert(pair<int, int>(*it, rank));
		rank++;
	}
	for (int index = 1; index <= totalPeople; index++) {
		cout << scoreToRank[digits[index]] << " ";
	}
	return 0;
} 
