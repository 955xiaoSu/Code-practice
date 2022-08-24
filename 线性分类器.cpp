// 对于每一条直线应该是一个公式
// 用一个函数把公式判定包装起来
// 在每条直线给出后，认定A、B，如果点之间相互冲突或AB判定有冲突则终止本次判定
// 用结构体存储点的信息 
// 用结果与状态相乘，如果大于0为正确，否则为错误
 
#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int x, y;
	char state;
	Node() {
		x = y = 0;
		state = ' ';
	}
};

int main() {
	int nodeNum = 0, lineNum = 0; 
	cin >> nodeNum >> lineNum;
	Node* digits = new Node[nodeNum];
	for (int times = 0; times < nodeNum; times++) {
		cin >> digits[times].x >> digits[times].y >> digits[times].state;
	}
	vector<string> ans(lineNum, "Yes"); // 预先认定所有直线都满足划分条件 
	
	int parameter1 = 0, parameter2 = 0, parameter3 = 0; // 分别代表直线的三个参数 
	for (int times = 0; times < lineNum; times++) {
		cin >> parameter1 >> parameter2 >> parameter3;
		// 利用点的类别进行判定，同类型点带入Judge结果相乘为正，反之为负 
		for (int index = 0; index < nodeNum; index++) {
			char kindFirst = 'a', kindSecond = 'b';
			int result = parameter1 + parameter2 * digits[index].x + parameter3 * digits[index].y;
			if (result > 0) {
				kindFirst = digits[index].state;
			}
			else  kindSecond = digits[index].state;
			if (kindFirst == kindSecond) {
				ans[times] = "No";
				break;
			}
		}
	}
	
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	} 
	return 0;
}
