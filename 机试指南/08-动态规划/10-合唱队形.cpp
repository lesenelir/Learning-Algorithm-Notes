#include <iostream>
#include <cstdio>
using namespace std;

/*

合唱队形（北京大学）P233

*/
const int maxn = 1010;
int A[maxn];
int dp1[maxn], dp2[maxn];

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
		// 边界
		for (int i = 0; i < n; i++) {
			dp1[i] = 1;
			dp2[i] = 1;
		}
		// 正序上升序列
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (A[j] < A[i] && dp1[j] + 1 > dp1[i]) {
					dp1[i] = dp1[j] + 1;
				}
			}
		}
		// 逆序上升序列
		for (int i = n-1; i>= 0; i--) {
			for (int j = n-1; j > i; j--) {
				if (A[j] < A[i] && dp2[j] + 1 > dp2[i]) {
					dp2[i] = dp2[j] + 1;
				}
			}
		}
		// 找最大值
		int res = 0;
		for (int i = 0; i < n; i++) {
			res = max(res, dp1[i] + dp2[i] - 1);
		}
		printf("%d\n", n-res);
	}
}