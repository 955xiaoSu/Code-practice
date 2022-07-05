// 用一个vector模拟座位情况
// 用一个struct模拟某个id的占座情况，开始位置，结束位置

#include <vector>
#include <iostream>
using namespace std;

struct People {
	int id;
	int startPos;
	int endPos;
	int size;
	bool haveSeat;
	People() {
		size = id = startPos = endPos = 0;
		haveSeat = false;
	}
}; 

int main() {
	int row = 0, totalPeople = 0, orders = 0;
	vector<string> ans;
	vector<int> numsPut;
	string s;
	unsigned int id = 0, dealSeats = 0, pointer = 0;
	while (cin >> row >> totalPeople >> orders) {
		numsPut.push_back(orders);
		vector<bool> seats(row * row, true);
		People* persons = new People[totalPeople + 1];
		for (int sub = 1; sub <= totalPeople; sub++) {
			persons[sub].id = sub;
		}
		for (int times = 1; times <= orders; times++) {
			cin >> s >> id;
			// 输入的是占座命令 
			if (s == "in") {
				cin >> dealSeats;
				if (seats.size() - pointer >= dealSeats && !persons[id].haveSeat) {
					persons[id].size = dealSeats;
					persons[id].startPos = pointer;
					persons[id].endPos = pointer + dealSeats - 1;
					for (unsigned int index = pointer; index < pointer + dealSeats; index++)
						seats[index] = false;
					pointer += dealSeats;
					persons[id].haveSeat = true;
					ans.push_back("yes");
				}
				// 可能是请求的座位数超标，可能是已经占过座了 
				else {
					//cout << "Request much or before!" << endl;
					ans.push_back("no");
				}
			}
			// 输入的是释放座位命令 
			else {
				// 此人未占过座 
				if (!persons[id].haveSeat) {
					//cout << "He didn't do it before!" << endl;
					ans.push_back("no");
				}
				// 此人曾经占过座 
				else {
					persons[id].haveSeat = false;
					for (int index = persons[id].startPos; index <= persons[id].endPos; index++) 
						seats.push_back(true);
					persons[id].size = 0;
					ans.push_back("yes");
				}
			} 
		}
	}
	vector<int>::iterator nums = numsPut.begin();
	vector<string>::iterator answer = ans.begin();
	for (; nums != numsPut.end(); nums++) {
		for (int times = 1; times <= *nums; times++, answer++) {
			cout << *answer << endl;
		}
	}
	//cout << endl << "ans's size : " << ans.size();
	return 0;
}
