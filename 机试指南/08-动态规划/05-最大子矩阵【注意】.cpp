#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/*

最大子矩阵（北京大学）P227

*/
const int maxn = 1010;
int a[maxn][maxn];

int LSM(int A[], int n) { // 一维最大连续子序列和
	int dp[100];
	// 边界
	dp[0] = A[0];
	// 状态转移方程
	for (int i = 1; i < n; i++) {
		dp[i] = max(A[i], dp[i-1] + A[i]);
	}
	// 找最大
	int k = 0;
	for (int i = 1; i < n; i++) {
		if (dp[i] > dp[k]) {
			k = i;
		}
	}
	return dp[k];
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		int temp[101];
		int res = -1;
		for (int i = 0; i < n; i++) { // i从第0行开始
			//数组temp表示i~j行，对应列元素的和，把i行到j行的同一列元素相加保存在temp中
			memset(temp, 0, sizeof(temp));
			for (int j = i; j < n; j++) { // j计算在i以下的行所有列元素相加，j在此充当行
				for (int k = 0; k < n; k++) { // 遍历每列相加元素
					temp[k] = temp[k] + a[j][k];
				}
				res = max(res, LSM(temp, n));
			}
		}
		printf("%d\n", res);
	}
}