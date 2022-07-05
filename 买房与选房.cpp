// 优先级顺序：刚性需求(住房面积为0，社保缴纳必须超过2年) > 改善性需求(住房面积大于0)
// 刚性需求：缴纳社保月数多者优先、申报时间早者优先
// 改善性需求：现有自由住房面积小者优先、申报时间早者优先
// 根据规则进行排序，排名相同则输出区间
// 因为测试数据规模十分庞大，用map来快速映射 
// 我现在不能对原有的struct进行更改
// 但是我必须给身份证号对应的人进行排序

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

struct people {
    char id[19]; // 身份证号码 
    int social;  // 社保缴纳月数 
    int area; // 现有住房面积 
    char date[11]; // 申报日期 
};

people* getMess(int &n);

string intToStr(int num) {
	stringstream sstream;
	sstream << num;
	string ans = sstream.str();
	return ans;
}

// 功能：返回此排名该轮得到的结果  
string Feedback(int& rank, int& totalHouse, people person[], int n, map<string, int> idToRank) { // rank为该身份证所有人对应的排名 
	// 先判定在该排名前一共有多少人，再判定同排名有多少人 
	int sameCount = 0, beforeCount = 0;
	for (int index = 0; index < n; index++) {
		if (idToRank[person[index].id] < rank) beforeCount++;
		else if (idToRank[person[index].id] == rank) sameCount++;
		else break;
	}
	
	// 没机会参与购房 
	if (beforeCount >= totalHouse || rank == 0) return "Sorry";
	else {
		// 有概率能参与购房 
		if (beforeCount < totalHouse && sameCount + beforeCount > totalHouse) {
			string s1 = intToStr(totalHouse - beforeCount);
			string s2 = intToStr(sameCount);
			return (s1 + "/" + s2);
		}
		// 一定能参与购房 
		else {
			if (sameCount == 1) {
				return intToStr(beforeCount + 1);
			}
			else return (intToStr(beforeCount + 1) + " " + intToStr(sameCount));
		}
		
	}
}

// 功能：日期转换以日为单位 
int ChangeToDay(char c[]) {
	int year = 0, month = 0, day = 0;
	int result = 0;
	
	month = (c[0] - '0') * 10 + c[1] - '0';
	day = (c[3] - '0') * 10 + c[4] - '0';
	year = (c[6] - '0') * 1000 + (c[7] - '0') * 100 + (c[8] - '0') * 10 +  c[9] - '0';
	result = year * 365 + month * 30 + day;
	return result;
}

// 功能：将优先级高的购房者置于数组靠前位置 
// 按照硬性需求 / 满足改善性需求 / 不符合要求三类进行划分 
bool cmp(people first, people second) {
	// 先把不符合要求的全部后移 
	if (first.area == 0 && first.social < 24) return false;
	else if (second.area == 0 && second.social < 24) return true;
	
	// 如果同为刚性需求 
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
	
	// 如果同为改善性需求 
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
	
	// 如果一个为刚性需求一个为改善性需求
	else if (first.area == 0 && second.area != 0) {
		return true;
	} 
	else if (first.area != 0 && second.area == 0) {
		return false;	
	}
}

// 功能：对所有排名购房者进行排名 
void RankAllPeople(map<string, int>& idToRank, int n, people person[]) {
	sort(person, person + n, cmp);
	// 下标小的排名靠前 
	for (int index = 0; index + 1 < n; index++) {
		// 如果二者位置可交换，说明他们排名相同 
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
	// 完成txt文件数据的读入，并获取报名的总人数n 
    people *person; // 指向所有报名人的基本资料首地址，通过调用函数getMess获取      
    int n; // n为报名人数，通过调用函数getMess获取 
    person = getMess(n);
       
    // 实现logn级别的查询速度
    map<string, int> idToRank; // 实现从身份证号->排名的映射 
	RankAllPeople(idToRank, n, person); // 对所有购房者进行排名 
       
    // 输入测试数据 
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

people* getMess(int &n) { // 将文件数据读入内存 
    FILE *fp;
    fp = fopen("house.bin", "rb");
    fseek(fp, -1*(long)sizeof(int), 2); // 第二个参数的符号：负号前移，正号后移。最后一个参数是whence，意味着从该位置开始查找 
    fread(&n, sizeof(int), 1, fp); // 读取数据 
    rewind(fp); // 回到给定stream文件的开头 
    
    people *tmp = new people[n];
    fread(tmp, sizeof(people), n, fp);
    fclose(fp);
    return tmp;
}
