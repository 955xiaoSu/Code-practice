// ����Ҫ�˷ѿռ�洢���е����֣�ֻ��Ҫһ���������洢�ַ���
// �ж��߼�������ǰһ��������Ŀǰ�����֣������ж������ж�����
// ��һ�θ��ܵ���Ⱥ�۵����������� 

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
			
			if (numBefore == 0) { // 0�ĺ���ֻ����0/1/7/8 
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
			
			else if (numBefore == 1) { // 1�ĺ��治����2/5/6 
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
			
			else if (numBefore == 2) { // 2�ĺ���ֻ����2/8 
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
			
			else if (numBefore == 3) { // 3�ĺ���ֻ����1/3/7/8/9
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
			
			else if (numBefore == 4) { // 4�ĺ���ֻ����1/4/8/9 
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
			
			else if (numBefore == 5) { // 5�ĺ���ֻ����5/6/8/9
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
			
			else if (numBefore == 6) { // 6�ĺ���ֻ����5/6/8 
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
			
			else if (numBefore == 7) { // 7�ĺ��治����2/4/5/6 
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
			
			else if (numBefore == 8) { // 8�ĺ���������κ��� 
				numBefore = numNow;
				continue;
			}
			
			else { // 9�ĺ��治����0/2/6 
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
		if (!haveJoined) ans.push_back("YES"); // �Ÿ��������������������YES 
	}
	
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
