// ʵ�ְ��ַ����Գ�����

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
	vector<string> ans;
	vector<int> nums; // �洢ÿ��Ҫ����ַ��������� 
	vector<string> temp;
	
	int digit = 0, totalNum = 0;
	string s = " ";
	vector<string>::iterator i = temp.begin();
	while (cin >> digit) {
		if (digit == 0) break;
		nums.push_back(digit);
		totalNum += digit;
		
		temp.clear();
		temp.resize(digit);  // һ��Ҫ�Ƚ����ڴ������ʹ���±긳ֵ 
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
			cin >> s; temp[digit / 2] = s; // ע���±�ļ��� 
		}
		
		ans.insert(ans.end(), temp.begin(), temp.end());
	}
	
	i = ans.begin();
	int count = 1;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		cout << "set-" << count << endl;
		count++;
		for (int times = 1; times <= *it; times++, i++) { // �������Ǹ��µ�������λ�ã����� 
			cout << *i << endl;
		}
	}	
	return 0;
}
