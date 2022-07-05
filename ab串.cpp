#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 5010;

int main() {
	char s[maxn];
	int fa[maxn];
	scanf("%s", s + 1);  int n = strlen(s + 1);
	for (int i = 1; i <= n; i++) fa[i] = fa[i - 1] + (s[i] == 'a'); // ��ȡ������a�ĳ��� 
	int ans = fa[n];
	for (int i = 1; i <= n; i++) { // ��̬�滮 
		for ( int j = i; j <= n; j++) {
			ans = max(ans, fa[i - 1] + (fa[n] - fa[j]) + (j - i + 1 - (fa[j] - fa[i - 1])));
		}
	} 
	printf("%d\n", ans);
	return 0;
}
