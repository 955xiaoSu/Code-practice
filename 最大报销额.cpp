#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<sstream>
using namespace std;

/*
允许报销的发票类型包括买ABC,有其他类，no！
要求每张发票的总额不得超过1000元，超过1000，no！
每张发票上，单项物品的价值不得超过600元。有超过600的，no！
【本质是个处理数据后的0-1背包问题】
*/

vector<double> v;
double dp(int n,double maxi) {         //装入前n个物体，容积为v
	if(n == 0) return 0;        //边界条件
	if(maxi >= v[n - 1] ) { //能装下当前物品，比较装和不装的大小
		return max( v[n - 1] + dp(n - 1, maxi - v[n - 1] ), dp(n - 1, maxi)) ;
	} 
	else { return dp(n - 1, maxi); }
}

int main() {
	double maximum = 0.0;
	int test = 0;
	while(cin>> maximum >> test) {
		if(test == 0) break;
		while(test--) {     //处理数据  n张发票
			int num;	cin >> num; // num个物品 
			double sum = 0.0;
			int flag = 1;
			while(num--) {
				string temp;	cin >> temp;
				char type=temp[0];
				string price = temp.substr(2, temp.size() - 2);
				if(type != 'A' && type != 'B' && type != 'C')  {//有不报销物品的单子丢掉
					flag = 0;
					break;
				}
				stringstream ss;  ss << price;
				double pri = 0.0;	ss >> pri;
				if (pri > 600) {  //单物品大于600的单子丢掉
					flag = 0;
					break;
				}
				sum += pri;
			}
			if(sum <= 1000 && flag && sum <= maximum) v.push_back(sum);
			//大于1千或者最大额度的单子，舍弃
		}
		double res = dp(v.size(), maximum); // 求出最大报销金额 
		if(v.size() == 0) res = 0.0;
		cout << fixed<< setprecision(2) << res << endl;
		v.clear();
	}
}
