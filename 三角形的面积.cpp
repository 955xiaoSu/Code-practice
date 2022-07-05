// 怎么判断输入结束？ 利用while循环，计算三角形面积如果得到的结果是0，说明输入结束 
// 方法：利用向量叉乘解决三角形面积问题

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

struct Vector {
	double x;
	double y;
	Vector() {
		x = y = 0.0;
	}
};
int main() {
	double x1 = 0.0, x2 = 0.0, x3 = 0.0, y1 = 0.0, y2 = 0.0, y3 = 0.0;
	Vector temp1, temp2; // 向量叉乘需要两个向量 
	vector<double> ans;  ans.clear();
	
	while (1) {
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		temp1.x = x1 - x3;  temp1.y = y1 - y3;
		temp2.x = x1 - x2;  temp2.y = y1 - y2;
		if (x1 == 0 && x2 == 0 && x3 == 0 && y1 == 0 && y2 == 0 && y3 == 0)  break; 
		ans.push_back(abs((temp1.x * temp2.y) - (temp1.y * temp2.x)) / 2);
	}
	
	vector<double>::iterator it = ans.begin();
	for (; it != ans.end(); it++) {
		cout << fixed << setprecision(6) << *it << endl;
	} 
	return 0;
} 
