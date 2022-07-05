// �����Ӧ�����ַ�������ȡ֮�󰴵�λ����һ��struct���ͽ��д洢
// �������ӵ�λ���λ��ʼ���������ͼ�һ

// ��Ȼ�ɹ�ʵ�֣����Ǿ����Լ��Ĵ���ʮ���߳�������������ʮ������
// ��������Բ�����ô��Ŀռ䣬ֱ��ʹ��int��¼ + string�Ľ�ȡ���ܾͿ������ 

#include <iostream>
#include <string>
using namespace std;

struct Money {
	int Galleon;
	int Sickle;
	int Knut;
	bool plus;
	Money() {
		Galleon = Sickle = Knut = 0;
		plus = true;
	}
}; 

// ���õ��Ĳ����ַ���ת��Ϊint 
inline int TransferStrToInt(string s) {
	int ans = 0, len = s.length();
	for (int index = 0; index < len; index++) {
		ans = ans * 10 + s[index] - '0';
	}
	return ans;
}

// ���ַ���ת��Ϊint���뵽Money���� 
void GetNum(Money& data, string& s) {
	string temp = " ";
	size_t site1 = s.find("."), site2 = s.find_last_of(".");
	
	// ����.�������ַ����Ľ�ȡ��Χ 
	temp = s.substr(0, site1);
	data.Galleon = TransferStrToInt(temp);
	
	temp = s.substr(site1 + 1, site2 - site1 - 1);
	data.Sickle = TransferStrToInt(temp);
	
	temp = s.substr(site2 + 1);
	data.Knut = TransferStrToInt(temp);
	
	return;
}

// ��ʼ�� 
void Input(Money& shouldPay, Money& actuallyPay, Money& change) {
	string s1 = " ", s2 = " ";
	cin >> s1 >> s2;
	
	GetNum(shouldPay, s1);
	GetNum(actuallyPay, s2);
	
	// ������Ǯ�Ĺ��̿�����ͳһת��ΪKnut��λ�������Knut��ת��Ϊ�������Ƶĵ�λ
	long long total1 = shouldPay.Knut + shouldPay.Sickle * 29 + shouldPay.Galleon * 29 * 17;
	long long total2 = actuallyPay.Knut + actuallyPay.Sickle * 29 + actuallyPay.Galleon * 29 * 17;
	long long ans = total2 >= total1 ? total2 - total1 : total1 - total2;
	
	change.plus = total2 >= total1 ? true : false; // �жϷ���
	int lowest = ans % 29;
	int middle = ans / 29;
	int highest = middle / 17;  middle = middle % 17;
	
	change.Knut = lowest;  change.Sickle = middle;  change.Galleon = highest;
	return;
}

int main() {
	Money shouldPay, actuallyPay, change;
	
	Input(shouldPay, actuallyPay, change);
	
	if (!change.plus) cout << "-";
	cout << change.Galleon << "." << change.Sickle << "." << change.Knut;
	return 0;
}
