// 不需要浪费空间存储所有的数字，只需要一个答案容器存储字符串
// 判断逻辑：保留前一个数字与目前的数字，根据判定规则判定即可
// 第一次感受到了群论的运算表的作用 

#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main() {
	int numBefore = 0, numNow = 0;
	vector<string> ans;
	bool haveJoined = false;
	
	while (cin >> numBefore) {
		if (numBefore == -1) break;
		haveJoined = false;
		
		for (int times = 1; times <= 9; times++) {
			cin >> numNow;
			
			if (numBefore == 0) { // 0的后面只能是0/1/7/8 
				if (numNow == 0 || numNow == 1 || numNow == 7 || numNow == 8) {
					numBefore = numNow;
					continue;
				}
				else {
					for (int i = 1; i <= 9 - times; i++)  cin >> numNow;
					ans.push_back("NO");
					haveJoined = true;
					break;
				} 
			}
			
			else if (numBefore == 1) { // 1的后面不能是2/5/6 
				if (numNow == 2 || numNow == 5 || numNow == 6) {
					for (int i = 1; i <= 9 - times; i++)  cin >> numNow;
					ans.push_back("NO");
					haveJoined = true;
					break;
				}
				else {
					numBefore = numNow; 
					continue;
				}
			}
			
			else if (numBefore == 2) { // 2的后面只能是2/8 
				if (numNow == 2 || numNow == 8) {
					numBefore = numNow;
					continue;
				}
				else {
					for (int i = 1; i <= 9 - times; i++)  cin >> numNow;
					ans.push_back("NO");
					haveJoined = true;
					break;
				} 
			}
			
			else if (numBefore == 3) { // 3的后面只能是1/3/7/8/9
				if (numNow == 1 || numNow == 3 || numNow == 7 || numNow == 8 || numNow == 9) {
					numBefore = numNow;
					continue;
				}
				else {
					for (int i = 1; i <= 9 - times; i++)  cin >> numNow;
					ans.push_back("NO");
					haveJoined = true;
					break;
				} 
			}
			
			else if (numBefore == 4) { // 4的后面只能是1/4/8/9 
				if (numNow == 1 || numNow == 4 || numNow == 8 || numNow == 9) {
					numBefore = numNow;
					continue;
				}
				else {
					for (int i = 1; i <= 9 - times; i++)  cin >> numNow;
					ans.push_back("NO");
					haveJoined = true;
					break;
				} 
			}
			
			else if (numBefore == 5) { // 5的后面只能是5/6/8/9
		    	if (numNow == 5 || numNow == 6 || numNow == 8 || numNow == 9) {
					numBefore = numNow;
					continue;
				}
				else {
					for (int i = 1; i <= 9 - times; i++)  cin >> numNow;
					ans.push_back("NO");
					haveJoined = true;
					break;
				} 
			}
			
			else if (numBefore == 6) { // 6的后面只能是5/6/8 
				if (numNow == 5 || numNow == 6 || numNow == 8) {
					numBefore = numNow;
					continue;
				}
				else {
					for (int i = 1; i <= 9 - times; i++)  cin >> numNow;
					ans.push_back("NO");
					haveJoined = true;
					break;
				} 
			}
			
			else if (numBefore == 7) { // 7的后面不能是2/4/5/6 
				if (numNow == 2 || numNow == 4 || numNow == 5 || numNow == 6) {
					for (int i = 1; i <= 9 - times; i++)  cin >> numNow;
					ans.push_back("NO");
					haveJoined = true;
					break;
				}
				else {
					numBefore = numNow; 
					continue;
				}
			}
			
			else if (numBefore == 8) { // 8的后面可以是任何数 
				numBefore = numNow;
				continue;
			}
			
			else { // 9的后面不能是0/2/6 
				if (numNow == 0 || numNow == 2 || numNow == 6) {
					for (int i = 1; i <= 9 - times; i++)  cin >> numNow;
					ans.push_back("NO");
					haveJoined = true;
					break;
				}
				else {
					numBefore = numNow; 
					continue;
				}
			}
		}
		if (!haveJoined) ans.push_back("YES"); // 九个数都满足条件才能输出YES 
	}
	
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
