// 实现三个命令的动态交互
// alloc得查询，得有一个指针指向已分配内存的下一位
// erase将指向的块内存释放
// erase可以为defragment服务，将之前erase的代码块内存补充到vector容器的后米娜
// 需要一个指针记录分配到哪里了
// 用同一个vector<bool>当作内存条，用一个vector<string>存储答案
// 将三种操作封装起来 
// alloc以及erase两个操作写的程序不够严谨
// 重写 就老老实实按照所有的规矩来
// 用一个struct记录编号、内存大小、起始位置 

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

struct MemoryManage {
	int serialNum;
	int size;
	int startPos;
	int endPos;
	MemoryManage() {
		serialNum = size = startPos = endPos = 0;
	}
};

MemoryManage* digits;

// 功能：将数字从int类型转换为string类型 
string TransferIntToStr(int num) {
	stringstream sstream;
	sstream << num;
	string ans = sstream.str();
	return ans;
}

void DealAlloc(int& index, unsigned int& pointer, vector<string>& ans, vector<bool>& memory) {
	unsigned int occupy = 0;  cin >> occupy; // 输入本次要分配的内存大小
	
	if (memory.size() - pointer >= occupy) {
		index++;
		digits[index].serialNum = index; digits[index].size = occupy;
		digits[index].startPos = pointer; digits[index].endPos = pointer + occupy - 1;
		
		for (unsigned int sub = pointer; sub < pointer + occupy; sub++) {
			memory[sub] = false; // 说明此内存不能再参与分配了 
		}

		pointer += occupy; // 使指针指向未分配内存的首位 
		ans.push_back(TransferIntToStr(index)); // 将内存块的编号返回到答案容器当中 
	} 
	else ans.push_back("NULL"); // 如果剩余内存空间不够，返回NULL 
	return;
} 

void DealErase(vector<bool>& memory, vector<string>& ans, int index, unsigned int& pointer) {
	int serialNum = 0;  cin >> serialNum; // 输入要释放的内存块的编号

	if (serialNum > index || serialNum <= 0 || digits[serialNum].size == 0) { // 没有此内存块，所有erase命令失败 
		ans.push_back("ILLEGAL_ERASE_ARGUMENT");
		return;
	}
	else {
		// 将所有内存置为可用并且重置对应内存块的信息 
		for (int pos = digits[serialNum].startPos; pos <= digits[serialNum].endPos; pos++) {
			memory[pos] = true;
		}
		digits[serialNum].endPos = digits[serialNum].startPos = digits[serialNum].size = 0;
		
		// 要将pointer移向最后一位
		for (unsigned int sub = memory.size() - 1; sub >= 0; sub--) {
			if (memory[sub] == true) {
				pointer = sub;
				break;
			} 
		}
		return;
	}
}

// 找出true与false的数量，并且重置pointer的位置 
void DealDefragment(vector<bool>& memory, unsigned int& pointer, int index) {
	pointer = 0;
	
	for (int sub = 1; sub <= index && digits[sub].size != 0; sub++) {
		digits[sub].startPos = pointer;
		digits[sub].endPos = pointer + digits[sub].size - 1;
		pointer += digits[sub].size; // 实现内存的重置 
	}
	
	// 重置内存分配情况 
	for (unsigned int sub = 0; sub < pointer; sub++) {
		memory[sub] = false;
	}
	for (unsigned int sub = pointer; sub < memory.size(); sub++) {
		memory[sub] = true;
	}
	return;
}


int main() {
	int operands = 0, memorySize = 0; 
	cin >> operands >> memorySize;

	int index = 0; unsigned int pointer = 0; // index记录内存编号，pointer指向已分配内存的下一位 
	string s; // 记录输入的命令 
	vector<string> ans; // 存储命令反馈的结果 
	vector<bool> memory(memorySize, true); // 模拟内存条 
	digits = new MemoryManage[operands + 1]; // 管理内存 
	
	while (operands--) {
		cin >> s; 
		if (s == "alloc") DealAlloc(index, pointer, ans, memory);
		else if (s == "erase") DealErase(memory, ans, index, pointer);
		else {
			DealDefragment(memory, pointer, index);
		}
	} 
	
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
} 
 
