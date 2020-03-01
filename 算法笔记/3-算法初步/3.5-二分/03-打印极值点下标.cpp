#include <iostream>
#include <cstdio>
using namespace std;

/*

在一个整数数组上，对于下标为i的整数，如果它大于所有它相邻的整数，或者小于所有它相邻的整数，则称为该整数为一个极值点，极值点的下标就是i。

有2×n+1行输入：第一行是要处理的数组的个数n；
对其余2×n行，第一行是此数组的元素个数k(4<k<80)，第二行是k个整数，每两个整数之间用空格分隔。

每个案例输出不多于n行：每行对应于相应数组的所有极值点下标值，下标值之间用空格分隔，如果没有极值点则不输出任何东西。

输入：
2
4
1 2 1 3
5
3 4 5 6 7
输出：
0 1 2 3
0 4

思路：
分开分析，边界和中间部分。对于中间部分，我们只要判断这个数字两个的数字分别和它做差，只要差相乘为负数，说明这就是极值点。

*/

const int maxn = 1010;


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		while (n--) {
			int k;
			scanf("%d", &k);
			int a[maxn];
			for (int i = 0; i < k; i++) {
				scanf("%d", &a[i]);
			}
			if (a[0] != a[1]) printf("0 "); // 边界
			
			// 处理中间部分
			for (int i = 1; i < k-1; i++) {
				int c = a[i+1] - a[i];
				int d = a[i] - a[i-1];
				if (c * d < 0) {
					printf("%d ", i);
				}
			}
			
			if (a[k-2] != a[k-1]) printf("%d\n", k-1); // 边界
			else printf("\n"); // 不做处理则换行
		}
	}
}