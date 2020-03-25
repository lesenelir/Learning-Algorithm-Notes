#include <iostream>
#include <cstdio>
using namespace std;

/*

数组循环右移 P12

*/
const int maxn = 1010;
int A[maxn];
int B[maxn], num = 0; // 新的数组

int main(int argc, char *argv[]) {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
		m = m % n; // m > n时 移动的只是余数部分【关键步骤】
		for (int i = n - m; i < n; i++) { // 存入后面的元素
			B[num++] = A[i];
		}
		for (int i = 0; i < n - m; i++) { // 存入前面的元素
			B[num++] = A[i];
		}
		for (int i = 0; i < num; i++) {
			printf("%d", B[i]);
			if (i != num - 1) printf(" ");
		}
		printf("\n");
	}
}