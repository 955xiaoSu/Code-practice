// ��vector�洢��
// ���ڿ���ֱ��ͨ��ȡģ�õ�
// ʣ�µľͷֱ�ȡ��ݣ��ж��Ƿ�Ϊ���꣩��ȡ�·ݡ�ȡ����
// �������·�ʹ��һ��map��Ӧ

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

void Initial(map<int, string>& dayToWeek) {
	int allDay[7] = {1, 2, 3, 4, 5, 6, 7};
	string dayOfWeek[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday", "Sunday"};
	for (int index = 0; index < 7; index++) {
		dayToWeek.insert(pair<int, string>(allDay[index], dayOfWeek[index]));
	}
	return;
}

void Init(map<int, int>& monthToDay) {
	int allMonth[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int dayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int index = 0; index < 12; index++) {
		monthToDay.insert(pair<int, int>(allMonth[index], dayOfMonth[index]));
	}
	return;
}

string IntToStr(int num) {
	stringstream sstream;
	sstream << num;
	string s = sstream.str();
	return s;
}

inline bool isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
	else return false;
}

int main() {
	vector<string> date, week;
	map<int, string> dayToWeek;
	Initial(dayToWeek);
	map<int, int> monthToDay;
	Init(monthToDay);
	int gap = 0, day = 1, month = 1, year = 2000, transWeek = 0;
	// ע�⴦�����ڡ�����
	while (cin >> gap) {
		if (gap == -1) break;
		transWeek = (gap + 6) % 7;
		day = 1; month = 1; year = 2000; // �ظ�ʹ�ñ���һ��Ҫ�ǵó�ʼ�� 
		if (transWeek == 0) transWeek = 7;
		week.push_back(dayToWeek[transWeek]);
		// �������
		while (gap >= 366) {
			if (isLeapYear(year))  { 
				//cout << year << " abnormal year" << endl; 
				gap -= 366; 
			}
			else {
				//cout << year << " normal year" << endl;
				gap -= 365;
			}
			year++;
		}
		if (gap == 365 && !isLeapYear(year)) {
			gap -= 365;
			year++;
			month = 1; day = 1;
		}
		// ��������������� 
		if (isLeapYear(year)) {
			monthToDay[2] = 29;
			for (int temp = 1; temp <= 12; temp++) { // ע���·� 
				// �п��ܻ�������� 
				if (gap > monthToDay[temp]) {
					gap -= monthToDay[temp];
					month++;
					//cout << "gap : " << gap << endl;
				}
				else {
					//cout << "this time gap : " << gap << endl;
					day += gap;
					if (day > monthToDay[temp]) {
						month++;
						day -= monthToDay[temp];
					}
					break;
				}
			}
			monthToDay[2] = 28;
		} 
		// ���������������� 
		else { 
			for (int temp = 1; temp <= 11; temp++) {
				if (gap > monthToDay[temp]) {
					gap -= monthToDay[temp];
					month++;
				}
				else {
					day += gap;
					if (day > monthToDay[temp]) {
						month++;
						day -= monthToDay[temp];
					}
					break;
				}
			}
		}
		// �����ʽ 
		string tempMonth = " ", tempDay = " ";
		tempMonth = IntToStr(month); if (tempMonth.length() == 1) tempMonth = "0" + tempMonth;
		tempDay = IntToStr(day); if (tempDay.length() == 1) tempDay = "0" + tempDay;
		
		date.push_back(IntToStr(year) + "-" + tempMonth + "-" + tempDay);
	}
	vector<string>::iterator DATE = date.begin();
	vector<string>::iterator WEEK = week.begin();
	for (; DATE != date.end(); DATE++, WEEK++) {
		cout << *DATE << " " << *WEEK << endl;
	}
	return 0;
}
