// 方法；倍数判断与字符串查找判断相结合
// 用vector<int>容器存储所有答案
// 难点在于把int转化为string 

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std; 

string Transfer(stringstream &sstream, string &numString, int num) {
	sstream.clear();  numString.clear();
	sstream << num;
	numString = sstream.str();
	sstream.str("");
	return numString;
}

// 传引用参数必须符合const条件 
bool Judge(string s) {
	if (s.find("7") != s.npos) return true;
	else return false;
}

int main() {
	int range = 0;  cin >> range;
	vector<int> ans;	
	bool result = false; // 接受函数判定是否含有n的结果 
	stringstream sstream; 	string numString; // stringstream是一个字符串类 
		
	for (int num = 7; num <= range; num++) {
		if (num % 7 == 0) {
			ans.push_back(num);
			continue; 
		}
		
		result = Judge(Transfer(sstream, numString, num));
		if (result) ans.push_back(num);
	}
	
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
