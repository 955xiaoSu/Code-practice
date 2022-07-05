// 由于数据规模很大，因此得采用字符串进行处理 
// 我需要两个函数，第一是乘法函数，第二是判别函数

#include <iostream>
#include <string>
using namespace std; 

// 功能：实现以string存储的数字的乘法运算 
// 参数列表：原字符串s；乘法因子product 
// 返回值：原字符串经乘法运算后得到的字符串 
string Multiplication(string s, unsigned int product) {
	int len = s.length();
	int count = 0, temp = 0; // count记录应进到下一位的数，temp记录本位数字进行乘法运算后得到的结果 
	for (int index = len - 1; index >= 0; index--) { // 从最低位到最高位 
		temp = (s[index] - '0') * product + count;
		count = temp / 10;
		temp = temp % 10;
		s[index] = temp + '0';
	}
	
	// 考虑如果最高位大于9，说明数字位数增加，那么返回一串全为0，且长度为原来长度+1的字符串
	// 这么做是为了方便判别函数进行判断 
	if (s[0] > '9') {
		string result;
		result.resize(len + 1);
		for (int index = 0; index <= len; index++) {
			result[index] = '0';
		}
		return result;
	}
	else return s;
}


// 功能：判定是否该数是否为循环数
// 参数列表：经过乘法运算得到的字符串temp；原字符串s；原字符串长度len 
// 返回值：如果为循环数，返回true；否则返回false 
bool Judge(string& temp, const string s, const unsigned int len) {
	if (temp.length() != len) return false; // 注意如果字符串本身长度变化了，那么一定不是循环数
	
	// 将temp的最后一位挪到第一位，满足循环数的定义 
	temp.insert(0, 1, temp[len - 1]);  temp.erase(len);	
	  
	char target = temp[0]; // 从第一位进行比对 
	size_t pos = 0;
	// 考虑到target可能是字符串中的某重复字符，因此在s中应对应多种可能的字符串序列  
	while (pos < s.npos) {
		// 心得：size_t是C中定义的long long unsigned int类型 
	    // 如果要对齐运算一般得进行数据类型的强制转换，不然很容易发生程序错误 
	    // 但是即使进行了强制转换还是有几率发生玄学错误，因此采用find()找遍s中target字符的所有可能位置
		pos = s.find(target, pos); 
		for (unsigned int index = 0; index < len; index++, pos++) {
			if (pos == len)  pos -= len;
			if (temp[index] != s[pos]) break;
			if (index == len - 1) return true; // 只要有一个符合的字符串序列即可 
		}
	}
	
	return false; // 如果所有字符串序列都不符合条件，那么返回false 
}

int main() {
	string s;  cin >> s;  
	unsigned int len = s.length();
	bool result = true;
	
	string temp = " "; // 接收原先字符串做乘法运算后的结果 
	for (unsigned int product = 2; product <= len; product++) {
		temp = Multiplication(s, product);
		result = Judge(temp, s, len);  
		cout << endl;
		if (!result) {
			cout << "No";
			return 0;
		} 
	}
	
	cout << "Yes";
	return 0;
} 
