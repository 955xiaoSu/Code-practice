// �����Ѿ��ṩ��ÿ�����ֵ�������Ҫ�����Ǹ����������������ھ�
// ���ǽ���������ӳ����±꣬Ȼ���������Σ��ֱ�洢��� 
// ֻ��Ҫ����ھ������ù���̫����Ϣ
// ��ô�ھ���ʲô���ģ� �÷���࣬������ǰ�����
// ���Ȱѵ÷�������������ǰ�������˸���� 

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct Player {
	string name;
	int integral; // ���� 
	map<int, int> rankToTimes; // ʵ�ִ�����->������ӳ�� 
	Player() { // ����ṹ�����ƣ��ǵ�ͬ���޸Ĺ��캯�� 
		integral = 0;	
		name = " ";
		rankToTimes.clear();
		for (int rank = 1; rank <= 100; rank++) {
			rankToTimes.insert(pair<int, int>(rank, 0));
		}
	} 
};

Player* digits;
int index;

bool cmp(Player first, Player second) {
	if (first.integral != second.integral) {
		return first.integral > second.integral;
	}
	else {
		// ��Ϊ����ֻ��֤��Ψһ�Ĺھ��������ܱ�֤��������ѡ������������� 
		for (int rank = 1; rank <= 100; rank++) {
			if (first.rankToTimes[rank] != second.rankToTimes[rank]) {
				return first.rankToTimes[rank] > second.rankToTimes[rank];
			}
		}
		return false;
	} 
}

bool CMP(Player first, Player second) {
	if (first.rankToTimes[1] != second.rankToTimes[1]) {
		return first.rankToTimes[1] > second.rankToTimes[1]; 
	}
	else if (first.integral != second.integral) {
		return first.integral > second.integral;
	}
	else return cmp(first, second);
}

void Init(map<int, int>& rankToIntegral) {
	rankToIntegral.insert(pair<int, int>(1, 25));
	rankToIntegral.insert(pair<int, int>(2, 18));
	rankToIntegral.insert(pair<int, int>(3, 15));
	rankToIntegral.insert(pair<int, int>(4, 12));
	rankToIntegral.insert(pair<int, int>(5, 10));
	rankToIntegral.insert(pair<int, int>(6, 8));
	rankToIntegral.insert(pair<int, int>(7, 6));
	rankToIntegral.insert(pair<int, int>(8, 4));
	rankToIntegral.insert(pair<int, int>(9, 2));
	rankToIntegral.insert(pair<int, int>(10, 1));
	for (int rank = 11; rank <= 100; rank++) {
		rankToIntegral.insert(pair<int, int>(rank, 0));		
	}
	return;
}

int main() {
	string ans;
	map<string, int> transfer; // ʵ�ֳ�����->�ṹ�������±��ӳ��
	map<int, int> rankToIntegral; // ʵ������->���ֵ�ӳ�� 
	Init(rankToIntegral);
	digits = new Player[101];
		
	int races = 0;  cin >> races; //cout << races << endl;
	index = 1;
	string temp;
	while (races--) {
		int playerNum = 0;  cin >> playerNum; //cout << playerNum << endl;
		
		for (int rank = 1; rank <= playerNum; rank++) {
			cin >> temp; //cout << temp << endl;
			if (transfer[temp] == 0) {
				transfer[temp] = index;
				digits[index].name = temp;
				index++;
			}
			digits[transfer[temp]].integral += rankToIntegral[rank];
			digits[transfer[temp]].rankToTimes[rank]++;
		}
	} 
	
	// ��ѵ��������δ��ȫͨ������ǰ�����еĲ��Զ�Ӧ��ע�͵�������ɾ����
	//cout << endl; 
	//for (int sub = 1; sub <= index; sub++) {
	//	if (digits[sub].integral == 0) break;
	//	cout << digits[sub].name << " " << digits[sub].integral << " " << digits[sub].rankToTimes[1] << endl;
	//}
	
	// �ó�ԭʼ����ھ� 
	sort(digits + 1, digits + 1 + index, cmp); 
	ans = digits[1].name;
	cout << ans << endl;
	
	// �ó���ѡ����ھ� 
	sort(digits + 1, digits + 1 + index, CMP);
	ans = digits[1].name;
	cout << ans;
	
	return 0;
} 
