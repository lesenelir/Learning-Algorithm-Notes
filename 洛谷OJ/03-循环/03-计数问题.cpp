#include <cstdio>
#include <iostream>
using namespace std;

/*

试计算在区间 1 到 n的所有整数中数字x(0~9)总共出现了几次
输入：
11 1
输出：
4

*/
const int maxn = 10001;
int a[maxn], num = 0;

int main() {
	int n, x;
	while (scanf("%d %d", &n, &x) != EOF) {
		int count = 0;
		for (int i = 1; i <= n; i++) {
			int temp = i;
			while (temp != 0) {
				a[num++] = temp % 10;
				temp = temp / 10;
			}
		}	
		for (int i = 0; i < num; i++) {
			if (a[i] == x) {
				count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}