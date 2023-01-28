// map 映射，而后排序
// sort 只能对线性容器进行排序
// 因此将 map 容器中的数据重载到 vector 容器中 

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool CMP(const pair<unsigned int, unsigned int> &a,
		 const pair<unsigned int, unsigned int> &b) {
	if (a.second > b.second) return true;
	else if(a.second == b.second && a.first < b.first) return true; 
	return false; 
}

int main() {
	int num = 0; cin >> num;
	map<unsigned int, unsigned int> count;
	int digit = 0;
	for (int i = 1; i <= num; i++) {
		cin >> digit;
		count[digit]++;
	}
	
	map<unsigned int, unsigned int>::iterator it = count.begin();
	vector<pair<unsigned int, unsigned int> > ans;
	while (it != count.end()) {
		ans.push_back(make_pair(it->first, it->second));
		it++;
	}
	sort(ans.begin(), ans.end(), CMP);
	for (vector<pair<unsigned int, unsigned int> >::iterator iter = ans.begin();
		 iter != ans.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;	 	
	}
	return 0;
} 
