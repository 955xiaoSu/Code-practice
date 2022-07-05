// 只有速度才是真正起作用的！
// 这道题的思考就是正向很难思考，那么我们进行反向操作！ 
 
#include<iostream>
using namespace std;

struct Runner{
	int speed;
	int site;
	Runner() {
		speed = 0;
		site = 0;
	}
};

int main(){
	int total = 0, infected = 0; //total代表总人数，infected代表感染新馆病毒的人的编号 
	cin >> total >> infected;
	Runner *run = new Runner[total+1];
	
	for(int i = 1; i <= total; i++)  cin >> run[i].site;
	for(int i = 1; i <= total; i++)  cin >> run[i].speed;
	
	int count = 0, maxV = 0, minV = run[infected].speed; //count代表最终有多少人没被感染 maxV、minV分别代表了最快速度与最小速度 
	for(int i = 1; i <= total; i++){
		if(run[i].speed > run[infected].speed && run[i].speed > maxV && run[i].site <= run[infected].site)  maxV = run[i].speed; // 记录被感染患者的最快速度 
		if(run[i].site >= run[infected].site && run[i].speed < minV)  minV = run[i].speed; // 记录被感染患者的最快速度 
	}
	for(int i=1; i<=total; i++){
		if(run[i].speed <= minV && run[i].site < run[infected].site)   count++;
		if(run[i].site > run[infected].site && run[i].speed >= maxV)   count++;
	} 
	
	cout << total - count;
	delete run;  run = NULL;
	return 0;
} 
