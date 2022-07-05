// ���ȼ�˳�򣺸�������(ס�����Ϊ0���籣���ɱ��볬��2��) > ����������(ס���������0)
// �������󣺽����籣�����������ȡ��걨ʱ����������
// ������������������ס�����С�����ȡ��걨ʱ����������
// ���ݹ����������������ͬ���������
// ��Ϊ�������ݹ�ģʮ���Ӵ���map������ӳ�� 
// �����ڲ��ܶ�ԭ�е�struct���и���
// �����ұ�������֤�Ŷ�Ӧ���˽�������

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

struct people {
    char id[19]; // ���֤���� 
    int social;  // �籣�������� 
    int area; // ����ס����� 
    char date[11]; // �걨���� 
};

people* getMess(int &n);

string intToStr(int num) {
	stringstream sstream;
	sstream << num;
	string ans = sstream.str();
	return ans;
}

// ���ܣ����ش��������ֵõ��Ľ��  
string Feedback(int& rank, int& totalHouse, people person[], int n, map<string, int> idToRank) { // rankΪ�����֤�����˶�Ӧ������ 
	// ���ж��ڸ�����ǰһ���ж����ˣ����ж�ͬ�����ж����� 
	int sameCount = 0, beforeCount = 0;
	for (int index = 0; index < n; index++) {
		if (idToRank[person[index].id] < rank) beforeCount++;
		else if (idToRank[person[index].id] == rank) sameCount++;
		else break;
	}
	
	// û������빺�� 
	if (beforeCount >= totalHouse || rank == 0) return "Sorry";
	else {
		// �и����ܲ��빺�� 
		if (beforeCount < totalHouse && sameCount + beforeCount > totalHouse) {
			string s1 = intToStr(totalHouse - beforeCount);
			string s2 = intToStr(sameCount);
			return (s1 + "/" + s2);
		}
		// һ���ܲ��빺�� 
		else {
			if (sameCount == 1) {
				return intToStr(beforeCount + 1);
			}
			else return (intToStr(beforeCount + 1) + " " + intToStr(sameCount));
		}
		
	}
}

// ���ܣ�����ת������Ϊ��λ 
int ChangeToDay(char c[]) {
	int year = 0, month = 0, day = 0;
	int result = 0;
	
	month = (c[0] - '0') * 10 + c[1] - '0';
	day = (c[3] - '0') * 10 + c[4] - '0';
	year = (c[6] - '0') * 1000 + (c[7] - '0') * 100 + (c[8] - '0') * 10 +  c[9] - '0';
	result = year * 365 + month * 30 + day;
	return result;
}

// ���ܣ������ȼ��ߵĹ������������鿿ǰλ�� 
// ����Ӳ������ / ������������� / ������Ҫ��������л��� 
bool cmp(people first, people second) {
	// �ȰѲ�����Ҫ���ȫ������ 
	if (first.area == 0 && first.social < 24) return false;
	else if (second.area == 0 && second.social < 24) return true;
	
	// ���ͬΪ�������� 
	else if (first.area == 0 && second.area == 0) {
		if (first.social != second.social) {
			return first.social > second.social;
		}
		else {
			int firstDay = ChangeToDay(first.date);
			int secondDay = ChangeToDay(second.date);
			return firstDay < secondDay;
		}
	}
	
	// ���ͬΪ���������� 
	else if (first.area != 0 && second.area != 0) {
		if (first.area != second.area) {
			return first.area < second.area;
		}
		else {
			int firstDay = ChangeToDay(first.date);
			int secondDay = ChangeToDay(second.date);
			return firstDay < secondDay;
		}
	}
	
	// ���һ��Ϊ��������һ��Ϊ����������
	else if (first.area == 0 && second.area != 0) {
		return true;
	} 
	else if (first.area != 0 && second.area == 0) {
		return false;	
	}
}

// ���ܣ����������������߽������� 
void RankAllPeople(map<string, int>& idToRank, int n, people person[]) {
	sort(person, person + n, cmp);
	// �±�С��������ǰ 
	for (int index = 0; index + 1 < n; index++) {
		// �������λ�ÿɽ�����˵������������ͬ 
		if (cmp(person[index], person[index + 1]) && cmp(person[index + 1], person[index])) {
			idToRank[person[index].id] = index + 1;
			idToRank[person[index + 1].id] = index + 1;
			continue;	
		}
		else idToRank[person[index].id] = index + 1;
	}
	return;
}

int main() {
	vector<string> ans;
	// ���txt�ļ����ݵĶ��룬����ȡ������������n 
    people *person; // ָ�����б����˵Ļ��������׵�ַ��ͨ�����ú���getMess��ȡ      
    int n; // nΪ����������ͨ�����ú���getMess��ȡ 
    person = getMess(n);
       
    // ʵ��logn����Ĳ�ѯ�ٶ�
    map<string, int> idToRank; // ʵ�ִ����֤��->������ӳ�� 
	RankAllPeople(idToRank, n, person); // �����й����߽������� 
       
    // ����������� 
  	int totalHouse = 0;  cin >> totalHouse;
  	int test = 0;  cin >> test;
  	 
  	string s = " ", result = " ";
  	while (test--) {
  		cin >> s;
		result = Feedback(idToRank[s], totalHouse, person, n, idToRank);
		//cout << endl <<  "rank : " << idToRank[s] << endl;
		ans.push_back(result);
	}
	
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
    return 0;
}

people* getMess(int &n) { // ���ļ����ݶ����ڴ� 
    FILE *fp;
    fp = fopen("house.bin", "rb");
    fseek(fp, -1*(long)sizeof(int), 2); // �ڶ��������ķ��ţ�����ǰ�ƣ����ź��ơ����һ��������whence����ζ�ŴӸ�λ�ÿ�ʼ���� 
    fread(&n, sizeof(int), 1, fp); // ��ȡ���� 
    rewind(fp); // �ص�����stream�ļ��Ŀ�ͷ 
    
    people *tmp = new people[n];
    fread(tmp, sizeof(people), n, fp);
    fclose(fp);
    return tmp;
}
