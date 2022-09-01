// 将答案存储到vector<int>容器当中，采用归并算法排序并求逆序数，以空间换时间 
#include <iostream>
#include <vector>
using namespace std;
int counts = 0;

// 归并排序的时间复杂度是nlogn。为什么呢？
// 首先得递归logn次，其次每次合并的时间复杂度都是n，因为每个数字都会被遍历一遍  
void MergeSort(int A[], int temp[], int left, int right) {
    if (left == right) return; // 递归结束条件
 	// 分治法中的"分"
 	int mid = (left + right) / 2; 
 	MergeSort(A, temp, left, mid);
 	MergeSort(A, temp, mid + 1, right);
 	// 分治法中的"治"
 	int leftPos = left, leftEnd = mid, rightPos = mid + 1, rightEnd = right; // 设定数组的边界变量
 	int curr = left; // 记录当前数组元素下标
 	while (leftPos <= leftEnd && rightPos <= rightEnd) { // 将所指较小元素放入temp数组中
	    if (A[leftPos] <= A[rightPos]) temp[curr++] = A[leftPos++];
     	    else {
     	 	counts += (leftEnd - leftPos + 1); // 逆序数统计 
     	 	temp[curr++] = A[rightPos++];
	    }
 	}
 	while (leftPos <= leftEnd)  temp[curr++] = A[leftPos++];    // 考虑到左序列有剩余元素
 	while (rightPos <= rightEnd)  temp[curr++] = A[rightPos++]; // 考虑到右序列有剩余元素
 	for (int i = right; i >= left; i--) { 			    // 将结果复制回A数组中
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
