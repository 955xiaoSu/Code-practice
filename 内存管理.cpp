// ʵ����������Ķ�̬����
// alloc�ò�ѯ������һ��ָ��ָ���ѷ����ڴ����һλ
// erase��ָ��Ŀ��ڴ��ͷ�
// erase����Ϊdefragment���񣬽�֮ǰerase�Ĵ�����ڴ油�䵽vector�����ĺ�����
// ��Ҫһ��ָ���¼���䵽������
// ��ͬһ��vector<bool>�����ڴ�������һ��vector<string>�洢��
// �����ֲ�����װ���� 
// alloc�Լ�erase��������д�ĳ��򲻹��Ͻ�
// ��д ������ʵʵ�������еĹ����
// ��һ��struct��¼��š��ڴ��С����ʼλ�� 

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

// ���ܣ������ִ�int����ת��Ϊstring���� 
string TransferIntToStr(int num) {
	stringstream sstream;
	sstream << num;
	string ans = sstream.str();
	return ans;
}

void DealAlloc(int& index, unsigned int& pointer, vector<string>& ans, vector<bool>& memory) {
	unsigned int occupy = 0;  cin >> occupy; // ���뱾��Ҫ������ڴ��С
	
	if (memory.size() - pointer >= occupy) {
		index++;
		digits[index].serialNum = index; digits[index].size = occupy;
		digits[index].startPos = pointer; digits[index].endPos = pointer + occupy - 1;
		
		for (unsigned int sub = pointer; sub < pointer + occupy; sub++) {
			memory[sub] = false; // ˵�����ڴ治���ٲ�������� 
		}

		pointer += occupy; // ʹָ��ָ��δ�����ڴ����λ 
		ans.push_back(TransferIntToStr(index)); // ���ڴ��ı�ŷ��ص����������� 
	} 
	else ans.push_back("NULL"); // ���ʣ���ڴ�ռ䲻��������NULL 
	return;
} 

void DealErase(vector<bool>& memory, vector<string>& ans, int index, unsigned int& pointer) {
	int serialNum = 0;  cin >> serialNum; // ����Ҫ�ͷŵ��ڴ��ı��

	if (serialNum > index || serialNum <= 0 || digits[serialNum].size == 0) { // û�д��ڴ�飬����erase����ʧ�� 
		ans.push_back("ILLEGAL_ERASE_ARGUMENT");
		return;
	}
	else {
		// �������ڴ���Ϊ���ò������ö�Ӧ�ڴ�����Ϣ 
		for (int pos = digits[serialNum].startPos; pos <= digits[serialNum].endPos; pos++) {
			memory[pos] = true;
		}
		digits[serialNum].endPos = digits[serialNum].startPos = digits[serialNum].size = 0;
		
		// Ҫ��pointer�������һλ
		for (unsigned int sub = memory.size() - 1; sub >= 0; sub--) {
			if (memory[sub] == true) {
				pointer = sub;
				break;
			} 
		}
		return;
	}
}

// �ҳ�true��false����������������pointer��λ�� 
void DealDefragment(vector<bool>& memory, unsigned int& pointer, int index) {
	pointer = 0;
	
	for (int sub = 1; sub <= index && digits[sub].size != 0; sub++) {
		digits[sub].startPos = pointer;
		digits[sub].endPos = pointer + digits[sub].size - 1;
		pointer += digits[sub].size; // ʵ���ڴ������ 
	}
	
	// �����ڴ������� 
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

	int index = 0; unsigned int pointer = 0; // index��¼�ڴ��ţ�pointerָ���ѷ����ڴ����һλ 
	string s; // ��¼��������� 
	vector<string> ans; // �洢������Ľ�� 
	vector<bool> memory(memorySize, true); // ģ���ڴ��� 
	digits = new MemoryManage[operands + 1]; // �����ڴ� 
	
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
 
