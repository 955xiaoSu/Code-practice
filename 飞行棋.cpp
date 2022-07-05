// ������Խ�紦��������ӹ��ܱ�ǣ��������й̶�����
// ��vector�洢��������������mapӳ��������ӹ���
// ������������ĳ�����ߵ����յ� 
//  ��Ϊ��������棬���Կ��Էֱ��� 

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int main() {
	stack<int> point;
	vector<string> ans;
	map<int, int> special;
	int N = 0, A = 0, B = 0, C = 0;
	int lele = 0, yueyue = 0, before = 0;
	string s = " ";
	while (cin >> N >> A >> B >> C) {
		// ������Ϸ�ĳ�ʼ�� 
		special.clear();  
		lele = yueyue = 0;
		for (int index = 0; index < N; index++) {
			cin >> s;
			if (s[0] == 'G') special[index] = s[1] - '0';
			else special[index] = 0;
		}
		point.push((A * C + B) % 6 + 1);
		while (true) {
			before = lele;
			lele += point.top();
			// ��������������� 
			if (special[lele] != 0) lele = special[lele];
			// ����Խ����� 
			if (lele >= N) lele = 2 * N - lele;
			// ��������������
			if (lele == yueyue) lele = before;
			// ����lele��ʤ
			if (lele == N - 1) break; 
			// ������һ��������
			point.push((A * point.top() + B) % 6 + 1); 
			before = yueyue;
			yueyue += point.top();
			// ��������������� 
			if (special[yueyue] != 0) yueyue = special[yueyue];
			// ����Խ����� 
			if (yueyue >= N) yueyue = 2 * N - yueyue;
			// ��������������
			if (yueyue == lele) yueyue = before;
			// ����yueyue��ʤ
			if (yueyue == N - 1) break; 
			// ������һ�������� 
			point.push((A * point.top() + B) % 6 + 1); 
 			
		}
		if (lele == N - 1) ans.push_back("Lele");
		else ans.push_back("Yueyue");
	}
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
} 
