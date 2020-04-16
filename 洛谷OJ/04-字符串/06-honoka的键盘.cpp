#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 101;
char str[maxn];

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		scanf("%s", str);
		int count = 0;
		// 从头到尾跑一遍，把正确的VK都改为X
		for (int i = 0; i < n; i++) {
			if (str[i] == 'V' && str[i+1] == 'K') { 
				count++;
				str[i] = 'X';
				str[i+1] = 'X';
			}
		}
		// 再跑一遍找到一个KK 或 VV 就停止。因为只能修改一次
		for (int i = 0; i < n; i++) {
			if (str[i] != 'X' && str[i] == str[i+1]) {
				count++;
				break;
			}
		}
		printf("%d\n", count);
	}
	
	return 0;
}