#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

PAT B1019 数字黑洞

给定一个四位数字 各位数先按照非递增排序，再按非递减排序，然后用第一个数字减去第二个数字，得到一个新的数字。
再把新的数字按照如此进行重复得到最终会得到一个数字6174

输入：
6767
输出：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8352 - 2358 = 6174

输入：
2222
输出：
2222 - 2222 = 0

备注：
数字转换成数组就是拆分 拆解
把数组转换成数字 一定要牢记的步骤：sum = sum * 10 + a[i]

*/


const int maxn = 1010;

bool cmp (int a, int b) {
	return a > b;
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		while (true) {
			int max = 0, min = 0;
			int a[maxn], num = 0;
			
			for (int i = 0; i < 4; i++) { // 把数字n转换成数组
				a[num++] = n % 10; // 数字从个位存入数组低位
				n = n / 10;
			}
			
			sort(a, a + 4, cmp); // 非递增
			for (int i = 0; i < 4; i++) { // 把数组转换成数字，此时0开始的是最大数字
				max = max * 10 + a[i]; // [关键步骤]
			}
			
			sort(a, a + 4); // 非递增排序
			for (int i = 0; i < 4; i++) {
				min = min * 10 + a[i];
			}
			
			n = max - min;
			printf("%04d - %04d = %04d\n", max, min, n);
			if (n == 0 || n == 6174) break;
		}	
	}
}