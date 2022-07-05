// 输入的应该是字符串，截取之后按单位创建一个struct类型进行存储
// 方法：从低位向高位开始减，不够就减一

// 虽然成功实现，但是觉得自己的代码十分冗长，且条理并不是十分清晰
// 最起码可以不用这么多的空间，直接使用int记录 + string的截取功能就可以完成 

#include <iostream>
#include <string>
using namespace std;

struct Money {
	int Galleon;
	int Sickle;
	int Knut;
	bool plus;
	Money() {
		Galleon = Sickle = Knut = 0;
		plus = true;
	}
}; 

// 将得到的部分字符串转化为int 
inline int TransferStrToInt(string s) {
	int ans = 0, len = s.length();
	for (int index = 0; index < len; index++) {
		ans = ans * 10 + s[index] - '0';
	}
	return ans;
}

// 将字符串转化为int存入到Money当中 
void GetNum(Money& data, string& s) {
	string temp = " ";
	size_t site1 = s.find("."), site2 = s.find_last_of(".");
	
	// 按照.来划分字符串的截取范围 
	temp = s.substr(0, site1);
	data.Galleon = TransferStrToInt(temp);
	
	temp = s.substr(site1 + 1, site2 - site1 - 1);
	data.Sickle = TransferStrToInt(temp);
	
	temp = s.substr(site2 + 1);
	data.Knut = TransferStrToInt(temp);
	
	return;
}

// 初始化 
void Input(Money& shouldPay, Money& actuallyPay, Money& change) {
	string s1 = " ", s2 = " ";
	cin >> s1 >> s2;
	
	GetNum(shouldPay, s1);
	GetNum(actuallyPay, s2);
	
	// 计算零钱的过程可以先统一转化为Knut单位，最后由Knut再转化为其它进制的单位
	long long total1 = shouldPay.Knut + shouldPay.Sickle * 29 + shouldPay.Galleon * 29 * 17;
	long long total2 = actuallyPay.Knut + actuallyPay.Sickle * 29 + actuallyPay.Galleon * 29 * 17;
	long long ans = total2 >= total1 ? total2 - total1 : total1 - total2;
	
	change.plus = total2 >= total1 ? true : false; // 判断符号
	int lowest = ans % 29;
	int middle = ans / 29;
	int highest = middle / 17;  middle = middle % 17;
	
	change.Knut = lowest;  change.Sickle = middle;  change.Galleon = highest;
	return;
}

int main() {
	Money shouldPay, actuallyPay, change;
	
	Input(shouldPay, actuallyPay, change);
	
	if (!change.plus) cout << "-";
	cout << change.Galleon << "." << change.Sickle << "." << change.Knut;
	return 0;
}
