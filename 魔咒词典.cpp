// 实现一个相互对应的查找功能，如果查找不到则输出what?
// 使用两个map容器进行相互映射，使用vector<string>容器进行答案的存储 

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
	map<string, string> findByIncantation;
	map<string, string> findByFunction;
	string incantation = " ", temp = " ", function = " ";
	
	// 因为输入的咒语中可能含有空格，因此分别使用cin与getline()进行输入是有可能报错的 
	while (getline(cin, temp)) {
		if (temp == "@END@") break;
		
		// 使用substr()方法截取出咒语与对应的功能 
		// 总结一下substr()方法，第一种就是给一个起始的位置参数，第二种是给定起始位置参数与截取长度 
		size_t pos = temp.find("]");
		incantation = temp.substr(0, pos + 1);
		function = temp.substr(pos + 2);
		
		
		findByIncantation.insert(pair<string, string>(incantation, function));
		findByFunction.insert(pair<string, string>(function, incantation));
	}
	
	// 因为cin把换行符留在输入队列当中，所以下面代码中的第一次getline，实际上直接读取到一个换行符，然后把
	// 换行符丢弃换成'\0'，故第一次读入的字符串是一个空串
	// 因此利用cin.get()提前将换行符读取 
	int test = 0;  cin >> test; 
	char ch = ' ';  cin.get(ch); 
	
	string s = " ";
	vector<string> ans;
	for (int times = 1; times <= test; times++) {
		getline(cin, s); // 每次输入的可能都是一行字符串 
		if (findByFunction.find(s) == findByFunction.end() && findByIncantation.find(s) == findByIncantation.end()) {
			ans.push_back("what?");
		}
		else if (findByFunction.find(s) != findByFunction.end()) {
			s = findByFunction[s];
			// 将魔咒中的'[]'剔除 
			s.erase(s.begin(), s.begin() + 1);
			s.erase(s.end() - 1, s.end());
			ans.push_back(s);
		}
		else ans.push_back(findByIncantation[s]);
	}
	
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
} 
