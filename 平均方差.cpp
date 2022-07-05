// ��һ��vector�洢���ݣ����ȼ���ƽ��ֵ����μ���ƽ���ͣ����������и���

#include <iostream>
#include <vector>
using namespace std;

int main() {
	double counts = 0;
	vector<int> ans;
	vector<double> temp;
	
	while (cin >> counts) {
		if (counts == 0)  break;
		
		// �������� 
		double sum = 0.0, occa = 0.0;
		temp.clear(); // �ǵ�ÿ��ʹ��֮ǰ����� 
		for (int times = 1; times <= counts; times++) {
			cin >> occa;  temp.push_back(occa);
			sum += occa;  
		}
		
		double average = sum / counts; // ��ƽ����
		
		double quadraticSum = 0.0; // ��ƽ���� 
		for (int index = 0; index < counts; index++) {
			quadraticSum += (temp[index] - average) * (temp[index] - average);
		}
		
		ans.push_back((int)(quadraticSum / counts));
	}
	
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
} 
