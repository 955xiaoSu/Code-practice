// 根据核酸检测的有效时间，判定出行计划是否在有效时间内
// 有效时间q + k到q + k + c
// 判定：q + k <= t && q + k + c > t   等价于   t - c < q + k <= t
// 超时->以空间换时间，将时间转化成一个区间范围内的判断 
#include <iostream>
#include <string.h>
using namespace std;

const int maxN = 4e5; 
int section[maxN + 1]; // 开辟一个出行计划的有效区间 

void Insert(int left, int right) { // 对于区间的有效赋值是一种从点到线的延伸，数学的美妙！
	section[left] += 1;
	section[right + 1] -= 1;
}

int main() {
	int plan = 0, query = 0, needTime = 0; // plan出行计划数， query查询个数，needtime核酸检测所需时间
	cin >> plan >> query >> needTime;
	memset(section, 0, sizeof(section));
	
	int left = 0, right = 0;   // 分别代表左右区间 
	int start = 0, expiry = 0; // start前往时刻，expiry核酸检测时间 
	for (int index = 0; index < plan; index++) {
		cin >> start >> expiry;
		left = start - expiry + 1;   // 根据不等式左开右闭，所以有效的左区间得+1 
		left = left >= 1 ? left : 1; // 防止左区间过小不符合实际情况 
		right = start;
		Insert(left, right);
	}
	
	// 前缀加和，统计出区间中的每一个时刻对应的可出行计划数 
	for (int index = 1; index <= maxN; index++) {
		section[index] = section[index - 1] + section[index];
	} 
	
	int tmp = 0; // 记录临时查询时间 
	for (int times = 0; times < query; times++) {
		cin >> tmp;
		cout << section[tmp + needTime] << endl;
	}
	return 0;
}
 
