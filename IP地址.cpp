// 用字符串进行保存，将一个字符串截断成四个子字符串
// 写一个计数函数来返回每个字符串包含的1的个数
// 用一个int类型的数组存储答案 

#include <iostream>
#include <string>
using namespace std;

string toBinary(int n) {
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return r;
}

// 统计1的个数 
int Calculate(string& s) {
	//cout << "Before : " << s << " "; 
	int result = 0,	len = s.length();
	int num = 0;
	
	for (int i = 0; i < len; i++) {
		num = num * 10 +  s[i] - '0'; 
	}
	string afterTrans = toBinary(num);
	//cout << "After : " << afterTrans << endl;
	char cmp = '1';
	for (unsigned int sub =  0; sub < afterTrans.length(); sub++) {
		if (afterTrans[sub] == cmp)  
			result++;
	}
	return result;
}

int main() {
	int test = 0;  cin >> test;
	int* ans = new int[test];
	int count = 0;
	
	string s = " ", temp = " ", occa = " ", temp2 = " ", temp3 = " ", temp4 = " ";
	for (int times = 0; times < test; times++) {
		cin >> s;	
		count = 0;
		
		// 搜索三次'.'的位置，然后使用substr()方法获取想要的子串 
		size_t pos = s.find(".");
		temp = s.substr(pos + 1);
		occa = s.substr(0, s.length() - temp.length() - 1);
		count += Calculate(occa);
		
		pos = temp.find(".");
		temp2 = temp.substr(pos + 1);
		occa = temp.substr(0, temp.length() - temp2.length() - 1);
		count += Calculate(occa);
		
		pos = temp2.find(".");
		temp3 = temp2.substr(pos + 1);
		occa = temp2.substr(0, temp2.length() - temp3.length() - 1);
		count += Calculate(occa);
		
		pos = temp3.find(".");
		temp4 = temp3.substr(pos + 1);
		count += Calculate(temp4);
		
		ans[times] = count;
	}
	
	for (int sub = 0; sub < test; sub++) {
		cout << ans[sub] << endl;
	} 
	return 0;
}
