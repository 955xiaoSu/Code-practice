// 现在已经提供了每个车手的排名，要求我们根据排名规则反馈出冠军
// 还是将车手名字映射成下标，然后排序两次，分别存储结果 
// 只需要求出冠军，不用关心太多信息
// 那么冠军是什么样的？ 得分最多，排名靠前数最多
// 我先把得分最多或者排名靠前数最多的人搞出来 

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct Player {
	string name;
	int integral; // 积分 
	map<int, int> rankToTimes; // 实现从排名->次数的映射 
	Player() { // 改完结构体名称，记得同步修改构造函数 
		integral = 0;	
		name = " ";
		rankToTimes.clear();
		for (int rank = 1; rank <= 100; rank++) {
			rankToTimes.insert(pair<int, int>(rank, 0));
		}
	} 
};

Player* digits;
int index;

bool cmp(Player first, Player second) {
	if (first.integral != second.integral) {
		return first.integral > second.integral;
	}
	else {
		// 因为数据只保证有唯一的冠军，而不能保证任意两名选手排名都不想等 
		for (int rank = 1; rank <= 100; rank++) {
			if (first.rankToTimes[rank] != second.rankToTimes[rank]) {
				return first.rankToTimes[rank] > second.rankToTimes[rank];
			}
		}
		return false;
	} 
}

bool CMP(Player first, Player second) {
	if (first.rankToTimes[1] != second.rankToTimes[1]) {
		return first.rankToTimes[1] > second.rankToTimes[1]; 
	}
	else if (first.integral != second.integral) {
		return first.integral > second.integral;
	}
	else return cmp(first, second);
}

void Init(map<int, int>& rankToIntegral) {
	rankToIntegral.insert(pair<int, int>(1, 25));
	rankToIntegral.insert(pair<int, int>(2, 18));
	rankToIntegral.insert(pair<int, int>(3, 15));
	rankToIntegral.insert(pair<int, int>(4, 12));
	rankToIntegral.insert(pair<int, int>(5, 10));
	rankToIntegral.insert(pair<int, int>(6, 8));
	rankToIntegral.insert(pair<int, int>(7, 6));
	rankToIntegral.insert(pair<int, int>(8, 4));
	rankToIntegral.insert(pair<int, int>(9, 2));
	rankToIntegral.insert(pair<int, int>(10, 1));
	for (int rank = 11; rank <= 100; rank++) {
		rankToIntegral.insert(pair<int, int>(rank, 0));		
	}
	return;
}

int main() {
	string ans;
	map<string, int> transfer; // 实现车手名->结构体数组下标的映射
	map<int, int> rankToIntegral; // 实现排名->积分的映射 
	Init(rankToIntegral);
	digits = new Player[101];
		
	int races = 0;  cin >> races; //cout << races << endl;
	index = 1;
	string temp;
	while (races--) {
		int playerNum = 0;  cin >> playerNum; //cout << playerNum << endl;
		
		for (int rank = 1; rank <= playerNum; rank++) {
			cin >> temp; //cout << temp << endl;
			if (transfer[temp] == 0) {
				transfer[temp] = index;
				digits[index].name = temp;
				index++;
			}
			digits[transfer[temp]].integral += rankToIntegral[rank];
			digits[transfer[temp]].rankToTimes[rank]++;
		}
	} 
	
	// 教训：在你尚未完全通过测试前，所有的测试都应该注释掉而不是删除掉
	//cout << endl; 
	//for (int sub = 1; sub <= index; sub++) {
	//	if (digits[sub].integral == 0) break;
	//	cout << digits[sub].name << " " << digits[sub].integral << " " << digits[sub].rankToTimes[1] << endl;
	//}
	
	// 得出原始规则冠军 
	sort(digits + 1, digits + 1 + index, cmp); 
	ans = digits[1].name;
	cout << ans << endl;
	
	// 得出可选规则冠军 
	sort(digits + 1, digits + 1 + index, CMP);
	ans = digits[1].name;
	cout << ans;
	
	return 0;
} 
