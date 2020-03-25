#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

A1046 Shortest Distance P20

*/
const int maxn = 1010;
int A[maxn];

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &A[i]);
			sum = sum + A[i]; // 计算一圈的值
		}
		int m, left, right;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int dist = 0; // 计算顺时针时候的路径
			scanf("%d %d", &left, &right); 
			if (left > right) swap(left, right); // 编号保证left小于right
			while (left < right) dist = dist + A[left++];
			printf("%d\n", min(dist, sum - dist));
		}
	}
}