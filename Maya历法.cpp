#include <iostream>
#include <string>
using namespace std;

inline int read() {
	int ret = 0, sign = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') sign = -1; ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		ret = ret * 10 + ch - '0'; ch = getchar();
	}
	return ret *sign;
}

// Haab
string haa[19]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

// Tzolkin
string tzo[20]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int getMonth(string s) {
	for (int i = 0; i < 19; i++) {
		if (s == haa[i]) return i + 1;
 	}
	return 0;
}
int main() {
	int test = 0;  cin >> test;
	string month;
	int day = 0, year = 0, totDay = 0;
	while (test--) {
		day = read();
		cin >> month;
		int year = read();
		int totDay = year * 365 + (getMonth(month) - 1) * 20 + day;
		
		year = totDay / 260; totDay %= 260;
		int x = 0, y = 0;
		while (totDay) {
			x = (x + 1) % 20;
			y = (y + 1) % 13;
			totDay--;
		}
		cout << y + 1 << " " << tzo[x] << " " << year << endl;
	}
	return 0;
}
