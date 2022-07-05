// ���𰸴洢��vector<int>�������У����ù鲢�㷨���������������Կռ任ʱ�� 

#include <iostream>
#include <vector>
using namespace std;

int counts = 0;

// �鲢�����ʱ�临�Ӷ���nlogn��Ϊʲô�أ�
// ���ȵõݹ�logn�Σ����ÿ�κϲ���ʱ�临�Ӷȶ���n����Ϊÿ�����ֶ��ᱻ����һ��  
void MergeSort(int A[], int temp[], int left, int right) {
    if (left == right) return; // �ݹ��������
 	// ���η��е�"��"
 	int mid = (left + right) / 2; 
 	MergeSort(A, temp, left, mid);
 	MergeSort(A, temp, mid + 1, right);
 	// ���η��е�"��"
 	int leftPos = left, leftEnd = mid, rightPos = mid + 1, rightEnd = right; // �趨����ı߽����
 	int curr = left; // ��¼��ǰ����Ԫ���±�
 	while (leftPos <= leftEnd && rightPos <= rightEnd) { // ����ָ��СԪ�ط���temp������
    	if (A[leftPos] <= A[rightPos]) temp[curr++] = A[leftPos++];
     	else {
     	 	counts += (leftEnd - leftPos + 1); // ������ͳ�� 
     	 	temp[curr++] = A[rightPos++];
		}
 	}
 	while (leftPos <= leftEnd) temp[curr++] = A[leftPos++]; // ���ǵ���������ʣ��Ԫ��
 	while (rightPos <= rightEnd) temp[curr++] = A[rightPos++]; // ���ǵ���������ʣ��Ԫ��
 	for (int i = right; i >= left; i--) { // ��������ƻ�A������
    	A[i] = temp[i];
 	}
 	return;
}

int main() {
	vector<int> ans;
	int num = 0;
	
	while (cin >> num) {
		if (num == 0) break;
		int* digits = new int[num];
		for (int index = 0; index < num; index++) {
			cin >> digits[index];
		}
		
		int* temp = new int[num];
		MergeSort(digits, temp, 0, num - 1);
		ans.push_back(counts);
		counts = 0;
	}
	
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
