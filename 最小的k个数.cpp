#include <iostream>
#include <queue>
using namespace std;

int main() {
	int total = 0, numNeed = 0;  cin >> total >> numNeed;
	int temp = 0;
	priority_queue<int> myqueue;

	// ǰ��numNeedԪ�ؿ϶�����������
	for (int times = 1; times <= numNeed; times++) {
		cin >> temp;
		myqueue.push(temp);
	}
	// ���Ƚϴ��Ԫ���޳������У����Ƚ�С��Ԫ�ؼ��뵽���е���
	for (int times = 1; times <= total - numNeed; times++) {
		cin >> temp;
		if (temp < myqueue.top())
			myqueue.pop();
		myqueue.push(temp);
	}

	int* ans = new int[numNeed];
	for (int sub = numNeed - 1; sub >= 0; sub--) {
		ans[sub] = myqueue.top();
		myqueue.pop();
	}

	for (int sub = 0; sub < numNeed; sub++) {
		cout << ans[sub] << " ";
	}
	return 0;
}