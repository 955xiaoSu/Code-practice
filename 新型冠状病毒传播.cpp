// ֻ���ٶȲ������������õģ�
// ������˼�������������˼������ô���ǽ��з�������� 
 
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
	int total = 0, infected = 0; //total������������infected�����Ⱦ�¹ݲ������˵ı�� 
	cin >> total >> infected;
	Runner *run = new Runner[total+1];
	
	for(int i = 1; i <= total; i++)  cin >> run[i].site;
	for(int i = 1; i <= total; i++)  cin >> run[i].speed;
	
	int count = 0, maxV = 0, minV = run[infected].speed; //count���������ж�����û����Ⱦ maxV��minV�ֱ����������ٶ�����С�ٶ� 
	for(int i = 1; i <= total; i++){
		if(run[i].speed > run[infected].speed && run[i].speed > maxV && run[i].site <= run[infected].site)  maxV = run[i].speed; // ��¼����Ⱦ���ߵ�����ٶ� 
		if(run[i].site >= run[infected].site && run[i].speed < minV)  minV = run[i].speed; // ��¼����Ⱦ���ߵ�����ٶ� 
	}
	for(int i=1; i<=total; i++){
		if(run[i].speed <= minV && run[i].site < run[infected].site)   count++;
		if(run[i].site > run[infected].site && run[i].speed >= maxV)   count++;
	} 
	
	cout << total - count;
	delete run;  run = NULL;
	return 0;
} 
