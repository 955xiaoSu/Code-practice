// 实现按字符串对称输入

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
	vector<string> ans;
	vector<int> nums; // 存储每次要输出字符串的数量 
	vector<string> temp;
	
	int digit = 0, totalNum = 0;
	string s = " ";
	vector<string>::iterator i = temp.begin();
	while (cin >> digit) {
		if (digit == 0) break;
		nums.push_back(digit);
		totalNum += digit;
		
		temp.clear();
		temp.resize(digit);  // 一定要先进行内存分配再使用下标赋值 
		if (digit % 2 == 0) {
			for (int index = 0; index < digit / 2; index++) {
				cin >> s;
				temp[index] = s;
				cin >> s;
				temp[digit - index - 1] = s;
			}
		}
		else {
			for (int index = 0; index < digit / 2; index++) {
				cin >> s;
				temp[index] = s;
				cin >> s;
				temp[digit - index - 1] = s;
			}
			cin >> s; temp[digit / 2] = s; // 注意下标的计算 
		}
		
		ans.insert(ans.end(), temp.begin(), temp.end());
	}
	
	i = ans.begin();
	int count = 1;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		cout << "set-" << count << endl;
		count++;
		for (int times = 1; times <= *it; times++, i++) { // 别再忘记更新迭代器的位置！！！ 
			cout << *i << endl;
		}
	}	
	return 0;
}
