#include <iostream>
using namespace std;

struct Data {
	int day;
	int money;
	Data() {
		day = money = 0;
	}
};

int Calculate(int day) {
	int basicDay = 1, count = 0;
	while (day > 0) {
		if (day >= basicDay) {
			count += basicDay * basicDay;
			day -= basicDay;
			basicDay++;
		}
		else {
			count += day * basicDay;
			break;
		}
	}
	return count;
}

int main() {
	Data knight[21];
	int sub = 0;
	
	while (cin >> knight[sub].day) {
		knight[sub].money = Calculate(knight[sub].day);
		sub++;
	}
	
	for (int i = 0; i < sub; i++) {
		cout << knight[i].day << " " << knight[i].money;
		cout << endl;
	}
	return 0;
}
