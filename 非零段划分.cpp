// 什么时候用差分法？
// 处理范围数据并且需要以空间换时间
// 节省时间的原因是：多次重复赋值 -> 单次赋值
// 开辟差分数组，并进行前缀和

#include <iostream>
using namespace std;

const int N = 1e6;
int diff[N], digit[N];

void add(int left, int right) {diff[left]++, diff[right + 1]--;} // 差分重新赋值的精髓

int main() {
    int n = 0;  cin >> n;
    for (int index = 1; index <= n; index++) cin >> digit[index];
    for (int index = 1; index <= n; index++) {
	if (digit[index - 1] < digit[index] { // 说明取二者之间的中间数时，会出现非零段
	    add(digit[index - 1] + 1, digit[index]);
	}
    }
    int maxn = 0, count = 0;
    for (int num = 1; num < 1e4; num++) {
    	count += diff[num]; // 累加法，取范围内重叠部分的数值
	maxn = max(maxn, count);
    }
    cout << maxn;
    return 0;
}
