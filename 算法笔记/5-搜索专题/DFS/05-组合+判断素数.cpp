#include <iostream>
#include <cstdio>
using namespace std;

/*

组合+判断素数

已知 n 个整数b1,b2,…,bn

以及一个整数 k（k＜n）。

从 n 个整数中任选 k 个整数相加，可分别得到一系列的和。

例如当 n=4，k＝3，4 个整数分别为 3，7，12，19 时，可得全部的组合与它们的和为：
　　　　3＋7＋12=22　　3＋7＋19＝29　　7＋12＋19＝38　　3＋12＋19＝34。
　　现在，要求你计算出和为素数共有多少种。

例如上例，只有一种的和为素数：3＋7＋19＝29。

第一行两个整数：n , k （1<=n<=20，k＜n） 
第二行n个整数：x1,x2，…,xn （1<=xi<=5000000） 

输入：
4 3
3 7 12 19
输出：
1

*/

int n, k;
int P[22];
int cnt;

bool isPrime(int c) {
	if (c <= 1) return false;
	for (int i = 2; i * i <= c; i++) {
		if (c % i == 0) return false;
	}
	return true;
}

void DFS(int index, int nowK, int sum) {
	if (nowK == k) { // 递归边界
		if (isPrime(sum)) {
			cnt++;
		}
		return;
	}
	if (index == n || nowK > k) return; // 处理完n个数字 或者超过n个数字 则返回
	DFS(index + 1, nowK + 1, sum + P[index]); // 选当前数
	DFS(index + 1, nowK, sum); // 不选当前数
}


int main(int argc, char *argv[]) {
	cnt = 0;
	while (scanf("%d %d", &n, &k) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &P[i]);
		}
		DFS(0, 0, 0);
		printf("%d\n", cnt);
	}
}