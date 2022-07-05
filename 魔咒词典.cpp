// ʵ��һ���໥��Ӧ�Ĳ��ҹ��ܣ�������Ҳ��������what?
// ʹ������map���������໥ӳ�䣬ʹ��vector<string>�������д𰸵Ĵ洢 

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
	map<string, string> findByIncantation;
	map<string, string> findByFunction;
	string incantation = " ", temp = " ", function = " ";
	
	// ��Ϊ����������п��ܺ��пո���˷ֱ�ʹ��cin��getline()�����������п��ܱ���� 
	while (getline(cin, temp)) {
		if (temp == "@END@") break;
		
		// ʹ��substr()������ȡ���������Ӧ�Ĺ��� 
		// �ܽ�һ��substr()��������һ�־��Ǹ�һ����ʼ��λ�ò������ڶ����Ǹ�����ʼλ�ò������ȡ���� 
		size_t pos = temp.find("]");
		incantation = temp.substr(0, pos + 1);
		function = temp.substr(pos + 2);
		
		
		findByIncantation.insert(pair<string, string>(incantation, function));
		findByFunction.insert(pair<string, string>(function, incantation));
	}
	
	// ��Ϊcin�ѻ��з�����������е��У�������������еĵ�һ��getline��ʵ����ֱ�Ӷ�ȡ��һ�����з���Ȼ���
	// ���з���������'\0'���ʵ�һ�ζ�����ַ�����һ���մ�
	// �������cin.get()��ǰ�����з���ȡ 
	int test = 0;  cin >> test; 
	char ch = ' ';  cin.get(ch); 
	
	string s = " ";
	vector<string> ans;
	for (int times = 1; times <= test; times++) {
		getline(cin, s); // ÿ������Ŀ��ܶ���һ���ַ��� 
		if (findByFunction.find(s) == findByFunction.end() && findByIncantation.find(s) == findByIncantation.end()) {
			ans.push_back("what?");
		}
		else if (findByFunction.find(s) != findByFunction.end()) {
			s = findByFunction[s];
			// ��ħ���е�'[]'�޳� 
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
