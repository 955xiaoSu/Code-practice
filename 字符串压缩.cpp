

#include <iostream>
#include <string>
using namespace std;

int main() {
	int payMoney = 0, len = 0, a = 0, b = 0;
	cin >> len >> a >> b;
	//cout << len << " " << a << " " << b << endl;
	string s = " ", temp;  cin >> s; //cout << s << endl;
	int lenNow = 0;
	int profit = b / a;
	bool thisWay = false;
	for (int index = 0; index < len; index++) {
		lenNow = temp.length();
		// 截取尽可能长的字串进行对比，看是否能加入temp当中，可能是把潜在的最长加入长度缩短了导致金币增加！ 
		for (int lenSub = lenNow; lenSub >= 2 && lenSub + index <= len && lenSub >= profit; lenSub--) {
			cout << "lenSub : " << lenSub << " " << s.substr(index, lenSub) << endl;
			if (temp.find(s.substr(index, lenSub)) != temp.npos) {
				cout << s.substr(index, lenSub) << " isSub  : " << temp << endl;
				temp += s.substr(index, lenSub);
				payMoney += b;
				index += lenSub - 1;
				// 刚好把所有字符处理完毕 
				if (index == len - 1) {
					thisWay = true;
					break;
			    }
				continue;	
			}
		}
		if (thisWay) break;
		// 单个字符是子串 
		if (temp.find(s[index]) != temp.npos) {
			//cout << s[index] << " isSub  : " << temp << endl;
			if (b <= a) { payMoney += b; }
			else {
				payMoney += a;
				//cout << "It's expensive." << endl; 
			}
		}
		// 单个字符不是子串 
		else payMoney += a;
		temp += s[index];
	}
	cout << payMoney;
	return 0;
}
