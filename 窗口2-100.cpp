// ʹ�ýṹ���Ǵ���
// ÿ�ص��ǰ�Դ��ڱ���һ�飬��֤����˳���Զ�����
// ���������Ƕ�����������б�� 

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int x1, x2, y1, y2;
	int window_num;
	int order;
	Node() {
		x1 = x2 = y1 = y2 = 0;
		order = 11;
		window_num = 11;
	}
}; 

bool cmp(Node a, Node b) { // ���� false ����λ�� 
	return a.order < b.order;
}

int main() {
	int window_num = 0, test_num = 0;
	cin >> window_num >> test_num;
	Node* digit = new Node[window_num + 1]; 
	for (int i = 1; i <= window_num; i++) {
		cin >> digit[i].x1 >> digit[i].y1 >> digit[i].x2 >> digit[i].y2;
		digit[i].window_num = i;
		digit[i].order = window_num - i + 1;
	} 
	
	int x = 0, y = 0;
	bool flag = false;
	for (int i = 1; i <= test_num; i++) {
		cin >> x >> y;
		flag = false;
		sort(digit + 1, digit + window_num + 1, cmp);
		for (int index = 1; index <= window_num; index++) {
			if (x >= digit[index].x1 && x <= digit[index].x2 
			 && y >= digit[index].y1 && y <= digit[index].y2) { // �ж����Ƿ����ڴ����������� 
			 	cout << digit[index].window_num << endl;
			 	flag = true;
			 	digit[index].order = 0;
			 	for (int j = 1; j <= index; j++) digit[j].order++; // ��[1, index]�Ĵ����������� 
			 	break;
			}
		}
		if (!flag) cout << "IGNORED" << endl;
	}
	return 0;
}

