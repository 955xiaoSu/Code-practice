#include <iostream>
#include <cstring>

inline int read() {
	char ch = getchar(); int ret = 0, sign = 1;
	while (ch < '0' || ch > '9') { if (ch == '-') sign = -1; ch = getchar();	}
	while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret * sign;
}

int main() {
	int total = read();
	char name[40];
	while (total) {
		memset(name, 0, sizeof(name));
		for (int times = 1; times <= 2 * total - 1; times++) {
			char temp[40];
			scanf("%s", temp);
			for (unsigned int index = 0; index < strlen(temp); index++) name[index] ^= temp[index];
		}
		for (unsigned int index = 0; index < 40 && name[index]; index++) putchar(name[index]);
		putchar('\n');
		total = read();
	}
	return 0;
}
