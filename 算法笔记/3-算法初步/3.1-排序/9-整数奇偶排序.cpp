#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


/*

输入n代表用n个整数，彼此以空格分隔。重新排序以后输出(也按空格分隔)，要求:
1.先输出其中的奇数,并按从大到小排列；
2.然后输出其中的偶数,并按从小到大排列。

输入：
10
0 56 19 81 59 48 35 90 83 75 
10
17 86 71 51 30 1 9 36 14 16 
输出：
83 81 75 59 35 19 0 48 56 90
71 51 17 9 1 14 16 30 36 86

*/

const int maxn = 1010;

bool cmp (int a, int b) {
	return a > b;
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[maxn];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int odd[maxn], num_odd = 0; // 奇
		int even[maxn], num_even = 0; // 偶
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 != 0) {
				odd[num_odd++] = a[i];
			} else{
				even[num_even++] = a[i];
			}
		}
		sort(odd, odd+num_odd, cmp);
		sort(even, even+num_even);
		for (int i = 0; i < num_odd; i++) {
			printf("%d ", odd[i]);
		}
		for (int i = 0; i < num_even; i++) {
			printf("%d ", even[i]);
		}
		printf("\n");
	}
}