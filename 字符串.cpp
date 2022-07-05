// 给定字符串，首先计算无序度，将字符串按无序度排序输出
// 使用struct类型，计算无序度单列一个方法，排序单列一个方法
#include <iostream>
#include <string>
using namespace std;

struct Data {
public:
	string s;
	int disorder;
	Data() {
		s = " ";  disorder = 0;
	}
}; 

int Calculate(string s, const int& length) {
	int count = 0;
	for (int sub = 0; sub < length - 1; sub++) {
		for (int sub2 = sub + 1; sub2 < length; sub2++) { // 一定要注意for循环的判断条件 
			if (s[sub] > s[sub2]) count++;
		}
	}
	return count;
}

void OrderAndOutput(Data* manageString, const int& numString) {
	for (int sub = 0; sub < numString - 1; sub++) {
		for (int sub2 = sub + 1; sub2 < numString; sub2++) {  
			if (manageString[sub].disorder > manageString[sub2].disorder) {
				Data temp = manageString[sub];
				manageString[sub] = manageString[sub2];
				manageString[sub2] = temp;
			} 
		}
	}
	
	for (int sub = 0; sub < numString; sub++) {
		cout << manageString[sub].s << endl;
	}
	
	return;
}

int main() {
	int lenString = 0, numString = 0;  cin >> lenString >> numString;
	Data* manageString = new Data[numString];
	
	for (int sub = 0; sub < numString; sub++) {
		cin >> 	manageString[sub].s;
		manageString[sub].disorder = Calculate(manageString[sub].s, lenString);
	}
	
	OrderAndOutput(manageString, numString);
	return 0;
}
