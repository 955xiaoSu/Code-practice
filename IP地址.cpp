// ���ַ������б��棬��һ���ַ����ضϳ��ĸ����ַ���
// дһ����������������ÿ���ַ���������1�ĸ���
// ��һ��int���͵�����洢�� 

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

// ͳ��1�ĸ��� 
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
		
		// ��������'.'��λ�ã�Ȼ��ʹ��substr()������ȡ��Ҫ���Ӵ� 
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
