// ����������еķ�ֵ������������������ս��
// û��ô�򵥣�����Ҫ��ע���ٵ����������һ�����䷶Χ���Ǵ� 
// ��Ҫ��������������ѹ�������ը�� 
// ���Ի��������Ҳ���ƮƮȻ��ÿһ�ⶼҪ����Դ� 

#include <iostream>
using namespace std;

int main() {
	int numStations = 0, maxLoad = 0;
	cin >> numStations >> maxLoad;
	
	int peak = 0, minimum = 0, temp = 0, occa = 0; // peak��¼��ֵ��minimum����������Ҫ��������temp��¼�仯�� 
	for (int times = 1; times <= numStations; times++) {
		cin >> occa;
		temp += occa;
		if (temp > peak) peak = temp;
		if (temp < minimum) minimum = temp;
	}
	if (minimum < -maxLoad || peak > maxLoad) cout << 0;
	else cout << (maxLoad - peak) - (-minimum) + 1;
	return 0;
} 
