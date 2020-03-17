#include <iostream>
#include <cstdio>
using namespace std;

/*

A+B for Matrices（浙江大学）

*/
const int maxn = 12;

int main(int argc, char *argv[]) {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		int a[maxn][maxn], b[maxn][maxn];
		int c[maxn][maxn];
		// 输入
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &b[i][j]);
			}
		}
		// 计算A+B
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				c[i][j] = a[i][j] + b[i][j];
			}
		}
		// 遍历c，计算行列元素全为0的行列数目
		int count = 0;
		bool flag = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (c[i][j] != 0) { // 对每一行来说
					flag = false;
					break;
				}
			}
			if (flag == true) count++; 
			flag = true;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (c[j][i] != 0) { // 对每一列来说
					flag = false;
					break;
				}
			}
			if (flag == true) count++; 
			flag = true;
		}
		printf("%d\n", count);
	}
}