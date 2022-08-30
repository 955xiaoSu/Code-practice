// 一定要边写边测试 
#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int people = 0, continuity = 0, times = 0;  					 // people测试人数， continuity判定逗留的连续时刻，times测试时间数                      
	int  leftColumn = 0, leftRow = 0, rightColumn = 0, rightRow = 0; // 风险矩阵的左下与右上坐标 
	cin >> people >> continuity >> times >> leftColumn >> leftRow >> rightColumn >> rightRow;
	
	int* passCount = new int [people + 1];            // passCount经过人群统计，
	int* lingerCount = new int [people + 1];          // lingerCount逗留人群统计 
	memset(passCount, 0, sizeof(int) * (people + 1)); // 使用memset只能初始化为0 / -1，并且初始化大小不能用sizeof(pointer)，否则会导致只初始化一部分内存 
	memset(lingerCount, 0, sizeof(int) * (people + 1));
	
	int tmpColumn = 0, tmpRow = 0, tmpCount = 0; // tmpColumn，tmpRow临时坐标统计，tmpCount统计某人连续在风险矩阵的坐标数 
	for (int person = 1; person <= people; person++) {
		tmpCount = 0;
		for (int time = 1; time <= times; time++) {
			cin >> tmpColumn >> tmpRow;
			if (tmpColumn < leftColumn || tmpColumn > rightColumn)  { // 剔除纵坐标不符合的情况 
				tmpCount = 0;
				continue;
			}
			else if (tmpRow < leftRow || tmpRow > rightRow)  { // 剔除横坐标不符合的情况 
				tmpCount = 0;
				continue;
			}
			else { // 判定为经过人群 
				tmpCount++;
				passCount[person] = 1;
				if (tmpCount >= continuity) { // 如果满足连续坐标数大于times，则判定为逗留人群 
					lingerCount[person] = 1;
				}
			}
		}
	}
	
	int resultPass = 0, resultLinger = 0;
	for (int index = 1; index <= people; index++) {
		resultPass += passCount[index];
		resultLinger += lingerCount[index];
	}
	delete[] passCount;
	delete[] lingerCount;
	cout << resultPass << endl << resultLinger;
	return 0;
}
