#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int count = 0; // 记录每一轮的逆序数

// 功能：利用归并算法统计逆序数
// 参数：原数组A，空的临时数组tmp，数组起始下标，数组终止下标
// 返回值类型：None
void MergeSort(int* A, int* tmp, int left, int right) {
	if (left == right)  return;   // 递归终止条件
	int mid = (left + right) / 2;
	// 分治法中的“分”
	MergeSort(A, tmp, left, mid);
	MergeSort(A, tmp, mid + 1, right);
	// 分治法中的“治”，此时数组分为各自有序的左右两个数组
	// 逆序数为0的情况是，左数组最大元素比右数组最小元素小
	int leftStart = left, leftEnd = mid, rightStart = mid + 1, rightEnd = right;
	int curr = left;
	while (leftStart <= leftEnd && rightStart <= rightEnd) {
		if (A[leftStart] <= A[rightStart])  tmp[curr++] = A[leftStart++];
		else {
			count += leftEnd - leftStart + 1; // 当左数组元素大于右数组元素时，逆序数产生
			tmp[curr++] = A[rightStart++];
		}
	}
	while (leftStart <= leftEnd)  tmp[curr++] = A[leftStart++];    // 考虑到左数组有剩余元素
	while (rightStart <= rightEnd)  tmp[curr++] = A[rightStart++]; // 考虑到右数组有剩余元素
	for (int index = right; index >= left; index--) { // 将临时数组中的元素复制回原数组
		A[index] = tmp[index];
	}
	return;
}

int main() {
	vector<int> ans; // 记录答案的容器
	int num = 0;     // 每组测试数据的个数
	while (cin >> num) {
		if (num == 0)  break;
		int* digits = new int[num];
		for (int index = 0; index < num; index++) {
			cin >> digits[index];
		}
		int* tmp = new int[num];
		memset(tmp, 0, sizeof(int) * num); // 将临时数组初始化为0
		MergeSort(digits, tmp, 0, num - 1);
		ans.push_back(count);
		count = 0;
		delete []tmp;
		delete []digits;
	}
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
