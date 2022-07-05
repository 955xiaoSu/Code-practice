#include <iostream>
#include <map>
using namespace std;

int main() {
	int test = 0;  cin >> test;
	map<int, int> counts;
	
	int serialNum = 0, score = 0;
	int maximumNum = 0, maximumScore = 0;
	for (int times = 1; times <= test; times++) {
		cin >> serialNum >> score;
		counts[serialNum] += score;
		if (counts[serialNum] > maximumScore) {
			maximumScore = counts[serialNum];
			maximumNum = serialNum;
		}
	}
	
	cout << maximumNum << " " << maximumScore;
	return 0;	
}
