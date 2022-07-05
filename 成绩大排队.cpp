#include <iostream>
#include <string>
using namespace std;

struct Student {
	int score;
	string name;
	string studentNum;
	Student() {
		score = 0;
		name = " "; studentNum = " ";
	}
};

int main() {
	int test = 0;  cin >> test;
	Student highest, lowest;
	
	cin >> highest.name >> highest.studentNum >> highest.score;
	cin >> lowest.name >> lowest.studentNum >> lowest.score;
	
	Student temp;
	if (lowest.score > highest.score) {
		temp = lowest;
		lowest = highest;
		highest = temp;
	}
	
	for (int times = 1; times <= test - 2; times++) {
		cin >> temp.name >> temp.studentNum >> temp.score;
		if (temp.score > lowest.score && temp.score < highest.score)
			continue;
		else if  (temp.score > highest.score) highest = temp;
		else lowest = temp;  
	}
	
	cout << highest.name << " " << highest.studentNum << endl;
	cout << lowest.name << " " << lowest.studentNum;
	return 0;
}
