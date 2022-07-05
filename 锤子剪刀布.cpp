// 统计输赢平没问题，赢的时候需要记录一下用什么手势赢的

#include <iostream>
using namespace std;

struct Record {
	int win;
	int lose;
	int tie;
	int winWithC, winWithJ, winWithB;
	Record() {
		win = lose = tie = 0;
		winWithC = winWithJ = winWithB = 0;
	}
};

int main() {
	int test = 0;  cin >> test;
	Record firstParty, secondParty;
	char gestureFirst = ' ', gestureSecond = ' ';
	
	for (int times = 1; times <= test; times++) {
		cin >> gestureFirst >> gestureSecond;
		
		if (gestureFirst == 'C') {
			if (gestureSecond == 'C') {
				firstParty.tie++;
				secondParty.tie++;
			}
			else if (gestureSecond == 'B') {
				firstParty.lose++;
				secondParty.win++;
				secondParty.winWithB++;
			}
			else {
				secondParty.lose++;
				firstParty.win++;
				firstParty.winWithC++;
			}
		}
		
		else if (gestureFirst == 'B') {
			if (gestureSecond == 'C') {
				secondParty.lose++;
				firstParty.win++;
				firstParty.winWithB++;
			}
			else if (gestureSecond == 'B') {
				firstParty.tie++;
				secondParty.tie++;
			}
			else {
				firstParty.lose++;
				secondParty.win++;
				secondParty.winWithJ++;
			}
		}
		
		else {
			if (gestureSecond == 'C') {
				firstParty.lose++;
				secondParty.win++;
				secondParty.winWithC++;
			}
			else if (gestureSecond == 'B') {
				secondParty.lose++;
				firstParty.win++;
				firstParty.winWithJ++;
			}
			else {
				firstParty.tie++;
				secondParty.tie++;
			}
		}
	}
	
	cout << firstParty.win << " " << firstParty.tie << " " << firstParty.lose << endl;
	cout << secondParty.win << " " << secondParty.tie << " " << secondParty.lose << endl;
	
	int maximum = firstParty.winWithB >= firstParty.winWithC ? firstParty.winWithB : firstParty.winWithC;
	int finalAns = maximum >= firstParty.winWithJ ? maximum : firstParty.winWithJ;
	if (firstParty.winWithB == finalAns) cout << "B" << " ";
	else if (firstParty.winWithC == finalAns) cout << "C" << " ";
	else cout << "J" << " ";
	
	maximum = secondParty.winWithB >= secondParty.winWithC ? secondParty.winWithB : secondParty.winWithC;
	finalAns = maximum >= secondParty.winWithJ ? maximum : secondParty.winWithJ;
	if (secondParty.winWithB == finalAns) cout << "B";
	else if (secondParty.winWithC == finalAns) cout << "C";
	else cout << "J";
	
	return 0;
} 
