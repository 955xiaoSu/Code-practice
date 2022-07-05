// ����жϣ����𰸴洢��vector<int>

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int len = 0;
	string s;
	vector<int> counts;
	
	while (cin >> len) {
		if (len == 0) break;
		cin >> s;
		
		// �ַ����ַ����붨�����ռλ����'\0'������ 
		int recordAB = 0, recordBA = 0;
		for (int index = 0; index < len - 1; index++) {
			if (s[index] == 'a' && s[index + 1] == 'b')
				recordAB++;
			else if (s[index] == 'b' && s[index + 1] == 'a')
				recordBA++;
			else continue;
		}
		counts.push_back(recordAB - recordBA);
	}
	
	for (vector<int>::iterator it = counts.begin(); it != counts.end(); it++) {
		cout << *it << endl;
	}
	return 0;
} 
