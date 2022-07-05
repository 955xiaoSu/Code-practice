#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<sstream>
using namespace std;

/*
�������ķ�Ʊ���Ͱ�����ABC,�������࣬no��
Ҫ��ÿ�ŷ�Ʊ���ܶ�ó���1000Ԫ������1000��no��
ÿ�ŷ�Ʊ�ϣ�������Ʒ�ļ�ֵ���ó���600Ԫ���г���600�ģ�no��
�������Ǹ��������ݺ��0-1�������⡿
*/

vector<double> v;
double dp(int n,double maxi) {         //װ��ǰn�����壬�ݻ�Ϊv
	if(n == 0) return 0;        //�߽�����
	if(maxi >= v[n - 1] ) { //��װ�µ�ǰ��Ʒ���Ƚ�װ�Ͳ�װ�Ĵ�С
		return max( v[n - 1] + dp(n - 1, maxi - v[n - 1] ), dp(n - 1, maxi)) ;
	} 
	else { return dp(n - 1, maxi); }
}

int main() {
	double maximum = 0.0;
	int test = 0;
	while(cin>> maximum >> test) {
		if(test == 0) break;
		while(test--) {     //��������  n�ŷ�Ʊ
			int num;	cin >> num; // num����Ʒ 
			double sum = 0.0;
			int flag = 1;
			while(num--) {
				string temp;	cin >> temp;
				char type=temp[0];
				string price = temp.substr(2, temp.size() - 2);
				if(type != 'A' && type != 'B' && type != 'C')  {//�в�������Ʒ�ĵ��Ӷ���
					flag = 0;
					break;
				}
				stringstream ss;  ss << price;
				double pri = 0.0;	ss >> pri;
				if (pri > 600) {  //����Ʒ����600�ĵ��Ӷ���
					flag = 0;
					break;
				}
				sum += pri;
			}
			if(sum <= 1000 && flag && sum <= maximum) v.push_back(sum);
			//����1ǧ��������ȵĵ��ӣ�����
		}
		double res = dp(v.size(), maximum); // ����������� 
		if(v.size() == 0) res = 0.0;
		cout << fixed<< setprecision(2) << res << endl;
		v.clear();
	}
}
