#include <iostream>
using namespace std;

int main() {
	int test = 0;  cin >> test;
	int weight = 0, score = 0;
	int total = 0;
	for (int times = 0; times < test; times++) {
		cin >> weight >> score;
		total += weight * score;
	}
	if (total >= 0)  cout << total;
	else cout << "0";
	return 0;
} 
