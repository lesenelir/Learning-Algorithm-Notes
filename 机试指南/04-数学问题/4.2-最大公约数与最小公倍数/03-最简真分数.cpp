#include <iostream>
#include <cstdio>
using namespace std;

/*

最简真分数(北京大学)给出n个正整数，任取两个数分别作为分子和分母组成最简真分数，编程求共有几个这样的组合。

*/

int GCD(int a, int b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[1010];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int count = 0;
		for (int i = 0; i < n; i++) { // 分母
			for (int j = 0; j < n; j++) { // 分子
				if (a[i] > a[j] && GCD(a[i], a[j]) == 1) count++; // 最大公约数为1代表互质
			}
		}
		printf("%d\n", count);
	}
}