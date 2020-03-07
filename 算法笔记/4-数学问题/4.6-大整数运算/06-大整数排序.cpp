#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

大整数排序

对N个长度最长可达到1000的数进行排序。
输入第一行为一个整数N，(1<=N<=100)。
接下来的N行每行有一个数，数的长度范围为1<=len<=1000。
每个数都是一个正数，并且保证不包含前缀零。

输入：
4
123
1234
12345
2345
输出：
123
1234
2345
12345

*/


struct bign{
	int d[1000];
	int len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}	
}raw[100]; // raw数组存储bign类型的数据

bign change(char str[]) {
	bign a;
	a.len = strlen(str);
	for (int i = 0; i < a.len; i++) {
		a.d[i] = str[a.len - i- 1] - '0';
	}
	return a;
}

bool cmp(bign a, bign b) {
	if (a.len != b.len) {
		return a.len < b.len;
	}	
	for (int i = a.len - 1; i >= 0; i++) {
		if (a.d[i] != b.d[i]) return a.d[i] <b.d[i];
	}
}

void print(bign a) {
	for (int i = a.len - 1; i >= 0; i--) {
		printf("%d", a.d[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int m;
	char str[1000];
	while (scanf("%d", &m) != EOF) {
		for (int i = 0; i < m; i++) {
			scanf("%s", str);
			raw[i] = change(str);
		}
		sort(raw, raw+m, cmp);
		for (int i = 0; i < m; i++) {
			print(raw[i]);
		}
	}
}