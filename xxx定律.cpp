#include <vector>
#include <iostream>
using namespace std;

int main() {
	int num = 0;  cin >> num;
	int count = 0;
	vector<int> ans;
	
	while (num != 0) {
		count = 0;
		while (num != 1) {
			count++;
			if (num % 2 == 0) num /= 2;
			else num = (3 * num + 1) / 2;
		}
		ans.push_back(count);
		cin >> num; 
	}
	
	vector<int>::iterator it = ans.begin();
	for (; it != ans.end(); it++) cout << *it << endl;
	return 0;
} 
